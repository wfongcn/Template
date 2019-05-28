#include <LibMgr.hpp>
#include <MyLibBase.hpp>
#include <dlfcn.h>
using namespace std;

LibMgr::LibMgr()
{
}

LibMgr::~LibMgr()
{
  for (auto p : mMyLibPtrs)
  {
    destroy_t* destroy = (destroy_t*)dlsym(p.second.first, "destroy");
    char *error;
    if ((error = dlerror()) == NULL)
    {
      (*destroy)(p.second.second);
    }

    dlclose(p.second.first);
  }
}

bool LibMgr::load(const string& libpath)
{
  if (mMyLibPtrs.find(libpath) != mMyLibPtrs.end()) return true;

  void *lib_handle = dlopen(libpath.c_str(), RTLD_LAZY);
  if (!lib_handle)
  {
    fprintf(stderr, "%s\n", dlerror());
    return false;
  }

  create_t* create = (create_t*)dlsym(lib_handle, "create");
  char *error;
  if ((error = dlerror()) != NULL)
  {
    fprintf(stderr, "%s\n", error);
    dlclose(lib_handle);
    return false;
  }
  MyLibBase* pMyLib = (*create)();
  mMyLibPtrs[libpath] = pair<void*, MyLibBase*>(lib_handle, pMyLib);

  return true;
}

MyLibBase* LibMgr::get(const string& libpath)
{
  if (mMyLibPtrs.find(libpath) != mMyLibPtrs.end())
  {
    return mMyLibPtrs[libpath].second;
  }
  else
  {
    return nullptr;
  }
}

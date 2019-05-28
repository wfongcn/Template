#pragma once
#include <map>
#include <string>
#include <vector>

class MyLibBase;
class LibMgr
{
public:
  LibMgr();
  ~LibMgr();
  bool load(const std::string& libpath);
  MyLibBase* get(const std::string& libpath);

private:
  // key:path, value:lib handle,obj pointer
  std::map<std::string, std::pair<void*, MyLibBase*> > mMyLibPtrs;
};

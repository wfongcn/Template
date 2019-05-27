#include <MyLib.hpp>

using namespace std;

// ---- MUST HAVE BEGIN ----
MyLibBase::MyLibBase()
{
}

MyLibBase::~MyLibBase()
{
}

extern "C" MyLibBase* create()
{
  return new MyLib();
}

extern "C" void destroy(MyLibBase* p)
{
  delete p;
}
// ---- MUST HAVE END ----

MyLib::MyLib()
{
}

MyLib::~MyLib()
{
}

void MyLib::doSomething()
{
  // TODO ...
}

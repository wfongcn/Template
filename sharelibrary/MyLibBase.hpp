#pragma once

// 1. Library must inherit the MyLibBase class.
// 2. Library must implement the MyLibBase class's constructor/destructor.
// 3. Library must implement a create and destroy C function as blow.
//
//    extern "C" MyLibBase* create()
//    {
//      return new SubClass();
//    }
//
//    extern "C" void destroy(MyLibBase* p)
//    {
//      delete p;
//    }
// 3. Library must implement the doSomething function.
class MyLibBase
{
public:
  MyLibBase();
  virtual ~MyLibBase();

  virtual void doSomething() = 0;
};

typedef MyLibBase* create_t();
typedef void destroy_t(MyLibBase*);

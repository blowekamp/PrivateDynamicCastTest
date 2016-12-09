#include "create.h"
#include "derived.h"
#include <iostream>

base* create(void)
{
  std::cout << "create typeid: " << (void*)(&typeid(derived)) << std::endl;
  return new derived();
}


base* createI(void)
{
  return new derivedI<0>();
}

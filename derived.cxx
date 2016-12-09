#include "derived.h"
#include <iostream>

derived::~derived()
{
  std::cout << "~derived typeid: " << (void*)(&typeid(*this)) << std::endl;
}

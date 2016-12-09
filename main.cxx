#include "create.h"
#include "derived.h"
#include <iostream>

int main(void)
{
  std::cout << "main typeid: " << (void*)(&typeid(derived)) << std::endl;

  base *obj = create();

  if (dynamic_cast<derived*>(obj)== NULL)
    {
    std::cout << "dynamic_cast for \'derived\' failed!" << std::endl;
    return 1;
    }
  else
    {
    std::cout << "dynamic_cast for \'derived\' succeeded!" << std::endl;
    delete obj;
    return 0;
    }
}

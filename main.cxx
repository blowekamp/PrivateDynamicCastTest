#include "create.h"
#include "derived.h"
#include <iostream>

int main(void)
{
  std::cout << "main typeid: " << (void*)(&typeid(derived)) << std::endl;

  base *obj = create();

  int fail = 0;

  if (dynamic_cast<derived*>(obj)== NULL)
    {
    std::cout << "dynamic_cast for \'derived\' failed!" << std::endl;
    ++fail;
    }
  else
    {
    std::cout << "dynamic_cast for \'derived\' succeeded!" << std::endl;
    delete obj;
    }

  obj = createI();

  if (dynamic_cast<derivedI<0>*>(obj)== NULL)
    {
    std::cout << "dynamic_cast for \'derivedI\' failed!" << std::endl;
    ++fail;
    }
  else
    {
    std::cout << "dynamic_cast for \'derivedI\' succeeded!" << std::endl;
    delete obj;
    }
  return fail;
}

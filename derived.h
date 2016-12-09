#include "base.h"

struct derived
  : public base
{
  virtual ~derived();
};

template <int I = 0>
struct derivedI
  :public base
{
  virtual ~derivedI() {};
};

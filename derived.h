#ifndef DERIVED_H
#define DERIVED_H

#include "base.h"

struct derived
  : public base
{
  virtual ~derived();
};

template <int I>
struct derivedI
  :public base
{
  virtual ~derivedI() = default;
};

#endif

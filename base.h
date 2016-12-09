#ifndef BASE_H
#define BASE_H


struct
#ifdef BASE_DEFAULT_VISIBILITY
__attribute__ ((visibility ("default")))
#endif
base
{
  virtual ~base() = 0;
};

#endif


# Test case for C++ `dynamic_cast`ing of duplicate hidden symbols

When C++ type's RTTI cannot be resolved to a unique symbol across a
process failues related to dynamic_cast can occur. Specifically and
currently, GCC is resilient to duplicate RTTI of a type, while OSX's
clang with libc++ fails with duplicate symbols.

This test project demonstrates failing cases for dynamic_cast on the
OSX platform.

The test case has a library which implements a factory method
"create", which returns a constructed "deceived" class as a "base"
class pointer. This resulting object this then dynamically casted to
the derived class in the main executable.

This project has a CMake option "BASE_DEFAULT_VISIBILITY" to control
the visibility of the "base" class.

On a vanilla Linux system with GNU GCC and libstdc++ the test always
passes.

On OSX the behavior is more interesting:

- If "base" and "derived" have hidden visibility. Duplicate type RTTI
  will be in both the executable and the shared library. The
  dynamic_cast success but a message is logged into the system.log:
  "dynamic_cast error 2: One or more of the following type_info's  has
  hidden visibility.  They should all have public visibility.   4base,
  8derivedIILi0EE, 8derivedIILi0EE."

- If "base" is default but "derived" is hidden. There is a single type
  RTTI for "base" but multiple for "derived". The dynamic_cast will
  directly fail and return NULL. 


See also:
  - https://lists.freedesktop.org/archives/libreoffice-commits/2015-January/091572.html
  - http://www.russellmcc.com/posts/2013-08-03-rtti.html
  - https://gcc.gnu.org/ml/gcc-patches/2009-07/msg01239.html

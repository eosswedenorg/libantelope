#ifndef LIBANTELOPE_TESTING_H
#define LIBANTELOPE_TESTING_H

#include <doctest.h>

#define CHECK_PRED(a,b,pred) if (pred) { CHECK_EQ((a), (b)); } else { CHECK_NE((a), (b)); }

#endif /* LIBANTELOPE_TESTING_H */
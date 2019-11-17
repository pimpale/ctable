#include <stdlib.h>
#include <stdio.h>

#define FATAL(x)                                                               \
  do {                                                                         \
    fprintf(stderr, x);                                                        \
    exit(EXIT_FAILURE);                                                        \
  } while (0)

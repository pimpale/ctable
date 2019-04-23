#include <stdint.h>
#include <stdlib.h>

#include "hash.h"

uint64_t simpleHash(uint64_t seed, void *data, size_t datalen){
  uint64_t hash = 0;
  uint8_t* bytes = data;
  for (size_t i = 0; i < datalen; i++){
    //sdbm hashing algorithm
    hash = bytes[i] + (hash << 6) + (hash << 16) - hash + seed;
  }
  return (hash);
}

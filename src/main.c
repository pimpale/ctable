#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

int main() {
  Table t;
  initTable(&t);

  for (int i = 300; i < 500; i++) {
    char value[400];
    snprintf(value, 400, "hello%d", i);
    size_t valuelen = strlen(value) + 1;
    int* key = &i;
    size_t keylen = sizeof(i);
    putTable(&t, key, keylen, value, valuelen);
  }

  for (int i = 300; i < 500; i++) {
    // First query size
    int* key = &i;
    size_t keylen = sizeof(i);
    size_t valuelen = getValueLengthTable(&t, &key, keylen);
    char* value = malloc(valuelen);
    getTable(&t, key, keylen, value, valuelen);
  }
  freeTable(&t);
}


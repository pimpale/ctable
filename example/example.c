#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "table.h"

int main() {
  Table t;
  initTable(&t);

  for (int i = 300; i < 600; i++) {
    char key[400];
    snprintf(key, 400, "qwertyuiop%d", i);
    size_t keylen = strlen(key) + 1;
    char value[400];
    snprintf(value, 400, "asdfghjkl%d", i);
    size_t valuelen = strlen(value) + 1;
    printf("attempting to insert key value pair %s : %s\n", key, value);
    putTable(&t, key, keylen, value, valuelen);
  }

  for (int i = 500; i < 600; i++) {
    char key[400];
    snprintf(key, 400, "qwertyuiop%d", i);
    size_t keylen = strlen(key) + 1;
    printf("attempting to delete key %s\n", key);
    delTable(&t, key, keylen);
  }

  puts("ok");

  for (int i = 300; i < 500; i++) {
    // Determine key
    char key[400];
    snprintf(key, 400, "qwertyuiop%d", i);
    size_t keylen = strlen(key) + 1;
    printf("attempting to retrieve value at key: %s\n", key);

    // First query size
    size_t valuelen = getValueLengthTable(&t, &key, keylen);
    char* value = malloc(valuelen);
    getTable(&t, key, keylen, value, valuelen);
    printf("retrieved key value pair %s : %s\n", key, value);
  }
  freeTable(&t);
}


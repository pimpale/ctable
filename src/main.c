#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

int main() {
  Table t;
  initTable(&t);

  for (int i = 300; i < 500; i++) {
    char key[400];
    snprintf(key, 400, "qwertyuiop%d", i);
    size_t keylen = strlen(key) + 1;
    char value[400];
    snprintf(value, 400, "asdfghjkl%d", i);
    size_t valuelen = strlen(value) + 1;
    printf("attempting to insert key value pair %s : %s\n", key, value);
    putTable(&t, key, keylen, value, valuelen);
  }

  /*
  for (int i = 300; i < 500; i++) {
    // First query size
    int* key = &i;
    size_t keylen = sizeof(i);
    size_t valuelen = getValueLengthTable(&t, &key, keylen);
    char* value = malloc(valuelen);
    getTable(&t, key, keylen, value, valuelen);
  }
  */
  //freeTable(&t);
}


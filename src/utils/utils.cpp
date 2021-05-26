#include <Arduino.h>
#include "utils/utils.h"

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void randomArray(int* a, int n) {
  for (int i = 0; i < n; i++) {
    a[i] = random(50);
  }
}
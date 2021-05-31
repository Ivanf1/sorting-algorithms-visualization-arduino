#include "utils/utils.h"

#include <Arduino.h>

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

void printArray(int* a, int n) { 
  for (int i = 0; i < n; i++) {
    Serial.print(a[i]);
    Serial.print(" ");
  }
  Serial.println();
}
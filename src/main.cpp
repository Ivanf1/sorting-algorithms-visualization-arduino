#include <Arduino.h>
#include <ShiftRegister74HC595.h>

#include "utils/utils.h"

#define DATA_PIN 2
#define CLOCK_PIN 3
#define LATCH_PIN 4

ShiftRegister74HC595<2> sr(DATA_PIN, CLOCK_PIN, LATCH_PIN);

int arr[] = {1,4,2,7,5,8,9,0};

void bubbleSort(int* a, int n) {
  int i, j;

  for (i = 1; i < n; i++) {
    for (j = 0; j < n - i; j++) {
      delay(300);
      sr.setNoUpdate(j*2+1, 1);
      sr.setNoUpdate(j*2+3, 1);
      sr.updateRegisters();
      delay(300);

      if (a[j] > a[j+1]) {
        swap(&a[j], &a[j+1]);
      }

      sr.setNoUpdate(j*2+1, 0);
      sr.setNoUpdate(j*2+3, 0);
      sr.updateRegisters();
      delay(300);
    }
    sr.set(n*2 - (i*2), 1);
  }
  sr.set(0, 1);
}

void setup() {
  sr.setAllLow();

  bubbleSort(arr, 8);
}

void loop() {}

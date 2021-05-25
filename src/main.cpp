#include <Arduino.h>
#include <FastLED.h>

#include "utils/utils.h"

#define LED_D1 2
#define NUM_LEDS 12

#define YELLOW CRGB(0xeaf70c)
#define GREEN CRGB(0xf70c23)
#define RED CRGB(0x44f70c)
#define BLUE CRGB(0x0c30f7)

#define DELAY_BY 500

CRGB leds[NUM_LEDS];

int arr[] = {1,4,2,7,5,8,9,0,13,45,11,3};

void bubbleSort(int* a, int n) {
  int i, j;

  for (i = 1; i < n; i++) {
    for (j = 0; j < n - i; j++) {
      delay(DELAY_BY);
      leds[j] = YELLOW;
      leds[j+1] = YELLOW;
      FastLED.show();
      delay(DELAY_BY);

      if (a[j] > a[j+1]) {
        leds[j] = BLUE;
        leds[j+1] = BLUE;
        FastLED.show();
        swap(&a[j], &a[j+1]);
        delay(DELAY_BY);
      }

      leds[j] = RED;
      leds[j+1] = RED;
      FastLED.show();
      delay(DELAY_BY);
    }

    leds[n-i] = GREEN;
    FastLED.show();
    delay(DELAY_BY);
  }
  leds[0] = GREEN;
  FastLED.show();
}

int minInArray(int* array, int n) {
  int i, min = 0;
  for (i = 1; i < n; i++) {
    // sr.set(i*2+1, 1);
    if (array[min] > array[i]) {
      min = i;
    }
    // sr.set(i*2+1, 0);
  }
  return min;
}

void selectionSort(int* a, int n) {
  int i, min;
  for (i = 0; i < n-1; i++) {
    min = minInArray(a+i, n-i) + i;
    swap(a+i, a+min);
    // sr.set(i*2, 1);
    delay(700);
  }
  // sr.set(14, 1);
}

void setup() {
  FastLED.addLeds<WS2812B, LED_D1>(leds, NUM_LEDS);
  FastLED.setBrightness(30);
  FastLED.clear(true);

  bubbleSort(arr, 12);

  // for (int i = 0; i < 12; i++) {
  //   leds[i] = CRGB(RED);
  //   FastLED.show();
  //   delay(500);
  // }
  // selectionSort(arr, 12);
}

void loop() {}

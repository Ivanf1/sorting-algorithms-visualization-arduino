#include <Arduino.h>
#include <FastLED.h>

#include "utils/utils.h"
#include "shared/colors.h"

#define LED_D1 2
#define NUM_LEDS 12

#define DELAY_BY 600

CRGB leds[NUM_LEDS];

int arr[NUM_LEDS] = {6,5,3,1,8,7,2,4,10,11,12,13};

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
  leds[NUM_LEDS-n] = BLUE;
  FastLED.show();
  delay(DELAY_BY);

  for (i = 1; i < n; i++) {
    leds[NUM_LEDS-n+i] = YELLOW;
    FastLED.show();
    delay(DELAY_BY);

    if (array[min] > array[i]) {
      leds[NUM_LEDS-n+min] = NO_COLOR;
      min = i;
      leds[NUM_LEDS-n+i] = BLUE;
      FastLED.show();
      delay(DELAY_BY);
    }

    if (leds[NUM_LEDS-n+i] == YELLOW) {
      leds[NUM_LEDS-n+i] = NO_COLOR;
    }
    FastLED.show();
    delay(DELAY_BY);
  }

  leds[NUM_LEDS-n+min] = NO_COLOR;
  FastLED.show();
  return min;
}

void selectionSort(int* a, int n) {
  int i, min;
  for (i = 0; i < n-1; i++) {
    min = minInArray(a+i, n-i) + i;
    swap(a+i, a+min);
    leds[i] = GREEN;
    FastLED.show();
    delay(DELAY_BY);
  }
  leds[n-1] = GREEN;
  FastLED.show();
}

void setup() {
  FastLED.addLeds<WS2812B, LED_D1>(leds, NUM_LEDS);
  FastLED.setBrightness(80);
  FastLED.clear(true);

  randomArray(arr, NUM_LEDS);

  bubbleSort(arr, NUM_LEDS);
  delay(4000);
  FastLED.clear(true);

  randomArray(arr, NUM_LEDS);

  selectionSort(arr, NUM_LEDS);
  delay(4000);

  FastLED.clear(true);
}

void loop() {}

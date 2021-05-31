#include <Arduino.h>
#include <FastLED.h>

#include "utils/utils.h"
#include "shared/colors.h"

#define LED_D1 2
#define NUM_LEDS 12

#define DELAY_BY 600

CRGB leds[NUM_LEDS];

int arr[NUM_LEDS] = {10,6,11,5,3,1,8,7,2,12,4,9};

void shakerSort(int* a, int n) {
  int start = 0;
  int end = n-1;
  bool swapped;

  do {
    swapped = false;
    for (int i = start; i < end; i++) {
      delay(DELAY_BY);
      leds[i] = YELLOW;
      leds[i+1] = YELLOW;
      FastLED.show();

      if (a[i] > a[i+1]) {
        delay(DELAY_BY);
        leds[i] = BLUE;
        leds[i+1] = BLUE;
        FastLED.show();
        delay(DELAY_BY);

        swap(&a[i], &a[i+1]);
        swapped = true;
      }

      leds[i] = NO_COLOR;
      leds[i+1] = NO_COLOR;
    }

    delay(DELAY_BY);
    leds[end] = GREEN;
    FastLED.show();

    if (!swapped) break;
    swapped = false;
    end--;

    for (int i = end; i > start; i--) {
      delay(DELAY_BY);
      leds[i] = YELLOW;
      leds[i-1] = YELLOW;
      FastLED.show();

      if (a[i] < a[i-1]) {
        delay(DELAY_BY);
        leds[i] = BLUE;
        leds[i-1] = BLUE;
        FastLED.show();
        delay(DELAY_BY);

        swap(&a[i], &a[i-1]);
        swapped = true;
      }

      leds[i] = NO_COLOR;
      leds[i-1] = NO_COLOR;
    }

    delay(DELAY_BY);
    leds[start] = GREEN;
    FastLED.show();

    start++;

    printArray(a, n);
  } while (swapped);

  // turn green remaining elements in correct position
  for (int i = start; i <= end; i++) {
    leds[i] = GREEN;
  }
  FastLED.show();
}

void setup() {
  FastLED.addLeds<WS2812B, LED_D1>(leds, NUM_LEDS);
  FastLED.setBrightness(80);
  FastLED.clear(true);

  shakerSort(arr, NUM_LEDS);

  delay(15000);
  FastLED.clear(true);
}

void loop() {}

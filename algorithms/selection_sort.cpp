#include <Arduino.h>
#include <FastLED.h>

#include "utils/utils.h"
#include "shared/colors.h"

#define LED_DI 2
#define NUM_LEDS 12

#define DELAY_BY 600

CRGB leds[NUM_LEDS];

/**
 * Array from the graphical example on the wikipedia page for these algorithms
 * with the addition of the last 4 numbers to use all the LEDs (numbers added
 * already in order so they don't influence the animation)
 */
int arr[NUM_LEDS] = {6,5,3,1,8,7,2,4,10,11,12,13};

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
  FastLED.addLeds<WS2812B, LED_DI>(leds, NUM_LEDS);
  FastLED.setBrightness(80);
  FastLED.clear(true);

  selectionSort(arr, NUM_LEDS);

  delay(15000);
  FastLED.clear(true);
}

void loop() {}
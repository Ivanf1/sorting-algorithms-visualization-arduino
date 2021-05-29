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

void insertionSort(int* a, int n) {
  int key, j;
  leds[NUM_LEDS-n] = BLUE;
  FastLED.show();
  delay(DELAY_BY);

  leds[NUM_LEDS-n] = YELLOW;
  FastLED.show();
  delay(DELAY_BY);

  for (int i = 1; i < n; i++) {
    leds[i] = BLUE;
    FastLED.show();
    delay(DELAY_BY);

    key = a[i];
    j = i-1;

    while (j >= 0 && a[j] > key) {
      a[j+1] = a[j];

      leds[j+1] = YELLOW;
      leds[j] = BLUE;
      FastLED.show();
      delay(DELAY_BY);
      
      j--;
    }
    leds[j+1] = YELLOW;
    FastLED.show();
    delay(DELAY_BY);
    a[j+1] = key;

    leds[i] = YELLOW;
    FastLED.show();
    delay(DELAY_BY);
  }
  FastLED.showColor(GREEN);
}

void setup() {
  FastLED.addLeds<WS2812B, LED_DI>(leds, NUM_LEDS);
  FastLED.setBrightness(80);
  FastLED.clear(true);

  insertionSort(arr, NUM_LEDS);

  delay(15000);
  FastLED.clear(true);
}

void loop() {}
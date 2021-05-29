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

void setup() {
  FastLED.addLeds<WS2812B, LED_DI>(leds, NUM_LEDS);
  FastLED.setBrightness(80);
  FastLED.clear(true);

  bubbleSort(arr, NUM_LEDS);

  delay(15000);
  FastLED.clear(true);
}

void loop() {}
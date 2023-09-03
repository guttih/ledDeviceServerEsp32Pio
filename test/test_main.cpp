#include "arduino.h"
#include <unity.h>
#include "test_functions.h"


 #include "StripOrri.h"
    const char* deviceId = "63f1253530dc6b0533d3659a"; /*Orri device*/
    const char* hostName = "orri_sign"; /*max hostname 15 characters*/
    #define NUM_LEDS 300
    #define STRIP_TYPE APA102
    #define COLOR_SCHEME BGR 
    #define CLOCK_PIN 16  
    #define DATA_PIN  17 
CRGB leds[NUM_LEDS];

void testBase() {
    header("Testing Base");
}

void test_brightness() {
    StripOrri stripper; 
    FastLED.addLeds<STRIP_TYPE, DATA_PIN, CLOCK_PIN, COLOR_SCHEME>(leds, NUM_LEDS);
    stripper.initialize(&FastLED);
    stripper.setBrightness(4);
    TEST_ASSERT_EQUAL(stripper.getBrightness(), 4);
    // int a=3;
    // TEST_ASSERT_EQUAL(a,3);
}

int runUnityTests(void) {
  UNITY_BEGIN();
    RUN_TEST(testBase);
  return UNITY_END();
}

// int main(void){
//     return runUnityTests();
// }

void setup() {
     // Wait ~2 seconds before the Unity test runner
  // establishes connection with a board Serial interface
    delay(2000);
    
    Serial.begin(115200);
    header("Verbose printing tests");

     UNITY_BEGIN();
    RUN_TEST(test_brightness);
    UNITY_END();
}

void loop() {}

// void app_main() {
//   runUnityTests();
// }
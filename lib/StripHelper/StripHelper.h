#ifndef _StripHelper_h
#define _StripHelper_h

#include <WiFi.h>
#include <HTTPClient.h>


#define FASTLED_INTERNAL
#include <FastLED.h>

// #define WS2811_RGB_DATA_PIN13
// #define CHRISTMAS_SOUTH
// #define SOLEY_IN /*apa*/ 
#define ORRI_IN /*apa*/ 
// #define KITCHEN_ISLAND /*apa*/
// #define KITCHEN_ISLAND

#define COLOR_COUNT 6

enum STRIP_PROGRAMS {
    OFF,
    RESET,
    SINGLE_COLOR,
    MULTI_COLOR,
    FIRE,
    DOWN,
    UP_DOWN,
    STARS,
    RAINBOW,
    CYLON,
    SECTIONS,

#ifdef SOLEY_IN    
    SOLEY,
#elif defined (ORRI_IN)
    ORRI,
#endif
    /*add next type above this line*/
    STRIP_PROGRAMS_COUNT
};


/*
You must call initialize before you do any actions on the stripColors

Example: ----
#define CLOCK_PIN    13  
#define DATA_PIN     14  
#define NUM_LEDS     150 
#define STRIP_TYPE   APA102
#define COLOR_SCHEME BGR
CRGB leds[NUM_LEDS];
StripHelper stripper;

void stripInit(){
    FastLED.addLeds<STRIP_TYPE, DATA_PIN, CLOCK_PIN, COLOR_SCHEME>(leds, NUM_LEDS);
    stripper.initialize(&FastLED);
}

Example: ----
*/
struct ProgramValueInfo {
    String variableDescriptionArray;
    int colors;
};

class StripHelper {
    protected:
        CRGBPalette16 mPal;
        int ledCount;
        void init();
        bool fixStep();
        int direction,
            step,
            turns;
        uint8_t brightness;
        CRGB stripColors[COLOR_COUNT];
        unsigned long stepDelay;
        STRIP_PROGRAMS program;
        CFastLED *fastLED;
        struct CRGB * leds;
        unsigned long lightLastTime;
        unsigned int *tempArray;
        uint8_t byteWorker1= 0;
        unsigned long ulWorker1;
        int iWorker1;
        unsigned long value1;
        unsigned long value2;
        unsigned long value3;
        unsigned long value4;
    
        void fillByIndex(int startIndex, int endIndex, const struct CRGB& color);
        void reset();
        
        
        int getLast();
        int getStep(); 
        unsigned long getStepDelay();
        int getTurns();
        
        bool setStep(int step);
        int stepUp();
        int stepDown();
        int getDirection();
        int setDirection(bool forward);
        void toggleDirection();
        String ulToString(uint32_t number);
        String appendSpacesToGetMinLength(String str, int minLength);
        CRGB fadeTowardColor( CRGB& cur, const CRGB& target, uint8_t amount);
        void nblendU8TowardU8( uint8_t& cur, const uint8_t target, uint8_t amount);
                
        void programCylonFadeall();
        void programCylon();
        void programSections();
        void programStepOne(CRGB onColor, CRGB trailColor);
        void programUpDown();
        void programSingleColor();
        void programMultiColor();
        void programStars();
        void programStarsInit();
        void programStarsSelectNewStars();
        void programRainbow();
        void programFireInit();
        void programFire();

    protected:
        String quotes(String value);
        String MakeJsonKeyVal(String key, String Value);

    public:
        
        StripHelper();
        void initialize(CFastLED *controller);
        CFastLED* getController();
        STRIP_PROGRAMS getProgram();
        int getCount();
        uint8_t getBrightness();
        void setBrightness(uint8_t brightness);
        String getAllProgramNames();
        String getAllProgramNamesAsJsonArray();
        String getProgramInfoAsJsonArray(STRIP_PROGRAMS stripProgram);
        String getAllProgramInfosAsJsonArray();
        String toJson();        
        CRGB decodeColor(uint32_t uiColor);
        uint32_t encodeColor(CRGB color);
        CRGB getColorBank(uint8_t index);
        bool setColorBank(uint8_t index, CRGB newColor);
        void setNewValues(STRIP_PROGRAMS program, unsigned long stepDelay, unsigned long value1, unsigned long value2, unsigned long value3, unsigned long value4);
        void programOff();
        void run();
        virtual void initProgram(STRIP_PROGRAMS programToSet);
        virtual void runProgram(STRIP_PROGRAMS stripProgram);
        virtual String getProgramName(STRIP_PROGRAMS stripProgram);
        virtual String getProgramDescription(STRIP_PROGRAMS stripProgram);
        virtual ProgramValueInfo getProgramValuesAsJsonArray(STRIP_PROGRAMS stripProgram);
};



#endif
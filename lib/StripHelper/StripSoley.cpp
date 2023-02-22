#include "StripSoley.h"

#ifdef SOLEY_IN

StripSoley::StripSoley()
{
    StripHelper();
}

StripSoley::~StripSoley()
{

}

String StripSoley::getProgramName(STRIP_PROGRAMS stripProgram) {

    switch(stripProgram){
        case SOLEY : return "SOLEY";
        default   : return StripHelper::getProgramName(stripProgram);
    }
}

String StripSoley::getProgramDescription(STRIP_PROGRAMS stripProgram) {

    switch(stripProgram){
        case SOLEY: return "Color 0 will be set to underline.  Color 1 will be set to S.  Color 2 will be set to O.  Color 3 will be set to L.  Color 4 will be set to E.  Color 5 will be set to Y.";
        default   : return StripHelper::getProgramDescription(stripProgram);
    }
    
}

ProgramValueInfo StripSoley::getProgramValuesAsJsonArray(STRIP_PROGRAMS stripProgram)
{   
    switch (stripProgram)
    {
        case SOLEY : return ProgramValueInfo{"[]", COLOR_COUNT };                                 
        default    : return StripHelper::getProgramValuesAsJsonArray(stripProgram);
    }
}

void StripSoley::runProgram(STRIP_PROGRAMS stripProgram)
{
    switch (stripProgram)
    {
        case SOLEY : programSoley(); break;
        default    : StripHelper::runProgram(stripProgram);
    }
}

//steps one pixel at a time and changes the the pixels aftier
void StripSoley::initProgram(STRIP_PROGRAMS programToSet) {
    switch(programToSet) {
        case SOLEY : setDirection(true); break;
        default    : StripHelper::initProgram(programToSet);
    }
}

void StripSoley::programSoley() {
        
        stepUp();
		fillByIndex(126, 128, getColorBank(0)); // 0 = underLine 
        fillByIndex(  0,  14, getColorBank(0)); // 0 = underLine 
        fillByIndex( 15,  44, getColorBank(1)); // 1 = letterS   
        fillByIndex( 45,  72, getColorBank(2)); // 2 = letterO  
        fillByIndex( 73,  85, getColorBank(3)); // 3 = letterL  
        fillByIndex( 86, 104, getColorBank(4)); // 4 = letterE  
        fillByIndex(105, 125, getColorBank(5)); // 5 = letterY  
		fastLED->show();
}

#endif
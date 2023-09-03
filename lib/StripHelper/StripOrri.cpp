
#include "StripOrri.h"

#ifdef ORRI_IN
StripOrri::StripOrri()
{
    StripHelper();
}

StripOrri::~StripOrri()
{

}

String StripOrri::getProgramName(STRIP_PROGRAMS stripProgram) {

    switch(stripProgram){
        case ORRI : return "ORRI";
        default   : return StripHelper::getProgramName(stripProgram);
    }
}

String StripOrri::getProgramDescription(STRIP_PROGRAMS stripProgram) {

    switch(stripProgram){
        case ORRI : return "Color 0 will be set to underline.  Color 1 will be set to O.  Color 2 will be set to first R.  Color 3 will be set to second R.  Color 4 will be set to I.";
        default   : return StripHelper::getProgramDescription(stripProgram);
    }
    
}

ProgramValueInfo StripOrri::getProgramValuesAsJsonArray(STRIP_PROGRAMS stripProgram)
{
    switch (stripProgram)
    {
        case ORRI : return ProgramValueInfo{"[]", COLOR_COUNT - 1};
        default   : return StripHelper::getProgramValuesAsJsonArray(stripProgram);
    }
}

void StripOrri::runProgram(STRIP_PROGRAMS stripProgram)
{
    switch (stripProgram)
    {
        case ORRI : programOrri(); break;
        default   : StripHelper::runProgram(stripProgram);
    }
}

//steps one pixel at a time and changes the the pixels aftier
void StripOrri::initProgram(STRIP_PROGRAMS programToSet) {
    switch(programToSet) {
        case ORRI : setDirection(true); break;
        default   : StripHelper::initProgram(programToSet);
    }
}

void StripOrri::programOrri() {
        
        stepUp();
        fillByIndex( 0,    78, getColorBank(1)); // 1 = letterO     BLUE
        fillByIndex( 79,  156, getColorBank(2)); // 2 = letterR     YELLOW
        fillByIndex( 157, 234, getColorBank(3)); // 2 = letterR     RED
        fillByIndex( 235, 268, getColorBank(4)); // 4 = letterI     GREEN 
		fillByIndex(267,  299, getColorBank(0)); // 0 = underLine   RED
		fastLED->show();
}

#endif 
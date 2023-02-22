#include "StripOrri.h"

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


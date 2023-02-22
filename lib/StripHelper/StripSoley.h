#ifndef STRIPSOLEY_H
#define STRIPSOLEY_H

#include "StripHelper.h"

class StripSoley: public StripHelper
{
public:
    StripSoley();
    ~StripSoley();
    
    void programSoley();
    void initProgram(STRIP_PROGRAMS programToSet) override;
    void runProgram(STRIP_PROGRAMS stripProgram) override;
    String getProgramName(STRIP_PROGRAMS stripProgram) override;
    String getProgramDescription(STRIP_PROGRAMS stripProgram) override;
    ProgramValueInfo getProgramValuesAsJsonArray(STRIP_PROGRAMS stripProgram) override;

};
#endif
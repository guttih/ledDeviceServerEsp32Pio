#ifndef STRIPORRI_H
#define STRIPORRI_H

#include "StripHelper.h"

class StripOrri: public StripHelper
{
public:
    StripOrri();
    ~StripOrri();
    
    void initProgram(STRIP_PROGRAMS programToSet) override;
    void runProgram(STRIP_PROGRAMS stripProgram) override;
    String getProgramName(STRIP_PROGRAMS stripProgram) override;
    String getProgramDescription(STRIP_PROGRAMS stripProgram) override;
    ProgramValueInfo getProgramValuesAsJsonArray(STRIP_PROGRAMS stripProgram) override;

};

#endif
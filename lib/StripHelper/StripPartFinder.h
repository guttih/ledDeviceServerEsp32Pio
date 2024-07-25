#ifndef STRIPPARTFINDER_H
#define STRIPPARTFINDER_H


#include "StripHelper.h"

typedef struct
{
    int row;
    int column;
}CELL;

const int GRID_COLUMN_COUNT = 18;
const int GRID_FIRST_LARGE_SHELF_COL = 0;



class StripPartFinder : public StripHelper
{

private:
    void programPixelRange();
    void programGridSquare();
    void programGridShelf();
    void programGridShelfInit();
    void programGridShelfAnimate();

public:

    StripPartFinder();
    ~StripPartFinder();

    void initProgram( STRIP_PROGRAMS programToSet ) override;
    void runProgram( STRIP_PROGRAMS stripProgram ) override;
    String getProgramName( STRIP_PROGRAMS stripProgram ) override;
    String getProgramDescription( STRIP_PROGRAMS stripProgram ) override;
    ProgramValueInfo getProgramValuesAsJsonArray( STRIP_PROGRAMS stripProgram ) override;

    int GridToStripIndex( CELL cell );
    bool isValidCell( CELL cell );
    void getBoxValues( int cellColumn, int *boxIndexStart, int *firstColumn, int *rowCount );
    void gridLightSquare( CELL startCell, CELL endCell, CRGB borderColor, CRGB fillColor );


private:

};

#endif
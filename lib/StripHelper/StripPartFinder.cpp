#include "StripPartFinder.h"


StripPartFinder::StripPartFinder()
{

}

StripPartFinder::~StripPartFinder()
{

}
void StripPartFinder::programPixelRange()
{
    int index = ( value1 >= 0 && value1 < ledCount ) ? value1 : ledCount - 1;
    int pixelCount = ( value2 >= 0 && index + ( value2 - 1 ) < ledCount ) ? value2 : 1;
    fill_solid( leds, getCount(), getColorBank( 1 )   );
    fillByIndex( index, index + ( pixelCount - 1 ), getColorBank( 0 ) );
    fastLED->show();
}

/*
    Lights up a row in the grid.
    parameters:
        - startCell: cell grid location of the first pixel to be lit up,
        - count    : how many pixels should be lit up in the row
        - onColor  : which color to set
*/
void StripPartFinder::gridLightSquare( CELL startCell, CELL endCell, CRGB borderColor, CRGB fillColor )
{

    if( !isValidCell( startCell ) || !isValidCell( endCell ) )
        return; //invald cells

    CELL cell;
    int startIndex;
    CRGB color;
    //Serial.println("to Cell r:" + String(endCell.row)+",c:"+String(endCell.column) );
    for( cell.row = startCell.row; cell.row < endCell.row + 1; cell.row++ )
    {
        for( cell.column = startCell.column; cell.column < endCell.column + 1; cell.column++ )
        {
            startIndex = GridToStripIndex( cell );
            //select borderColor for outlines otherwise fill color
            color = ( cell.row    == startCell.row    || cell.row    == endCell.row ||
                      cell.column == startCell.column || cell.column == endCell.column
                      ) ? borderColor : fillColor;
            leds[ startIndex ] = color;
        }
    }





}

void StripPartFinder::programGridSquare()
{
    int fromRow = value1, fromCol = value2;
    int toRow = value3, toCol = value4;
    CELL from = { .row = fromRow, .column = fromCol },
         to = { .row =   toRow, .column =   toCol };
    //turn off all leds
    fill_solid( leds, getCount(), CRGB::Black );
    gridLightSquare( from, to, getColorBank( 0 ), getColorBank( 1 ) );
    fastLED->show();
}

void StripPartFinder::programGridShelfInit()
{
    setDirection( true );
    setStep( 0 );
    turns = 0;
}
void StripPartFinder::programGridShelfAnimate()
{

    CELL cell = { .row = value1, .column = value2 };
    int wait = 12;
    int boxIndexStart, firstCol, rowCount;
    if( !isValidCell( cell ) )
    {
        Serial.println( "Invalid cell, quitting programGridShelfAnimate" );
        return;
    }
    getBoxValues( cell.column, &boxIndexStart, &firstCol, &rowCount );

    CELL topLeft     = { .row = 0, .column = firstCol };
    CELL bottomRight = { .row = rowCount - 1, .column = firstCol + 5 };
    for( int i = 0; i < 20; i++ )
    {
        if( i % 2 )
        {
            fill_solid( leds, getCount(), CRGB::Black );
        }
        else
        {
            gridLightSquare( topLeft, bottomRight, getColorBank( 0 ), CRGB::Black );
        }

        fastLED->show(); delay( wait );
    }

    wait = 150;
    fill_solid( leds, getCount(), CRGB::Black );
    gridLightSquare( topLeft, bottomRight, getColorBank( 0 ), CRGB::Black );
    fastLED->show(); delay( wait );
    bool goOn;
    do
    {
        if( topLeft.row        < cell.row )
            topLeft.row++;
        if( topLeft.column     < cell.column )
            topLeft.column++;
        if( bottomRight.row    > cell.row )
            bottomRight.row--;
        if( bottomRight.column > cell.column )
            bottomRight.column--;
        goOn = topLeft.row< cell.row || topLeft.column< cell.column || bottomRight.row > cell.row || bottomRight.column > cell.column;

        fill_solid( leds, getCount(), CRGB::Black );
        gridLightSquare( topLeft, bottomRight, getColorBank( 0 ), CRGB::Black );
        fastLED->show();
        if( goOn )
            delay( wait ); //no delay for the last time

    } while( goOn );
}

void StripPartFinder::programGridShelf()
{
    stepUp();
    bool showAnimation = ( step == 1 && turns == 0 ) //the first time
                         ||
                         ( step == 0 && turns % 10 == 0 && turns < 101 ); //every 10th time

    if( showAnimation )
    {
        programGridShelfAnimate();
    }
    int col = value2;
    CELL cell = { .row = value1, .column = col };
    if( !isValidCell( cell ) )
        return;
    //turn off all leds
    fill_solid( leds, getCount(), CRGB::Black );
    int startIndex = GridToStripIndex( cell ),
        secondIndex = -1;
    if( col >= GRID_FIRST_LARGE_SHELF_COL && cell.row > 4 )
    {

        int oddCol = cell.column % 2;
        if( oddCol )
        {
            //start colum must be even
            cell.column--;
            startIndex = GridToStripIndex( cell );
        }
        //This is a two light shelf so lets light them both
        CELL to = { .row = cell.row, .column = cell.column + 1 };
        secondIndex = GridToStripIndex( to );
        gridLightSquare( cell, to, getColorBank( 0 ), getColorBank( 1 ) );

    }
    else
    {
        leds[ startIndex ] = getColorBank( 0 );
    }
    fastLED->show();

    CRGB color;
    if( showAnimation )
    {
        for( int i = 0; i < 12; i++ )
        {
            color = i % 2 ? getColorBank( 0 ) : CRGB::White;
            leds[ startIndex ] = color;
            if( secondIndex > -1 )
                leds[ secondIndex ] = color;
            delay( 150 );
            fastLED->show();
        }
    }
}
/*
    Part-finder version 1.0  (all little shelfs in box 1 but big shelfs in box 2 and 3)
       --  Box 1  --          --  Box 2  --           --  Box 3  --
   |c0|c1|c2|c3|c4|c5| | c6| c7| c8| c9|c10|c11| |c12|c13|c14|c15|c16|c17|
r0 | 0|19|20|39|40|59| | 60| 75| 76| 91| 92|107| |108|123|124|139|140|155| r0
r1 | 1|18|21|38|41|58| | 61| 74| 77| 90| 93|106| |109|122|125|138|141|154| r1
r2 | 2|17|22|37|42|57| | 62| 73| 78| 89| 94|105| |110|121|126|137|142|153| r2
r3 | 3|16|23|36|43|56| | 63| 72| 79| 88| 95|104| |111|120|127|136|143|152| r3
r4 | 4|15|24|35|44|55| | 64| 71| 80| 87| 96|103| |112|119|128|135|144|151| r4
r5 | 5|14|25|34|45|54| | 65  70| 81  86| 97 102| |113 118|129 134|145 150| r5
r6 | 6|13|26|33|46|53| | 66  69| 82  85| 98 101| |114 117|130 133|146 149| r6
r7 | 7|12|27|32|47|52| | 67  68| 83  84| 99 100| |115 116|131 132|147 148| r7
r8 | 8|11|28|31|48|51|
r9 | 9|10|29|30|49|50|

    Part-finder version 2.0  (all boxes the same as are in box 2 and 3 in version 1.0)
       --  Box 1  --          --  Box 2  --           --  Box 3  --
    |c0|c1|c2|c3|c4|c5| | c6| c7| c8| c9|c10|c11| |c12|c13|c14|c15|c16|c17|
r0  | 0|15|16|31|32|47| | 48| 63| 64| 79| 80| 95| | 96|111|112|127|128|143|
r1  | 1|14|17|30|33|46| | 49| 62| 65| 78| 81| 94| | 97|110|113|126|129|142|
r2  | 2|13|18|29|34|45| | 50| 61| 66| 77| 82| 93| | 98|109|114|125|130|141|
r3  | 3|12|19|28|35|44| | 51| 60| 67| 76| 83| 92| | 99|108|115|124|131|140|
r4  | 4|11|20|27|36|43| | 52| 59| 68| 75| 84| 91| |100|107|116|123|132|139|
r5  | 5 10|21 26|37 42| | 53  58| 69  74| 85  90| |101 106|117 122|133 138|
r6  | 6  9|22 25|38 41| | 54  57| 70  73| 86  89| |102 105|118 121|134 137|
r7  | 7  8|23 24|39 40| | 55  56| 71  72| 87  88| |103 104|119 120|135 136|
r8  | 155 154 153 152 | |     151 150 149 148   | |     147 146 145 144   | eftir að implementa

*/
int StripPartFinder::GridToStripIndex( CELL cell )
{
    /* Version 1.0
        Box indexStart firstCol  rowCount
         1      0         0         10    (index 0 - 59)
         2     60         6          8    (index 60 - 107)
         3     108       12          8   (index 108 - 155)

         Version 2.0
        Box indexStart firstCol  rowCount
         1      0         0         8    (index 0 - 47)
         2     48         6         8   (index 48 - 95)
         3     96        12         8   (index 96 - 143)
    */

    if( !isValidCell( cell ) )
        return -1;

    int boxIndexStart, firstCol, rowCount;

    getBoxValues( cell.column, &boxIndexStart, &firstCol, &rowCount );

    int retIndex = -1;
    int oddRow = cell.column % 2;
    int startIndex =( ( cell.column - firstCol ) * rowCount ) + boxIndexStart;
    int res;
    if( !oddRow )
        res = startIndex + cell.row;
    else
        res = startIndex + ( rowCount - 1 ) - cell.row;

    if( cell.row > 4 && cell.column >= GRID_FIRST_LARGE_SHELF_COL )
    {
        int oddCol = cell.column % 2;
        if( !oddRow && oddCol )
            res--; //even row and odd column
        else if( oddRow && !oddCol )
            res--; //odd row and even column
    }

    retIndex = res;
    return retIndex;

}

/*
    Gets information about a box the given cell is in.
    Note this function does not check if cell is valid for performance reasons.
    Call function isValidCell if you need to be sure the cell is valid.

    after:
      parameters have been set to the corresponding box values
*/
void StripPartFinder::getBoxValues( int cellColumn, int *boxIndexStart, int *firstColumn, int *rowCount )
{
    /*

    Part-finder version 1.0  (all little shelfs in box 1 but big shelfs in box 2 and 3)
       --  Box 1  --          --  Box 2  --           --  Box 3  --
   |c0|c1|c2|c3|c4|c5| | c6| c7| c8| c9|c10|c11| |c12|c13|c14|c15|c16|c17|
r0 | 0|19|20|39|40|59| | 60| 75| 76| 91| 92|107| |108|123|124|139|140|155| r0
r1 | 1|18|21|38|41|58| | 61| 74| 77| 90| 93|106| |109|122|125|138|141|154| r1
r2 | 2|17|22|37|42|57| | 62| 73| 78| 89| 94|105| |110|121|126|137|142|153| r2
r3 | 3|16|23|36|43|56| | 63| 72| 79| 88| 95|104| |111|120|127|136|143|152| r3
r4 | 4|15|24|35|44|55| | 64| 71| 80| 87| 96|103| |112|119|128|135|144|151| r4
r5 | 5|14|25|34|45|54| | 65  70| 81  86| 97 102| |113 118|129 134|145 150| r5
r6 | 6|13|26|33|46|53| | 66  69| 82  85| 98 101| |114 117|130 133|146 149| r6
r7 | 7|12|27|32|47|52| | 67  68| 83  84| 99 100| |115 116|131 132|147 148| r7
r8 | 8|11|28|31|48|51|
r9 | 9|10|29|30|49|50|

    Part-finder version 2.0  (all boxes the same as are in box 2 and 3 in version 1.0)
       --  Box 1  --          --  Box 2  --           --  Box 3  --
    |c0|c1|c2|c3|c4|c5| | c6| c7| c8| c9|c10|c11| |c12|c13|c14|c15|c16|c17|
r0  | 0|15|16|31|32|47| | 48| 63| 64| 79| 80| 95| | 96|111|112|127|128|143|
r1  | 1|14|17|30|33|46| | 49| 62| 65| 78| 81| 94| | 97|110|113|126|129|142|
r2  | 2|13|18|29|34|45| | 50| 61| 66| 77| 82| 93| | 98|109|114|125|130|141|
r3  | 3|12|19|28|35|44| | 51| 60| 67| 76| 83| 92| | 99|108|115|124|131|140|
r4  | 4|11|20|27|36|43| | 52| 59| 68| 75| 84| 91| |100|107|116|123|132|139|
r5  | 5 10|21 26|37 42| | 53  58| 69  74| 85  90| |101 106|117 122|133 138|
r6  | 6  9|22 25|38 41| | 54  57| 70  73| 86  89| |102 105|118 121|134 137|
r7  | 7  8|23 24|39 40| | 55  56| 71  72| 87  88| |103 104|119 120|135 136|

    Each box has 6 columns but box that has large has 8 rows and others have 10 rows.
    Version 1.0  ->  const int GRID_FIRST_LARGE_SHELF_COL = 6
        BoxNr boxIndexStart firstColumn rowCount BoxPixelIndeces
         1        0              0         10         0 -  59
         2       60              6          8        60 - 107
         3      108             12          8       108 - 155

    Version 2.0  ->  const int GRID_FIRST_LARGE_SHELF_COL = 0
        BoxNr boxIndexStart firstColumn rowCount BoxPixelIndeces
         1       0               0          8         0 -  47
         2      48               6          8        48 -  95
         3      96              12          8        96 - 143
    */

    // now let's find the values for *boxIndexStart, *firstColumn and *rowCount based on the cellColumn and GRID_FIRST_LARGE_SHELF_COL
    // GRID_FIRST_LARGE_SHELF_COL is a constant that is defined in the header file the version of the part-finder can be determined by this value


    int boxIdx = cellColumn / 6;   //COLUMN_PER_BOX

    *firstColumn = boxIdx * 6;    //COLUMN_PER_BOX

    if( boxIdx >= GRID_FIRST_LARGE_SHELF_COL / 6 )      //COLUMN_PER_BOX
    {
        *rowCount = 8;    //LARGE_SHELF_ROW_COUNT
    }
    else
    {
        *rowCount = 10;   //SMALL_SHELF_ROW_COUNT
    }

    *boxIndexStart = boxIdx * ( 6 * *rowCount );  // 6 * *rowCount as per boxIndexStart formula

}

// checks if a cell values are within the grid
bool StripPartFinder::isValidCell( CELL cell )
{

    if( cell.row < 0 || cell.column < 0 )
        return false;         //can not be negative
    if( cell.row > 9 || cell.column >= GRID_COLUMN_COUNT )
        return false;         //absolute grid maximum reached
    if( cell.column >= GRID_FIRST_LARGE_SHELF_COL && cell.row > 7 )
        return false;         //max row

    return true;
}
void StripPartFinder::initProgram( STRIP_PROGRAMS programToSet )
{
    switch( programToSet )
    {
        case GRIDSHELF:
            programGridShelfInit(); break;
        default:
            StripHelper::initProgram( programToSet );
    }
}
void StripPartFinder::runProgram( STRIP_PROGRAMS stripProgram )
{
    switch( stripProgram )
    {
        case SECTIONS:
            programSections(); break;
        case PIXELRANGE:
            programPixelRange(); break;
        case GRIDSQUARE:
            programGridSquare(); break;
        case GRIDSHELF:
            programGridShelf(); break;
        default:
            StripHelper::runProgram( stripProgram );
    }
}


String StripPartFinder::getProgramName( STRIP_PROGRAMS stripProgram )
{

    switch( stripProgram )
    {
        case PIXELRANGE:
            return "Pixel range";
        case GRIDSQUARE:
            return "Grid square";
        case GRIDSHELF:
            return "Grid shelf";
        default:
            return StripHelper::getProgramName( stripProgram );
    }
}

String StripPartFinder::getProgramDescription( STRIP_PROGRAMS stripProgram )
{

    switch( stripProgram )
    {
        case PIXELRANGE:
            return "Light up one or more pixels in sequence with color 0 and all other pixels will have color 1.";
        case GRIDSQUARE:
            return "Light up a square on the grid with outline from color 0 and inner color from color 1.";
        case GRIDSHELF:
            return "Light up a selected shelf in the grid with shelf colored with the color 0 and assistant color from color 1.";

        default:
            return StripHelper::getProgramDescription( stripProgram );
    }

}

ProgramValueInfo StripPartFinder::getProgramValuesAsJsonArray( STRIP_PROGRAMS stripProgram )
{
    int colors = 0;
    String values = "[";
    switch( stripProgram )
    {
        case PIXELRANGE:
            colors = 2;
            values+="\"Pixel index\",\"Pixel count\"";
            break;
        case GRIDSQUARE:
            colors = 2;
            values+="\"From row index\",\"From column index\",\"To row index\",\"To column index\"";
            break;
        case GRIDSHELF:
            colors = 2;
            values+="\"Shelf row index\",\"Shelf column index\"";
            break;
        default:
            return StripHelper::getProgramValuesAsJsonArray( stripProgram );
    }
    values += "]";

    return ProgramValueInfo {
        values,
        colors
    };
}
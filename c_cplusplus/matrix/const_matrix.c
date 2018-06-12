#include <stdio.h>

#define ROWS 3
#define COLS 5

main()
{
    int i,j;
    int matrix[ROWS][COLS] = {
                                { 00,01,02,03,04 },
                                { 10,11,12,13,14 },
                                { 20,21,22,23,24 }
                            };
    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            printf ("matrix[%d][%d] = %d\n", i, j, matrix[i][j]);
        }
    }
}


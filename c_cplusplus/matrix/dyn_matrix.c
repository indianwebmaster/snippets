#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 5

main()
{
    int i,j;
    int *dyn_matrix[ROWS];

    for (i=0; i<ROWS; i++) {
        dyn_matrix[i] = (int *)malloc (sizeof(int) * COLS);
        for (j=0; j<COLS; j++) {
            dyn_matrix[i][j] = j + (i*10);
        }
    }
    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            printf ("dyn_matrix[%d][%d] = %d\n", i, j, dyn_matrix[i][j]);
        }
        free(dyn_matrix[i]);
    }
}


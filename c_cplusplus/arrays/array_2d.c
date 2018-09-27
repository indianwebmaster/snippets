#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 3
#define COLS 6
#define STRING_SIZE 32
int main()
{
	int array_2d[ROWS][COLS];
	char string_array_2d[ROWS][STRING_SIZE];
	int i,j;

	for (i=0; i<ROWS; i++) {
		for (j=0; j<COLS; j++) {
			array_2d[i][j] = i + j;
			printf ("array_2d[row-%d][col-%d] = %d\n",i,j,array_2d[i][j]);
		}
	}

	for (i=0; i<ROWS; i++) {
		sprintf (string_array_2d[i],"%d",i);
		printf ("%s\n",string_array_2d[i]);
	}
	return 0;
}

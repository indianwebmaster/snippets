#include <stdio.h>
#include <stdlib.h>

#define NUMELEMS 10
int main(int argc, char *argv[])
{
	int *(aofp[NUMELEMS]);
	int i;

	for (i=0; i<NUMELEMS; i++) {
		aofp[i] = (int *) NULL;
	}

	for (i=0; i<NUMELEMS; i++) {
		aofp[i] = &i;
		printf ("*(aofp[%d]) = %d, aofp[%d] = %lx, aofp = %lx\n",
			i, *(aofp[i]), i, (unsigned long) aofp[i], (unsigned long) aofp);
	}
	return EXIT_SUCCESS;
}

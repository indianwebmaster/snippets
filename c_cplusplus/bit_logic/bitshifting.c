#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	unsigned short bitval1, bitval2;
	unsigned int val;

	if (argc > 1) bitval1 = atoi(argv[1]); else bitval1 = 0x1234;
	if (argc > 2) bitval2 = atoi(argv[2]); else bitval2 = 0x00AA;

	val = (unsigned int) bitval2;
	val <<= 16;
	val |= bitval1;
	val &= 0x00FFFFFF;

	printf ("bitval1 = %X, bitval2 = %X, val = %X\n", bitval1, bitval2, val);

}

#include <stdio.h>

#define NUM 3
#define WIDTH 5
test1()
{
        char str[NUM][WIDTH] = { "1234", "2345", "3456" };
        int i;

        for (i=0; i<NUM; i++) {
                printf ("str[%d] = %s\n", i, str[i]);
        }
}

#define MAXSTRLEN       10
#define NUMSTRINGS      2
test2()
{
        char str[NUMSTRINGS][MAXSTRLEN] = { "1234", "2345" };
        int i;

        for (i=0; i<NUMSTRINGS; i++) {
                printf ("str[%d] = %s\n", i, str[i]);
        }
}

main()
{
        test1();
        test2();
}

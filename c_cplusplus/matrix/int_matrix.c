#include <stdio.h>

void func(int *pi, int nelems)
{
    while (--nelems >= 0) {
        pi[nelems] = nelems;
    }
}

void func2(int pi[], int nelems )
{
    func((int*)pi, nelems);
}

main()
{
        int iarr[10];
        int i;

        func((int*)iarr, 10);
        for (i=0; i<10; i++) {
                printf ("%d = %d\n", i, iarr[i]);
        }

        func2(iarr, 10);
        for (i=0; i<10; i++) {
                printf ("%d = %d\n", i, iarr[i]);
        }
}


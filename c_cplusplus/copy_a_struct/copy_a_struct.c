/* The purpose of this program is to check if you can assign two structure variable to copy
   the contents from one to the other. I thought not, but I see it being done in
   get_reliable_copy() in the sensor code
*/
#include <stdio.h>
#include <string.h>

typedef struct {
        short sval1;
        short sval2;
} A_STRUCT;

main()
{
        A_STRUCT s1, s2;

        s1.sval1 = 10;
        s1.sval2 = 20;

        memset (&s2, 0x0, sizeof (A_STRUCT));
        printf ("Before copy: s1(%d, %d), s2(%d, %d)\n",
                                s1.sval1, s1.sval2, s2.sval1, s2.sval2);

        s2 = s1;
        printf ("After copy: s1(%d, %d), s2(%d, %d)\n",
                                s1.sval1, s1.sval2, s2.sval1, s2.sval2);

        if ( (s1.sval1 == s2.sval1) && (s1.sval2 == s2.sval2) ) {
                printf ("Viola: it works!!!!\n");
                printf ("Mem addresses: s1(%x, %x), s2(%x, %x)\n",
                                        &(s1.sval1), &(s1.sval2), &(s2.sval1), &(s2.sval2));
        } else {
                printf ("Oops: does not work\n");
        }

        return (0);
}

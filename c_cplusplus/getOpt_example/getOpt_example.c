#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void showhelp(char *progname)
{
        fprintf (stderr, "%s [-a] [-b] [-c cvalue]\n", progname);
}

int main (int argc, char *argv[])
{
        int aflag = 0;
        int bflag = 0;
        char *cValue = NULL;
        int i;
        int c;

        opterr = 0;

        while ( (c = getopt (argc, argv, "abc:h")) != -1) {
                switch (c) {
                        case 'a':
                                aflag = 1;
                                break;
                        case 'b':
                                bflag = 1;
                                break;
                        case 'c':
                                cValue = optarg;
                                break;
                        case 'h':
                                showhelp (argv[0]);
                                return (0);
                        case '?':
                                if (optopt == 'c') {
                                        fprintf (stderr, "Option -c requires an argument\n");
                                } else {
                                        fprintf (stderr, "Unknown option (-%c) specified\n", optopt);
                                }
                                showhelp(argv[0]);
                                return (1);
                        default:
                                return (1);
                }
        }

        printf ("aflag = %d, bflag = %d, cValue = %s\n", aflag, bflag, (cValue==NULL?"<nil>":cValue) );

        for (i = optind; i < argc; i++) {
                printf ("Non-option argument (%d) = %s\n", i, argv[i]);
        }
}


#include <stdio.h>
#include <string.h>

void parse_args(char *istr, char **args, int *numArgs)
{
        char ch;
        int len;
        int i;
        int nargs = 0;
        int spaceFound, quoteFound, escapeFound;

        len = strlen (istr);
        spaceFound = quoteFound = escapeFound = 0;
        for (i=0; i<len; i++) {
                switch (istr[i]) {
                        case '"':
                        case '\'':
                                quoteFound = 1;
                                break;
                        case ' ':
                        case '\t':
                                spaceFound = 1;
                                break;
                        case '\\':
                                escapeFound = 1;
                                break;
                        default:
                                ch=istr[i];
                                break;
                }
        }
}

main()
{
        char inputString[1024];
        char delim[8] = " \"";
        char *token;
        int i = 0;

        printf ("Enter the input string\n");
        fgets (inputString, 512, stdin);

        token = strtok(inputString,delim);
        printf ("%d: %s\n", i++, token);

        token = strtok(NULL,delim);
        printf ("%d: %s\n", i++, token);

        token = strtok(NULL,delim);
        printf ("%d: %s\n", i++, token);
}

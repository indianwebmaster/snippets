
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NUMSTRINGS 16
#define MAXSTRLEN  64

/** This function takes an input string and breaks it into an args
 * array. It accounts for an argument with embedded spaces enclosed in
 * quotes.
 */
void splitString(char *istr, char args[][MAXSTRLEN], int *numArgs)
{
    char ch;
    int len;
    int i;
    int nargs = 0;
    int curarglen = 0;
    int chFound, spaceFound, quoteStartFound, escapeFound;

    len = strlen (istr);
    quoteStartFound = 0;
    for (i=0; i<len; i++) {
        chFound = spaceFound = escapeFound = 0;
        ch=istr[i];
        switch (ch) {
            case '"':
            case '\'':
                if (quoteStartFound == 0) {
                    quoteStartFound = 1;
                } else {
                    quoteStartFound = 0;
                }
                break;
            case ' ':
            case '\t':
                spaceFound = 1;
                break;
            case '\\':
                escapeFound = 1;
                i++;
                if (i<len) {
                    ch = istr[i];
                    chFound = 1;
                }
                break;
            default:
                chFound = 1;
                break;
        }
        if ( chFound == 1 ) {
            args[nargs][curarglen++] = ch;
        }
        if ( (quoteStartFound == 1) && (spaceFound == 1) ) {
            args[nargs][curarglen++] = ch;
        }
        if ( (spaceFound == 1) && (quoteStartFound == 0) && (escapeFound == 0) ) {
            args[nargs][curarglen++] = '\0';
            nargs++;
            curarglen = 0;
        }
    }
    if ((nargs > 0) && (curarglen > 0)) {
        args[nargs][curarglen++] = '\0';
        nargs++;
    }
    *numArgs = nargs;
}

int main(int argc, char** argv) {
    char inputString[1024];
    int i;
    char args[NUMSTRINGS][MAXSTRLEN];
    int numArgs;

    strcpy (inputString,"abcd \"xyz 123\" 12\\\\ab");
    printf ("%s\n",inputString);
    splitString(inputString,args,&numArgs);
    for (i=0; i<numArgs; i++) {
        printf ("args[%d] = %s\n",i,args[i]);
    }

    return (EXIT_SUCCESS);
}

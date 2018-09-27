/** This function will trim a string by eliminating the spaces from
 * the start and the end of the string.
 */
void trim(char *s)
{
	int origLen, len;
	char *sCopy;
	int start, end;
	
	origLen = strlen(s);
	sCopy = strdup(s);
	if (sCopy != NULL) {
		len = strlen(sCopy);
		for (start=0; start= 0; end--) {
			if (!isspace(sCopy[end])) {
				break;
			}
		}
	
		sCopy[end+1] = '\0';
		strcpy (s, &(sCopy[start]));
		free(sCopy);
	}
}

int main()
{
	char inputString[64] = " Spaces at start and end   ";

	printf ("%s\n",inputString);
	trim(inputString);
	printf ("%s\n",inputString);
}

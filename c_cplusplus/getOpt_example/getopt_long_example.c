#include <stdio.h>	/* for printf() */
#include <stdlib.h>	/* for abort() */
#include <getopt.h>

static int verbose_flag;

int main (int argc, char *argv[])
{
	int c;
	int exit_loop = 0;

	while (!exit_loop) {
		static struct option long_options[] = {
			/* these options set a flag */
			{"verbose", no_argument,       &verbose_flag, 1},
			{"brief",   no_argument,       &verbose_flag, 0},
			/* these options DO NOT set a flag */
			{"add",     no_argument,       0,             'a'},
			{"append",  no_argument,       0,             'b'},
			{"delete",  required_argument, 0,             'd'},
			{"create",  required_argument, 0,             'c'},
			{"file",    required_argument, 0,             'f'},
			{0,         0,                 0,             0}
		};

		int option_index = -1;

		c = getopt_long (argc, argv, "abc:d:f:", long_options, &option_index);
		printf ("option_index = %d\n", option_index);
		/* Detect end of the options */
		if (c == -1) {
			exit_loop = 1;
		} else {
			switch (c) {
			case 0:
				/* If this option set a flag, do nothingi. Which would be the case for --verbose in this example */
				if (long_options[option_index].flag != 0) 
					break;

				printf ("Option %s", long_options[option_index].name);
				if (optarg)
					printf (" with optarg %s", optarg);
				printf ("\n");
				break;

			case 'a':
				if (option_index < 0)
					printf ("Option -%c\n",c);
				else
					printf ("Option %s (-%c)\n", long_options[option_index].name, c);
				break;
			case 'b':
				if (option_index < 0)
					printf ("Option -%c\n",c);
				else
					printf ("Option %s (-%c)\n", long_options[option_index].name, c);
				break;
			case 'c':
				if (option_index < 0)
					printf ("Option -%c with optarg %s\n", c, optarg);
				else
					printf ("Option %s (-%c) with optarg %s\n", long_options[option_index].name, c, optarg);
				break;
			case 'd':
				if (option_index < 0)
					printf ("Option -%c with optarg %s\n", c, optarg);
				else
					printf ("Option %s (-%c) with optarg %s\n", long_options[option_index].name, c, optarg);
				break;
			case 'f':
				if (option_index < 0)
					printf ("Option -%c with optarg %s\n", c, optarg);
				else
					printf ("Option %s (-%c) with optarg %s\n", long_options[option_index].name, c, optarg);
				break;
			case '?':
				/* Do nothing. getopt_long already printed an error message */
			default:
				abort();
			}
		}
	}

	/* Perform diff action depending on --verbose or --brief */
	if (verbose_flag)
		printf ("Verbose Flag set\n");

	/* Print any remaining cmdline args  (not options) */
	if (optind < argc) {
		printf ("Non option cmdline args: ");
		while (optind < argc) {
			printf ("%s ",argv[optind++]);
		}
		printf ("\n");
	}
}

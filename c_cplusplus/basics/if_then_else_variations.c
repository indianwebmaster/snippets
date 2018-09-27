main()
{
	int i = -1;
	short flag;

	flag = 1; /* true */
	i = (flag) ? (100) : (0);
	printf ("i = (flag) ? (100) : (0) .... flag = true, i = %d\n", i);

	flag = 0; /* false */
	i = (flag) ? (100) : (0);
	printf ("i = (flag) ? (100) : (0) .... flag = false, i = %d\n", i);
}

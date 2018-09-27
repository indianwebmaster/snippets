#include <iostream>
using namespace std;

template <class T>
T GetMax (T a, T b) 
{
	T result;

	result = (a > b) ? a : b;

	return (result);
}

int main()
{
	int i=5, j=6, k;
	long l=10, m=5, n;

	//k = GetMax<int>  (i,j);
	//n = GetMax<long> (l,m);
	/* You can skip the <int> or <long> notation and let the compiler 
	 * do the job for you based on the type of variables passed in the function	
	 */
	k = GetMax  (i,j);	
	n = GetMax (l,m);

	cout << k << endl;
	cout << n << endl;

	return 0;
}

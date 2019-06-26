// * Convert this program to C++
// * * change to C++ io
// *
// * * change to one line comments
// *
// * * change defines of constants to const
// *
// * * change array to vector<>
// *
// * * inline any short function
// *
// * 

// Substitution of standardIO C library to the iostream library
//#include <stdio.h>
#include <iostream>
// We use the std namespace so we can omit std:: before cout, cin ,etc...
using namespace std;

// Change the define to a const unsigned int declaration.
// Slightly different as one is a preprocessor directive 
// and the other is a variable declaration but it is safer,
// more readable even if slightly less efficient in terms of memory
// as a variable is created in memory.
// #define N 40
const unsigned int N = 40;

template <class sumType>
// Changed to an inline function as we do not want the calling overhead for this very simple function.
// We can make this function general by using the template
// P is derefenced not by using pointer but using C++ &; the array which is summed (d[]) is constant as it is not modified.
// The size parameter (n) is an unsigned int (not a big gain but still more correct as index should be only positive...)
inline void sum(sumType& p, unsigned int n, const sumType d[]) 
{

	// Counter should be unsigned
	unsigned int i;

	p = 0;

	for(i = 0; i < n; ++i)

		p = p + d[i];

	
}

int main()

{


	int accum = 0;

	int data[N];

	for(int i = 0; i < N; ++i) // we can declare inside the for

		data[i] = i;

	sum(accum, N, data);

	//printf("sum is %d\n", accum);
	cout << "sum is " << accum << endl;

	return 0;

}

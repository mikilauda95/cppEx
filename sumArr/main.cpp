#include <iostream>

using namespace std;

template <class T>

inline T sumArray(T* a, unsigned int size){
	
	T sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += a[i];
	}	
	return sum;
}

int main(int argc, char *argv[])
{
	const unsigned int size = 9;
	double d_arr[size];
	double d_sum;
	int i_arr[size];
	int i_sum;

	for (int i = 0; i < size; ++i) {
		d_arr[i] = 0.5;	
		i_arr[i] = 1;	
	}

	d_sum = sumArray(d_arr, size);
	i_sum = sumArray(i_arr, size);

	cout << "Sum of double array is " << d_sum << endl;
	cout << "Sum of int array is " << i_sum << endl;

	return 0;
}

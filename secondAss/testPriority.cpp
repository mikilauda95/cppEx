#include "PriorityQueue.h"
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	pairtype a(1,1);
	pairtype b(2,1);
	pairtype c(1,2);
	cout << (a < b) << endl;
	cout << (a < c) << endl;
	cout << (b < c) << endl;

	return 0;
}

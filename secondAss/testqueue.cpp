#include "PriorityQueue.h"
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	pairtype tmp;

	unsigned int contained = 23;
	PriorityQueue Q;
	Q.Insert(90, 9);
	Q.Insert(80, 8);
	Q.Insert(70, 7);
	Q.Insert(60, 6);
	Q.Insert(50, 5);
	Q.Insert(10, 1);
	Q.Insert(20, 2);
	Q.Insert(30, 3);
	Q.PrintQueue();

	std::cout << std::endl;
	std::cout << std::endl;

	tmp = Q.Top();
	cout << tmp.first << " " << tmp.second << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	Q.PickMinPriority();
	Q.PrintQueue();

	std::cout << "Element " <<  contained << " " << Q.Contains(contained) << std::endl;
	return 0;
}

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
	PriorityQueue<pairtype> Q;
	Q.Insert(make_pair(90, 9));
	Q.Insert(make_pair(80, 8));
	Q.Insert(make_pair(70, 7));
	Q.Insert(make_pair(60, 6));
	Q.Insert(make_pair(50, 5));
	Q.Insert(make_pair(10, 1));
	Q.Insert(make_pair(20, 2));
	Q.Insert(make_pair(30, 3));
	Q.PrintQueue();

	std::cout << std::endl;
	std::cout << std::endl;

	tmp = Q.Top();
	cout << tmp.first << " " << tmp.second << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	Q.PickMinPriority();
	Q.PrintQueue();

	//std::cout << "Element " <<  contained << " " << Q.Contains(contained) << std::endl;
	return 0;
}

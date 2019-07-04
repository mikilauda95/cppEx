#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <functional>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;




typedef pair<unsigned int, unsigned int> pairtype;

template<class T>
class PriorityQueue
{
private:
	unsigned int NumElements;

	priority_queue<T, vector<T>, greater<T> > Queue;


public:
	PriorityQueue();
	virtual ~PriorityQueue();

	// PrintQueue()
	void PrintQueue();

	//Implemented as lazy delete
	void DecrPriority(T Priority);

	// Removes the top element of the queue
	void PickMinPriority();

	bool Contains(T queue_element);

	void Insert(T Priority);
		
	T Top();

	unsigned int Size();
	
};

#endif /* PRIORITYQUEUE_H */


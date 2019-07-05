#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "Mypair.h"
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;




typedef pair<unsigned int, unsigned int> Mypair;

template<class T> 
class PriorityQueue : public T
{
private:
	unsigned int NumElements;

	//template<class T>
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


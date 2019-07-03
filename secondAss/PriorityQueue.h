#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <functional>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

//template <class T=unsigned int> 

typedef pair<unsigned int, unsigned int> pairtype;

class PriorityQueue
{
private:
	unsigned int NumElements;

	priority_queue<pairtype, vector<pairtype>, greater<pairtype> > Queue;
	vector<pairtype> Costs;


public:
	PriorityQueue();
	virtual ~PriorityQueue();

	// PrintQueue()
	void PrintQueue();

	//Implemented as lazy delete
	void DecrPriority(unsigned int QueueElem, unsigned int Priority);

	// Removes the top element of the queue
	void PickMinPriority();

	bool Contains(unsigned int queue_element);

	void Insert(unsigned int QueueElem, unsigned int Priority);
		
	pairtype Top();

	unsigned int Size();
	
};

#endif /* PRIORITYQUEUE_H */

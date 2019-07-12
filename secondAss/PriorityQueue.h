#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "Mypair.h"
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;





//PriorityQueue inherits from the std::priority_queue and add some functionality to it.
template<class T, class S = greater<T> > 
class PriorityQueue : public std::priority_queue<T, std::vector<T> , S >
{
private:
	unsigned int NumElements;

	//template<class T>
	//priority_queue<T, vector<T>, S > Queue;


public:
	PriorityQueue();
	virtual ~PriorityQueue();

	// PrintQueue()
	void PrintQueue();


	bool Remove(T QueueElem);
	//Implemented as lazy delete
	void DecrPriority(T Priority);

	// Removes the top element of the queue
	void PickMinPriority();

	unsigned int Contains(T queue_element);

	bool Empty() const;

	void Insert(T Priority);
		
	T Top();

	unsigned int Size();
	
};

#endif /* PRIORITYQUEUE_H */


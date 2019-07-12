#include "Mypair.h"
#include "PriorityQueue.h"
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

// Overload the << operator to print pairs
template <typename T, typename S> 
ostream& operator<<(ostream& os, const pair<T, S>& v) 
{ 
	os << "("; 
	os << v.first << ", " << v.second << ")"; 
	return os; 
} 

template<class T, class S > 
PriorityQueue<T, S> :: PriorityQueue() : NumElements(0){

}

template<class T, class S > 
PriorityQueue<T, S> :: ~PriorityQueue(){

}

// Workaround to iterate on a list.
template<class T, class S > 
void PriorityQueue<T, S> :: PrintQueue(){
	PriorityQueue<T, S>  temp = *this;
	//temp = Queue;
	while(!temp.empty()){
		cout << temp.top().first << " " << temp.top().second << " " << endl;
		temp.pop();
	}
}


// Insert an elemente to a list
template<class T, class S > 
void PriorityQueue<T, S> :: Insert(T QueueElem){
	//T tmp(QueueElem);
	//Queue.push(tmp);
	//NumElements ++;
	T tmp(QueueElem);
	this->push(tmp);
	NumElements ++;
}

//The Remove method is not implemented as not necessary in the algorithm
template<class T, class S >
bool PriorityQueue<T, S > :: Remove(T QueueElem){
}

// The DecrPriority simply looks if the value associated to a certain key is lower than the given value. If so, it adds the element to the Queue (update phase for the open set)
template<class T, class S > 
void PriorityQueue<T, S> :: DecrPriority(T Elem){
	//if (Elem.first < this->Contains(Elem)) {
	//}
	//Insert(Elem);
	unsigned int tmp = this->Contains(Elem);
	if (Elem.first < tmp || !tmp || this->empty()) {
		this->Insert(Elem);
	}
}

// Get the size
template<class T, class S > 
unsigned int PriorityQueue<T, S> :: Size(){
	return this->size();
}

// Get the top of the queue (the smallest/greatest element depending on S template)
template<class T, class S > 
T PriorityQueue<T, S> :: Top(){
	return this->top();
}

// Pop first element
template<class T, class S > 
void PriorityQueue<T, S> :: PickMinPriority(){
	this->pop();
	NumElements--;
}

// Check if the Queue is empty
template<class T, class S > 
bool PriorityQueue<T, S> :: Empty() const{
	//Queue.empty();
	this->empty();
}

// Workaround to iterate on a list.
// Check if a certain element is present (compare the key)
template<class T, class S > 
unsigned int PriorityQueue<T, S> :: Contains(T queue_element){
	PriorityQueue<T, S>  temp = *this;
	while(!temp.empty()){
		if (temp.top().second == queue_element.second) {
			return temp.top().first;	
		}
		temp.pop();
	}
	return 0;
}

// All the PriorityQueue elements are pairs (value and key)
template class PriorityQueue<pair<unsigned int, unsigned int>, greater<pair<unsigned int, unsigned int> > >;

template class PriorityQueue<pair<unsigned int, unsigned int>, less<pair<unsigned int, unsigned int> > >;

template class PriorityQueue<pair<unsigned int, pair<unsigned int, unsigned int> >, greater<pair<unsigned int, pair<unsigned int, unsigned int> > > >;

template class PriorityQueue<pair<unsigned int, pair<unsigned int, unsigned int> >, less<pair<unsigned int, pair<unsigned int, unsigned int> > > >;

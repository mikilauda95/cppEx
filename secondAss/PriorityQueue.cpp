#include "PriorityQueue.h"
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

template<class T>
PriorityQueue<T> :: PriorityQueue() : NumElements(0){
	
}

template<class T>
PriorityQueue<T> :: ~PriorityQueue(){

}

// Workaround to iterate on a list.
template<class T>
void PriorityQueue<T> :: PrintQueue(){
	priority_queue<T, vector<T>, greater<T> > temp;
	temp = Queue;
	while(!temp.empty()){
		cout << temp.top().first << " " << temp.top().second << " " << endl;
		temp.pop();
	}
}


template<class T>
void PriorityQueue<T> :: Insert(T QueueElem){
	T tmp(QueueElem);
	Queue.push(tmp);
	NumElements ++;
}

template<class T>
void PriorityQueue<T> :: DecrPriority(T Elem){
	Insert(Elem);
}

template<class T>
unsigned int PriorityQueue<T> :: Size(){
	return Queue.size();
}

template<class T>
T PriorityQueue<T> :: Top(){
	return Queue.top();
}

template<class T>
void PriorityQueue<T> :: PickMinPriority(){
	Queue.pop();
	NumElements--;
}


// Workaround to iterate on a list.
template<class T>
bool PriorityQueue<T> :: Contains(T queue_element){
	std::priority_queue<T, vector<T>, greater<T> > temp = Queue;
	while(!temp.empty()){
		if (temp.top().second == queue_element) {
			return true;	
		}
		temp.pop();
	}
	return false;
}


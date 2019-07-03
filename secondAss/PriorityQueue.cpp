#include "PriorityQueue.h"
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

PriorityQueue :: PriorityQueue() : NumElements(0){
	
}

PriorityQueue :: ~PriorityQueue(){

}

// Workaround to iterate on a list.
void PriorityQueue :: PrintQueue(){
	priority_queue<pairtype, vector<pairtype>, greater<pairtype> > temp;
	temp = Queue;
	while(!temp.empty()){
		cout << temp.top().first << " " << temp.top().second << " " << endl;
		temp.pop();
	}
}


void PriorityQueue :: Insert(unsigned int Priority, unsigned int QueueElem){
	pairtype tmp(Priority, QueueElem);
	Queue.push(tmp);
	NumElements ++;
}

void PriorityQueue :: DecrPriority(unsigned int QueueElem, unsigned int Priority){
	Insert(QueueElem, Priority);
}

unsigned int PriorityQueue :: Size(){
	return Queue.size();
}

pairtype PriorityQueue :: Top(){
	return Queue.top();
}

void PriorityQueue :: PickMinPriority(){
	Queue.pop();
	NumElements--;
}


// Workaround to iterate on a list.
bool PriorityQueue :: Contains(unsigned int queue_element){
	std::priority_queue<pairtype, vector<pairtype>, greater<pairtype> > temp = Queue;
	while(!temp.empty()){
		if (temp.top().second == queue_element) {
			return true;	
		}
		temp.pop();
	}
	return false;
}


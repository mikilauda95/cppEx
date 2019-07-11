#include "Mypair.h"
#include "PriorityQueue.h"
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

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


template<class T, class S > 
void PriorityQueue<T, S> :: Insert(T QueueElem){
	//T tmp(QueueElem);
	//Queue.push(tmp);
	//NumElements ++;
	T tmp(QueueElem);
	this->push(tmp);
	NumElements ++;
}

template<class T, class S >
bool PriorityQueue<T, S > :: Remove(T QueueElem){
	//std :: vector<double> :: iterator it = std::find(this->c.begin(), this->c.end(), QueueElem);
	//for (int i = 0; i < this->c.size(); ++i) {
		//if (this->c[i] == QueueElem) {
			//this->c.erase(i);
		//}
	//}
	//return false;

	//if (it != this->c.end()) {
		//this->c.erase(it);
		//std::make_heap(this->c.begin(), this->c.end(), this->comp);
		//return true;
	//}
	//else {
		//return false;
	//}
}

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

template<class T, class S > 
unsigned int PriorityQueue<T, S> :: Size(){
	return this->size();
}

template<class T, class S > 
T PriorityQueue<T, S> :: Top(){
	//return Queue.top();
	return this->top();
}

template<class T, class S > 
void PriorityQueue<T, S> :: PickMinPriority(){
	//Queue.pop();
	this->pop();
	NumElements--;
}

template<class T, class S > 
bool PriorityQueue<T, S> :: Empty() const{
	//Queue.empty();
	this->empty();
}

// Workaround to iterate on a list.
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

template class PriorityQueue<pair<unsigned int, unsigned int>, greater<pair<unsigned int, unsigned int> > >;

template class PriorityQueue<pair<unsigned int, unsigned int>, less<pair<unsigned int, unsigned int> > >;

template class PriorityQueue<pair<unsigned int, pair<unsigned int, unsigned int> >, greater<pair<unsigned int, pair<unsigned int, unsigned int> > > >;

template class PriorityQueue<pair<unsigned int, pair<unsigned int, unsigned int> >, less<pair<unsigned int, pair<unsigned int, unsigned int> > > >;

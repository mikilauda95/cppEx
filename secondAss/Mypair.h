#ifndef MYPAIR_H
#define MYPAIR_H
#include <iostream>
using namespace std;

// Previous implementation. Too complex to inherit a class for adding only a member funct
//template<class T>
//class Mypair : public T
//{
//private:
	

//public:
	//Mypair();
	//virtual ~Mypair();

//};

//template <class T>
//ostream& operator<<(ostream& s, const Mypair<T>& p);

typedef pair<unsigned int, unsigned int> Mypair;

ostream& operator<<(ostream& s, const Mypair& p){
	return s << "(" << p.first << ", " << p.second << ")";
}

typedef pair<unsigned int, Mypair> Mypair2;

#endif /* MYPAIR_H */

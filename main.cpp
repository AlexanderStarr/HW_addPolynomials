#include <iostream>
using namespace std;

struct Term;

template <class T>
struct Node {
	T data;
	Node<T> * next;
};

struct Term {
	float coef;
	int exp;
public:
	Term (float co, int ex) {coef = co; exp = ex;};
	Term (){}; // Must have a default constructor
	bool operator== (Term te);
	friend ostream& operator<< (ostream& os, Term& te);
};

bool Term:: operator== (Term te) {
	if (exp == te.exp) return true;
	else return false;
}

ostream& operator<< (ostream& os, Term& te) {
	os<<te.coef<<"x^"<<te.exp;
	return os;
}

template <class T>
class Poly {
	Node<T> * head_ptr;
public:
	
};

int main () 
{
	Term myTerm1 = Term(4, 5);
	Term myTerm2 = Term(5, 5);
	Node <Term> myNode1;
	Node <Term> myNode2;
	myNode1.next = &myNode2;
	return 0;
}

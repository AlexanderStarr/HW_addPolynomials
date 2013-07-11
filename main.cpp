#include <iostream>
using namespace std;

struct Node;
struct Term;

template <class T>
struct Node {
	Node(){};
	T data;
	Node * next;
};

struct Term {
	float co;
	int ex;
public:
	Term (float co, int ex) {this->co = co; this->ex = ex;};
	Term (){}; // Must have a default constructor
	bool operator== (Term te);
	friend ostream& operator<< (ostream& os, Term& te);
};

bool Term:: operator== (Term te) {
	if (co == te.co && ex == te.ex) return true;
	else return false;
}

ostream& operator<< (ostream& os, Term& te) {
	os<<te.co<<"x^"<<te.ex;
	return os;
}

int main () 
{
	return 0;
}

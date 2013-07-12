#include <iostream>
using namespace std;

struct Term;

// ========== Node ========== //
template <class T>
struct Node {
	T data;
	Node<T> * next;
};

// ========== Term ========== //
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

// ========== Poly ========== //
template <class T>
class Poly {
	Node<T> * head_ptr;
public:
	Poly<T>(){};
	Poly<T>(Node<T> head_node) {head_ptr = &head_node;};
};

// ========== main ========== //
int main () 
{
	Term t1 = Term(1, 2);
	Node<Term> n1;
	n1.data = t1;
	Poly<Term> p1 = Poly<Term>(n1);
	return 0;
}

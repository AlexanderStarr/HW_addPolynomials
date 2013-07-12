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
	void operator+ (Term te);
	friend ostream& operator<< (ostream& os, Term& te);
};

bool Term:: operator== (Term te) {
	if (exp == te.exp) return true;
	else return false;
}

void Term:: operator+ (Term te) {
	coef += te.coef;
}

ostream& operator<< (ostream& os, Term& te) {
	os<<te.coef<<"x^"<<te.exp;
	return os;
}

// ========== Poly ========== //
class Poly {
	Node<Term> * head_ptr;
	Node<Term> * tail_ptr;
public:
	Poly(){};
	Poly(float coef, int exp);
	void print();
	void addNode(float coef, int exp);
};

Poly::Poly(float coef, int exp) {
	Term * first_term = new Term(coef, exp);
	Node<Term> * head_node = new Node<Term>;
	head_node->data = *first_term;
	head_ptr = head_node;
	tail_ptr = head_node;
};

void Poly::print() {
	Node<Term> * ptr = head_ptr;
	while (ptr) {
		Node<Term> node = *ptr;
		cout << (node.data) << " + ";
		ptr = node.next;
	}
};

void Poly::addNode(float coef, int exp) {
	Term * new_term = new Term(coef, exp);
	Node<Term> * new_node = new Node<Term>;
	new_node->data = *new_term;
	tail_ptr->next = new_node;
	tail_ptr = new_node;
};

// ========== main ========== //
int main () 
{
	/*Poly * p1 = new Poly(2.5, 3);
	Poly myPoly1 =  *p1;
	myPoly1.addNode(1.5, 2);
	myPoly1.addNode(1, 1);
	myPoly1.addNode(1, 0);
	Poly * p2 = new Poly(0.5, 3);
	Poly myPoly2 = *p2;
	myPoly2.addNode(0.5, 2);
	myPoly2.addNode(0, 1);
	myPoly1.print();
	cout << endl;
	myPoly2.print();*/
	Term * t1 = new Term(2, 2);
	Term * t2 = new Term(110, 2);
	cout << *t1 << " " << *t2 << endl;
	*t1 + *t2;
	cout << *t1 << endl;
	return 0;
}

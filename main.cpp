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
	void addNode(Node<Term> * new_node);
	void insertNode(Node<Term> * predecessor, Node<Term> * new_node);
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

void Poly::addNode(Node<Term> * new_node) {
	tail_ptr->next = new_node;
	tail_ptr = new_node;
};

void Poly::insertNode(Node<Term> * predecessor, Node<Term> * new_node) {
	new_node->next = predecessor->next;
	predecessor->next = new_node;
	delete new_node;
}

// ========== main ========== //
int main () 
{
	Poly * p1 = new Poly(2.5, 3);
	Poly myPoly1 =  *p1;
	Term * t1 = new Term(1,4);
	Term * t2 = new Term(2,2);
	Term * t3 = new Term(2,3);
	Node<Term> * n1 = new Node<Term>;
	Node<Term> * n2 = new Node<Term>;
	Node<Term> * n3 = new Node<Term>;
	n1->data = *t1;
	n2->data = *t2;
	n3->data = *t3;
	myPoly1.addNode(n1);
	myPoly1.addNode(n2);
	myPoly1.insertNode(n1, n3);
	myPoly1.print();
	return 0;
}

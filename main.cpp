#include <iostream>
using namespace std;

struct Term;

// ========== Node ========== //
template <class T>
struct Node {
	T data;
	Node * next;
};

// ========== Term ========== //
struct Term {
	float coef;
	int exp;
	Term (float co, int ex) {coef = co; exp = ex;};
	Term (){}; // Must have a default constructor
	bool operator== (Term te);
	bool operator> (Term te);
	void operator+ (Term te);
	friend ostream& operator<< (ostream& os, Term& te);
};

bool Term:: operator== (Term te) {
	if (exp == te.exp) return true;
	else return false;
}

bool Term:: operator> (Term te) {
	if (exp > te.exp) return true;
	else return false;
}

void Term:: operator+ (Term te) {
	coef += te.coef;
}

ostream& operator<< (ostream& os, Term& te) {
	os<<te.coef<<"x^"<<te.exp;
	return os;
}

// ========== LinkedList ========== //
template <class T>
class LinkedList {
	Node<T> * head;
	int size;
public:
	LinkedList() : head(NULL), size(0) {};
	~LinkedList();
	void printList();
	void printNode(Node<T> * pntr);
	void reverseList();
	bool addNode(T data);
	bool deleteNode(T data);
	Node<T> * searchNode(T data);
	Node<T> * returnHead() {return head;};
};

template <class T>
LinkedList<T>::~LinkedList(){
	Node<T> * tmp = NULL;
	while (head) {
		tmp = head;
		head = tmp->next;
		delete(tmp);
	}
}

template <class T>
void LinkedList<T>::printList() {
	Node<T> * tmp = head;
	while (tmp) {
		cout << tmp->data;
		tmp = tmp->next;
		if (tmp) {
			cout << " + ";
		}
	}
};

template <class T>
void LinkedList<T>::printNode(Node<T> * pntr) {
	cout << pntr->data;
}

template <class T>
void LinkedList<T>::reverseList() {
	Node<T> *curr = head, *prev = head, *save = NULL;
	while (curr) {
		save = curr->next;
		curr->next = prev;
		prev = curr;
		curr = save;
	}
	head->next = NULL;
	head = prev;
};

template <class T>
bool LinkedList<T>::addNode(T data) {
	try {
		Node<T> * tmp = new Node<T>();
		tmp->data = data;
		tmp->next = head;
		head = tmp;
		++size;
		return true;
	} catch (exception & ex) {
		return false;
	}
};

template <class T>
bool LinkedList<T>::deleteNode(T data) {
	Node<T> *curr = head, *prev = NULL;
	while (curr) {
		if (curr->data == data) {
			break;
		}
		prev = curr;
		curr = prev->next;
	}
	if (curr) {
		if (prev) {
			prev->next = curr->next;
		}
		else {
			head = curr->next;
		}
		delete(curr);
		--size;
	}
	else {
		return false;
	}
};

template <class T>
Node<T> * LinkedList<T>::searchNode(T data) {
	Node<T> * tmp = head;
	while (tmp) {
		if (tmp->data == data) {
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}

// ========== Poly ========== //
class Poly {
	LinkedList<Term> termList;
public:
	void addTerm(float coeff, int exp);
	Poly * &operator+ (Poly& p);
	void print();
};

void Poly::addTerm(float coeff, int exp){
	Term t(coeff, exp);
	Term * search = &(termList.searchNode(t)->data);
	if (search) {
		*search + t;
	}
	else {
		termList.addNode(t);
	}
};

Poly * &Poly::operator+ (Poly& p) {
	Node<Term> * tmp = p.termList.returnHead();
	while (tmp) {
		addTerm(tmp->data.coef, tmp->data.exp);
		tmp = tmp->next;
	}
};

void Poly::print() {
	termList.printList();
}

// ========== main ========== //
int main () 
{
	Poly p1;
	p1.addTerm(10, 0);
	p1.addTerm(5, 2);
	p1.addTerm(7, 2);
	p1.print();
	cout << endl;
	Poly p2;
	p2.addTerm(1, 1);
	p2.addTerm(2, 2);
	p2.addTerm(3, 3);
	p2.print();
	p1+p2;
	cout << endl;
	p1.print();
	return 0;
}

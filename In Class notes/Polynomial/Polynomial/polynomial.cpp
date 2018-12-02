//Matthew Avallone
//Using Linked List to work with polynomials
//akx^k +...+ a2x^2 + a1^x +a0
//expressions starting with lowest degree polynomialm at front

#include "polynomial.h"
#include <iostream>
#include <string>
#include <vector>
#include "Math.h"
using namespace std;

namespace poly{
	Node::Node(int data, Node* next = nullptr) : data(data), next(next) {}

	void listInsertHead(Node*& headPtr, int data) { //inserts node at beginning of list, ***must be by reference***
		headPtr = new Node(data, headPtr);
	}

	int listSize(Node* headPtr) {
		int count = 0;
		Node* p = headPtr;
		while (p != nullptr) { //p->next != nullptr while not the last node IS WRONG (skips last node)
			++count;
			p = p->next;
		}
		return count;
	}

	Node* listFindTail(Node* headPtr) {
		if (headPtr == nullptr) { //checks in case headPtr does not exist
			return nullptr;
		}

		Node* p = headPtr;
		while (p->next != nullptr) {
			p = p->next;
		}
		return p; //now it returns the last node 

	}

	void listInsertTail(Node*& headPtr, int data) {
		if (headPtr == nullptr) {
			headPtr = new Node(data);
		}
		else {
			//find the tail/find last node
			Node* last = listFindTail(headPtr);
			//tack on a new node for last node's data
			last->next = new Node(data);
		}
	}

	void listRemoveTail(Node*& headPtr) {
		if (headPtr == nullptr) return;

		if (headPtr->next == nullptr) {
			delete headPtr;
			headPtr = nullptr;
		}

		Node* p = headPtr;
		while (p->next->next != nullptr) {
			p = p->next;
		}
		delete p->next;
		p->next = nullptr;
	}

	Node* listCopy(Node* headPtr) {
		if (headPtr == nullptr) return nullptr;

		Node* targetHead = new Node(headPtr->data);
		Node* p = headPtr->next;
		Node* last = targetHead;

		while (p) { 
			last->next = new Node(p->data);
			last = last->next;
			p = p->next;
		}
		return targetHead;
	}

		/*

		END OF IMPLEMENTATION OF NODE FUNCTIONS

		*/

	Polynomial::Polynomial(const vector<int>& expression) {
		head = new Node(expression[0]); //creates the head pointer
		for (int i = 1; i < expression.size(); ++i) {
			listInsertTail(head, expression[i]); //adds to the end of the linked list
		}
	}

	//Implementation of Copy Control
	Polynomial::Polynomial(const Polynomial& rhs) {
		head = listCopy(rhs.head);
	}

	Polynomial::~Polynomial() {
		Node* p = head;
		while (p) {
			Node *temp = p->next;
			delete p;
			p = temp;
		}
	}

	Polynomial& Polynomial::operator=(const Polynomial& rhs) {
		Node* p = head;
			while (p) {
			Node *temp = p->next;
			delete p;
			p = temp;
		}
		head = listCopy(rhs.head); //sets this head equal to a copy of rhs head
		return *this;
	}

	//Implementation of Arithmetic opterator method
	Polynomial& Polynomial::operator+=(const Polynomial& rhs) {	
		Node* p = head; //walker
		Node* q = rhs.head; //walker
		if (listSize(head) >= listSize(rhs.head)) {
			while (q) {
				p->data += q->data; //adds the coefficient stored in rhs data into this data for variables of same degree
				p = p->next;
				q = q->next;
			}
		}
		else {
			while (p) {
				p->data += q->data; //adds the coefficient stored in rhs data into this data for variables of same degree
				p = p->next;
				q = q->next;
			}
		}

		return *this;
	}

	Polynomial operator+(Polynomial& lhs, const Polynomial& rhs) { //relies on the += operator to work
		Polynomial temp = lhs;
		temp += rhs;
		return temp;
	}

	double Polynomial::evaluate(int x) {
		if (head == nullptr) return 0; //checks if 0 polynomial

		Node* p = head;
		int maxDegree = listSize(head) - 1;
		double result = 0;
		for (int i = 0; i <= maxDegree; ++i) {
			result += pow(x, i) * (p->data); //uses Math class pow function to perform x^n
			p = p->next;
		}
		return result;
	}

	//Implementation of friend operators
	ostream& operator<<(ostream& os, const Polynomial& expression) {
		if (listSize(expression.head) == 1 && expression.head->data == 0) {
			os << "0" << endl;
			return os;
		}
		else if (listSize(expression.head) == 1 && expression.head->data != 0){
			os << expression.head->data << endl;
			return os;
		}

		int maxDegree = listSize(expression.head) - 1;
		if (maxDegree >= 2) {
			Node* p = expression.head->next->next;
			os << expression.head->data << showpos << expression.head->next->data << noshowpos << "x";
			for (int degree = 2; degree <= maxDegree; ++degree) {
				if(p->data != 0)
					os << showpos << p->data << "x^" << noshowpos << degree;
				p = p->next;
			}
			os << endl;
			return os;
		}
		else if(maxDegree == 1){
			if (expression.head->data != 0 && expression.head->next->data == 0) { //checks if constant is not zero
				os << expression.head->data;
			}

			if (expression.head->next->data != 0 && expression.head->data == 0) { //checks if x variable is not zero
				os << expression.head->next->data << "x" << noshowpos << endl;
			}

			if (expression.head->data == 0 && expression.head->next->data == 0) //checks if both are zero
				os << "0" << endl;
			else if(expression.head->data != 0 && expression.head->next->data != 0)
				os << expression.head->data << showpos << expression.head->next->data << "x" << noshowpos << endl;

			return os;
		}
	}


	bool operator==(const Polynomial& lhs, const Polynomial& rhs) {
		Node* lhsWalker = lhs.head;
		Node* rhsWalker = rhs.head;
		if (listSize(lhsWalker) == listSize(rhsWalker)) {
			while (lhsWalker) {
				if (lhsWalker->data == rhsWalker->data) { //checks the coefficient value at each position
					lhsWalker = lhsWalker->next;
					rhsWalker = rhsWalker->next;
				}
				else
					return false;
			}
			return true;
		}
		return false;
	}
	
	bool operator!=(const Polynomial& lhs, const Polynomial& rhs) {
		return !(lhs == rhs);
	}
}

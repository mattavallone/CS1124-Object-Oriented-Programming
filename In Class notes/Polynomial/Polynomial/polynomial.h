#ifndef POLY_H
#define POLY_H
#include <iostream>
#include <vector>
#pragma once
namespace poly {
	struct Node {
		Node(int data, Node* next);
		int data;
		Node* next;
	};

	void listInsertHead(Node*& headPtr, int data);
	Node* listCopy(Node* headPtr);

	class Polynomial {
	public:
		friend std::ostream& operator<<(std::ostream& os, const Polynomial& expression);
		friend bool operator==(const Polynomial& lhs, const Polynomial& rhs);

		Polynomial(const std::vector<int>& expression = { 0 });

		//Copy Control
		Polynomial(const Polynomial& rhs);
		~Polynomial();
		Polynomial& operator=(const Polynomial& rhs);
		Polynomial& operator+=(const Polynomial& rhs); 
		double evaluate(int x);
	private:
		Node* head = nullptr;
	};

	Polynomial operator+(Polynomial& lhs, const Polynomial& rhs);

	bool operator!=(const Polynomial& lhs, const Polynomial& rhs); //will use operator==

}

#endif
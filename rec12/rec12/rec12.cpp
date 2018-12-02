//Matthew Avallone
//section C
//rec12
\
#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
	Node(int data, Node* link = nullptr) : data(data), next(link) {}
	int data;
	Node* next;
};

void displayList(Node* headPtr) {
	Node* bump = headPtr;
	while (bump != nullptr) {
		cout << bump->data << " ";
		bump = bump->next;
	}
	cout << endl;
}

void listInsertHead(int entry, Node*& headPtr) {
	headPtr = new Node(entry, headPtr);
}

int size(Node* headPtr) {
	int counter = 0;
	Node* p = headPtr;
	while (p != nullptr) {
		++counter;
		p = p->next;
	}
	return counter;
}

void splice(Node* base, Node* splicer, Node* targetLocation) {
	Node* targetFinder = base;
	while (targetFinder != nullptr) { //loops through L1
		if (targetFinder->data == targetLocation->data) { //checks data in L1 compared to target data at first node
			Node* endSplicerLocation = targetFinder->next; //tracks location of values after first node in target
			targetFinder->next = splicer; //sets the next value after the target value in L1 to be the headPtr in L2
			Node* endSplicerFinder = splicer; 
			while(endSplicerFinder->next != nullptr) { //loops until it finds the last node in L2
				endSplicerFinder = endSplicerFinder->next; 
			}
			while (targetFinder != nullptr) { //loops again in L1 until it reaches the last node
				if (targetFinder->data == endSplicerFinder->data) { //checks to make sure data in L1 equals the last node in L2 (splicer List)
					targetFinder->next = endSplicerLocation; //inserts nodes from after the target headPtr location in L1 back to the end of new L1
				}
				targetFinder = targetFinder->next;
			}
			endSplicerFinder->next = endSplicerLocation; //places the nodes from after the target headPtr into the end of L2
			return;
		}
		targetFinder = targetFinder->next;
	}
}

Node* isSubList(Node* base, Node* subList) {
	if (size(base) < size(subList)) return nullptr; //makes sure that sublist can possibly be inside base list
	if (base == nullptr) return nullptr; //makes sure base list exists
	if (base->next == nullptr && base->data == subList->data) return base; //checks if base list has only one node
	
	Node* subListHeadFinder = base;
	Node* sub = subList;
	while (subListHeadFinder != nullptr) { //loops until it finds start of matching lists
		if (subListHeadFinder->data == sub->data) {
			Node* start = subListHeadFinder;
			subListHeadFinder = subListHeadFinder->next;
			sub = sub->next;
			while(sub != nullptr){
				if (subListHeadFinder->data == sub->data) {
					subListHeadFinder = sub->next;
					sub = sub = sub->next;
				}
				else return nullptr;
			}
			return start;
		}
		else
			subListHeadFinder = subListHeadFinder->next;
	}
}

int main() {
	Node* L1 = new Node(5);
	L1->next = new Node(7);
	L1->next->next = new Node(9);
	L1->next->next->next = new Node(1);
	cout << "L1: ";
	displayList(L1);
	
	Node* L2 = new Node(6);
	L2->next = new Node(2);
	L2->next->next = new Node(3);
	cout << "L2: ";
	displayList(L2);

	Node* target = new Node(7);
	target->next = new Node(9);
	target->next->next = new Node(1);
	cout << "Target: ";
	displayList(target);

	cout << "Splicing L2 at target in L1" << endl;
	splice(L1, L2, target);
	cout << "L1: ";
	displayList(L1);
	cout << "L2: ";
	displayList(L2);

	cout << "===========" << endl;
	
	Node* targetMatch = new Node(6);
	listInsertHead(5, targetMatch);
	listInsertHead(4, targetMatch);
	listInsertHead(2, targetMatch);
	listInsertHead(3, targetMatch);
	listInsertHead(2, targetMatch);
	listInsertHead(3, targetMatch);
	listInsertHead(2, targetMatch);
	listInsertHead(1, targetMatch);
	cout << "Target: ";
	displayList(targetMatch);

	Node* matchTest1 = new Node(1);
	cout << "Attempt Match: "; 
	displayList(matchTest1);
	if (isSubList(targetMatch, matchTest1) != nullptr) {
		displayList(isSubList(targetMatch, matchTest1));
	}
	else {
		cout << "Failed to match" << endl;
	}

	Node* matchTest2 = new Node(3);
	matchTest2->next = new Node(9);
	cout << "Attempt Match: ";
	displayList(matchTest2);
	if (isSubList(targetMatch, matchTest2) != nullptr) {
		displayList(isSubList(targetMatch, matchTest2));
	}
	else {
		cout << "Failed to match" << endl;
	}

	Node* matchTest3 = new Node(2);
	matchTest3->next = new Node(3);
	cout << "Attempt Match: ";
	displayList(matchTest3);
	if (isSubList(targetMatch, matchTest3) != nullptr) {
		displayList(isSubList(targetMatch, matchTest3));
	}
	else {
		cout << "Failed to match" << endl;
	}

	Node* matchTest4 = new Node(2);
	matchTest4->next = new Node(4);
	matchTest4->next->next = new Node(5);
	matchTest4->next->next->next = new Node(6);
	cout << "Attempt Match: ";
	displayList(matchTest4);
	if (isSubList(targetMatch, matchTest4) != nullptr) {
		displayList(isSubList(targetMatch, matchTest4));
	}
	else {
		cout << "Failed to match" << endl;
	}

	Node* matchTest5 = new Node(2);
	matchTest5->next = new Node(3);
	matchTest5->next->next = new Node(2);
	matchTest5->next->next->next = new Node(4);
	cout << "Attempt Match: ";
	displayList(matchTest5);
	if (isSubList(targetMatch, matchTest5) != nullptr) {
		displayList(isSubList(targetMatch, matchTest5));
	}
	else {
		cout << "Failed to match" << endl;
	}

	Node* matchTest6 = new Node(5);
	matchTest6->next = new Node(6);
	matchTest6->next->next = new Node(7);
	cout << "Attempt Match: ";
	displayList(matchTest6);
	if (isSubList(targetMatch, matchTest6) != nullptr) {
		displayList(isSubList(targetMatch, matchTest6));
	}
	else {
		cout << "Failed to match" << endl;
	}
}
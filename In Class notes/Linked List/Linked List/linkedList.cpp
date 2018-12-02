//11/16/15
#include <iostream>
using namespace std;

struct Node {
	Node(int data, Node* next = nullptr) : data(data), next(next){}
	int data;
	Node* next;
};

void listInsertHead(Node*& headPtr, int data) { //inserts node at beginning of list, ***must be by reference***
	headPtr = new Node(data, headPtr);
}

void listDisplay(Node* headPtr) {
	Node* p = headPtr;
	while (p != nullptr) { //until there's no node to display
		cout << p->data << ' ';
		p = p->next; //bump pointer to next node
	}
	cout << endl;
}

void listDisplayReverse(Node* headPtr) {
	if (headPtr == nullptr) return;

	listDisplayReverse(headPtr->next);
	cout << headPtr->data << endl;
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
	
	/*
	Node* p = headPtr;
	while (p != nullptr) {
		p = p->next;
	}
	return p; //P WOULD ALWAYS BE NULLPTR WHICH IS BAD
	*/

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

//void listInsert(Node* after) DOESN'T WORK WITH ONLY ONE POINTER (only contains next)
//The parameter before is not permitted to be nullptr
void listInsert(Node* before, int data) {
		//Node* after = before->next;
		//before->next = new Node(data, after);
		//OR
		before->next = new Node(data, before->next);
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

void listRemoveHead(Node*& headPtr) {
	if (headPtr == nullptr) return;
	Node* head = headPtr->next;
	delete headPtr;
	headPtr = nullptr;
}

//must not pass in nullptr for prior
void listRemoveAfter(Node* prior) {
	Node* after = prior->next->next;
	delete prior->next;
	prior->next = after;
}

Node* listCopy(Node* headPtr) {
	if (headPtr == nullptr) return nullptr;

	Node* targetHead = new Node(headPtr->data);
	Node* p = headPtr->next;
	Node* last = targetHead;

	//while (p != nullptr) { //while p exists
	while(p) { //nullptr is the only "false" address
		last->next = new Node(p->data);
		last = last->next;
		p = p->next;
	}
	return targetHead;
}


Node* listCopy2(Node* headPtr) {
	Node* targetHead = nullptr;
	Node* p = headPtr;
	while (p) { //nullptr is the only "false" address
		listInsertTail(targetHead, p->data);
		p = p->next;
	}
	return targetHead;
}

Node* listCopy3(Node* headPtr) { //recursion
	if (headPtr == nullptr) return nullptr; //base case
	return new Node(headPtr->data, listCopy3(headPtr->next)); //recursive call
}

int main() {
	Node* list = nullptr;
	listInsertHead(list, 17);
	//cout << list << endl;
	//cout << list->data << endl;
	listDisplay(list);
	listSize(list);
	listInsertTail(list, 38);
	//list->next = new Node(38);
	listDisplay(list);
	listInsert(list->next, 679);
	listDisplay(list);
	//cout << list->data << " " << list->next->data << endl;
}

////////////////////////////////deque class does insertion at front and back of a collection
//Matthew Avallone
//recitation 13

#include <iostream>
using namespace std;

struct Node {
	Node(const int data, Node* next = nullptr) : data(data), next(next) {}
	int data;
	Node* next;
};

class list {
public:
	list(Node* h) : headptr(h), current(headptr), size(1) {}
	void reset() {
		current = headptr;
	}
	int data() const {
		return current->data;
	}
	void next() {
		if (current->next)
			current = current->next;
		else
			current = nullptr;
	}
	void clear() {
		Node* temp = headptr;
		while(temp) {
			Node* link = temp->next;
			delete temp;
			temp = link;
		}
		delete headptr;
		delete current;
		size = 0;
	}
	void add(Node* anotha) { //adding to end of the list
		reset();
		while (current->next) {
			current = current->next;
		}
		current->next = anotha;
		++size;
	}
	void display() {
		Node* temp = headptr;
		while (temp) {
			cout << temp->data;
			temp = temp->next;
		}
		cout << endl;
	}
private:
	Node* headptr;
	Node* current;
	int size;
};

/*
int main() {
	list l1 = { new Node(5)};
	l1.add(new Node(4));
	l1.add(new Node(3));
	l1.add(new Node(2));
	l1.add(new Node(1));
	l1.display();

	l1.reset();
	l1.next();
	cout << l1.data() << endl;

	
	try {
		l1.clear();
		cout << l1.data() << endl;
	}
	catch (...) {
		throw "whoops I did it again";
	}
}
*/

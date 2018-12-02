// Matthew Avallone
// Section C
// 12/4/15

#include <iostream>
using namespace std;

struct Node {
	Node(int data, Node* next = nullptr) : data(data), next(next) {}
	int data;
	Node* next;
};

void removeTail(Node*& head) {
	if (head == nullptr) return; //checks if head exists
	if (head->next == nullptr) { //checks if only one node in sequence
		delete head;
		head = nullptr;
	}

	Node* p = head;
	while (p->next->next != nullptr) { //finds second to last node
		p = p->next;
	}
	delete p->next; //deletes last node
	p->next = nullptr;
}


class Sequence {
public:
	Sequence(Node* headptr = nullptr, Node* current = nullptr) : headPtr(headPtr), current(current){}

	Sequence(Sequence& rhs) {
		if (rhs.headPtr != nullptr) {
			headPtr = new Node(rhs.headPtr->data);
			current = new Node(rhs.data());
			Node* p = rhs.headPtr->next;
			while (p) {
				add(p->data);
				p = p->next;
			}
		}
		cout << "Sequence(Sequence& rhs)\n";
	}

	Sequence& operator=(Sequence& rhs) {
		clear();
		if (rhs.headPtr != nullptr) {
			headPtr = new Node(rhs.headPtr->data);
			current = new Node(rhs.data());
			Node* p = rhs.headPtr->next;
			while (p) {
				add(p->data);
				p = p->next;
			}
		}
		cout << "Sequence& operator=(Sequence& rhs)\n";

		return *this;
	}

	void add(int dataAdded) {
		if (valid()) {
			current->next = new Node(dataAdded, current->next);
			current = current->next;
		}
		else {
			headPtr = new Node(dataAdded, headPtr);
			current = headPtr;
		}
	}
	
	void reset(){
		current = headPtr;
	}

	void remove() {
		if (valid()) {
			Node* p = current->next;
			Node* tracker = headPtr; 
			while (tracker->next != current) { //finds the node before the current
				tracker = tracker->next;
			}
			delete current; //removese current node
			current = tracker;
			current->next = p; //links new current node to address of the nodes after old current node
		}
	}

	int data() {
		if(valid())
			return current->data;
	}

	void next() {
		if (valid())
			current = current->next;
	}
	void display() {
		Node* p = headPtr;
		while (p != nullptr) { //until there's no node to display
			cout << p->data << ' ';
			p = p->next; //bump pointer to next node
		}
		cout << endl;
	}

	bool valid() {
		return current != nullptr;
	}

	void clear() {
		while (headPtr != nullptr) { //deletes the last node until none are left
			removeTail(headPtr);
			headPtr = headPtr->next;
		}
	}

	~Sequence() {
		clear();
		delete current;
		cout << "~Sequence()\n";
	}
private:
	Node* headPtr;
	Node* current;
};


int main() {
	Sequence s;
	for (int i = 0; i < 6; ++i) s.add(i);
	s.display();
	cout << "==========\n";
	s.reset();
	for (int i = 0; i < 3; ++i) s.next();
	s.add(42);
	s.display();
	cout << "==========\n";
	s.reset();
	for (int i = 0; i < 2; ++i) s.next();
	s.remove();
	s.display();
	cout << "==========\n";
	s.clear();
	s.display();
	cout << "==========\n";

	Sequence s2(s);
	s2.display();
	Sequence s3(new Node(5));
	s2 = s3;
}
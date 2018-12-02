//Matthew Avallone
//CS1124
//Sec C
//12/11/15

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

void displayBinary(int n) {
	if (n < 2) cout << n;
	else {
		displayBinary(n / 2);
		cout << n % 2;
	}
}

struct Node {
	Node(const int data, Node* next = nullptr) : data(data), next(next) {} 
	int data;
	Node* next;
};

int sumLists(Node* list1, Node* list2) {
	if (list1 == nullptr && list2 == nullptr) return 0;
	return list1->data + list2->data + sumLists(list1->next, list2->next);
}

struct TNode {
	TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
		: data(data), left(left), right(right) {}
	int data;
	TNode *left, *right;
};

int max(TNode* root) {
	if (root == nullptr) return -1;
	int maximum = root->data;
	if (root->left->data > maximum) {
		maximum = root->left->data;
		return max(root->left);
	}
	else if (root->right->data > maximum) {
		maximum = root->right->data;
		return max(root->right);
	}
	else
		return maximum;
}

int cStringSum(const char chars[], int length) {
	if (length == 0) return 0;
	return chars[length - 1] + cStringSum(chars, length - 1);
}

int binarySearch(const vector<int>& v, int target, int low, int high) {
	if (low > high) return -1;
	int mid = low + (high - low) / 2;
	if (target == v[mid]) return mid;
	else if (target < v[mid]) {
		return binarySearch(v, target, low, mid - 1);
	}
	else
		return binarySearch(v, target, mid + 1, high);	
}

void foo(int n) {
	if (n > 1) {
		cout << 'a';
		foo(n / 2);
		cout << 'b';
		foo(n / 2);
	}
	cout << 'c';
}

int main() {
	displayBinary(1738); //displays in binary form
	cout << endl;
	Node* L1 = new Node(2);
	L1->next = new Node(3);
	L1->next->next = new Node(4);
	Node* L2 = new Node(5, new Node(6, new Node(7)));
	cout << "Sum of lists: " << sumLists(L1, L2) << endl; //returns the sum of the 2 lists passed in
	TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
	cout << max(&f) << endl; //prints out the maximum value of a binary tree
	char charList[] = { 'a', 'b', 'c' };
	cout << "Sum of chars: " << cStringSum(charList, 3) << endl; //prints out sum of the ANSI values of a cstring
	vector<int> vi = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	cout << "Position: " << binarySearch(vi, 5, vi.front(), vi.back()) << endl; //outputs the index of the target if it exists
	foo(3);
	cout << endl;
}
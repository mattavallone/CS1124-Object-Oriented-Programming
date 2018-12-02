//Matthew Avallone
//12/7/15
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//Tree
struct TreeNode {
	int data;
	TreeNode* leftChild;
	TreeNode* rightChild;
	 TreeNode(int data, TreeNode* left = nullptr, TreeNode* right = nullptr) : data(data), leftChild(left), rightChild(right) {}
};

int treeSum(TreeNode* rootPtr) {
	if (rootPtr == nullptr) return 0;
	return rootPtr->data + treeSum(rootPtr->leftChild) + treeSum(rootPtr->rightChild);
}

int binarySearch(const vector<int>& v, int target, int low, int high) {
	if (high < low) return -1;
	int mid = low + (high - low) / 2;
	if (target == v[mid]) return mid;
	else if (target < v[mid]) {
		return binarySearch(v, target, low, mid - 1);
	}
	else if (target > v[mid]) {
		return binarySearch(v, target, mid + 1, high);
	}
}

int main() {
	TreeNode* root = new TreeNode(5);
	root->leftChild = new TreeNode(3);
	root->rightChild = new TreeNode(4);
	cout << treeSum(root) << endl;

	vector<int> vi = { 13, 5, 21, 2, 34, 55, 8 };
	sort(vi.begin(), vi.end());
	cout << binarySearch(vi, 17, 0, 7) << endl;
}
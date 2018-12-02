//Matthew Avallone

#include <algorithm>
#include <list>
#include <vector>
#include<iterator>
#include <iostream>
#include<string>
using namespace std;

typedef vector<int>::iterator vecIt;
template<typename T>
void print(T v){
	vecIt iter = v.begin();
	for (iter; iter < v.end(); iter++) {
		cout << *iter << endl;
	}
}

void first();
void second();

class IAmAnException{};

int main() {
	vector<int> vm{ 6,7,9,17,38 };
	print(vm);
	first();
}

void first() {
	cout << "Before\n";
	try {
		second();
	}
	catch (string s) {
		cout << "Caught a string: " << s << endl;
	}
	catch (int n) {
		if (n != 7)
			cout << "Caught an integer: " << n << endl;
		else
			throw; // pass exception "up" -- local objects get extended lifetime.
	}
	catch (IAmAnException()) {
		cout << "Caught an exception object\n";
	}
	catch (char s[]) {
		cout << "Caught a character array: " << s << endl;
	}
	catch (...) {}
	cout << "AFTER\n";
}

void second()
{
	int q;  // Consider the lifetimes of q.
	cin >> q;
	if (q == 0) return;
	else if (q == 1) throw 7;
	else if (q == 2) throw "I'm a message";
	else if (q == 3) throw 72.6;
	else if (q == 4) throw q;  // Now what happens to q...
	else if (q == 5) throw IAmAnException();
	else if (q == 6) throw 17;
}

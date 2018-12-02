//bounds check

#include <exception>
#include <iostream>
#include <vector>
#include <cassert> //for assertions
#include <stdexcept>

//#define NDEBUG //no debugging (makes assert "vanish")
using namespace std;

class myException : public exception {
public:
	myException(int n = 0) : val(n) { print(); }
	void print(){
		cout << val << endl;
	}
private:
	int val;
};

void bar(int n) {
	assert(n <= 200);
	if (n > 200) {
		//throw 3.141592; //throws an exception (can be anything including pi LOL)
		throw myException(n);
		cerr << "in the bar";
	}
	cerr << "escapec the bar";
}

int main(){

	bar(250);
	cerr << "after bar";
	try {
		vector<int> vc;
		vc.push_back(1);
		vc.at(17);
	}
	catch (...) {
		cout << "caught ya a dollar" << endl;
	}

	cerr << "Carry on my wayward son" << endl;
}
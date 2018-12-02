#include <iostream>
using namespace std;

class Vector {
public:
	Vector() : theSize(0), theCapacity(0), data(nullptr) {cerr << "Vector()\n";}
	Vector(const Vector& rhs) : theSize(rhs.theSize), theCapacity(rhs.theCapacity), data(new int[theCapacity]){
		for (size_t i = 0; i < theSize; i++) {
			data[i] = rhs.data[i];
		}

		cerr << "Vector(const Vector& rhs)\n";
	}

	explicit Vector(size_t cap) : theSize(cap), theCapacity(cap), data(new int[theCapacity]) {} //explicit in order to prevent v = aNumber;

	size_t size() const {
		return theSize;
	}

	int operator[](size_t index) const {
		return data[index];
	}
	Vector& operator=(const Vector& rhs) {
		if (this != &rhs) {
			delete[] data;
			theSize = rhs.theSize;
			theCapacity = rhs.theCapacity;
			data = new int[theCapacity];

			for (size_t i = 0; i < rhs.size(); i++) {
				data[i] = rhs.data[i];
			}
		}
		return *this;
	}

	int& operator[](size_t index) {
		return data[index];
	}

	void push_back(int val) {
		if (theSize == theCapacity) {
			//increase the capacity
			int newCapacity = 0;
			newCapacity = newCapacity * 2 + 1;
			int* newData = new int[newCapacity];
			for (size_t i = 0; i < theSize; i++) {
				newData[i] = data[i];
			}
			delete [] data;
			data = newData;
			theCapacity = newCapacity;
		}
		data[theSize] = val;
		++theSize;
	}

	void clear() {
		theSize = 0;
	}
	void pop_back() { 
		//if(theSize > 0) doubles time to pop_back()
		--theSize; 
	}

	size_t capacity() const { return theCapacity; }

	~Vector() {
		delete [] data;
	}
private:
	size_t theSize;
	size_t theCapacity;
	int* data;
};

int main() {
	Vector v;
	v.push_back(17);
	v.push_back(38);
	v.push_back(6);
	v.push_back(7);
	v.push_back(9);

	for (size_t i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

	Vector v2;

	v2 = v;

	v2[0] = 100;

	for (size_t i = 0; i < v2.size(); i++) {
		cout << v2[i] << endl;
	}
}
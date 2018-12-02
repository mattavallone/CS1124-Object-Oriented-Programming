/*
Recitation 10
CS1124

Focus: Copy Control.  Uses dynamic array of pointers.
*/

#include <string>
#include <iostream>
using namespace std;

class Position {
public:
	Position(const string& aTitle, double aSalary)
		: title(aTitle), salary(aSalary) {}
	string getTitle() const { return title; }
	double getSalary() const { return salary; }
	void changeSalaryTo(double d) { salary = d; }
private:
	string title;
	double salary;
}; // class Position

class Entry {
public:
	Entry(const string& aName, unsigned aRoom, unsigned aPhone,
		Position& aPosition)
		: name(aName), room(aRoom), phone(aPhone), pos(&aPosition) {
	}
	friend ostream& operator<<(ostream& os, const Entry& e) {
		os << e.name << ' ' << e.room << ' ' << e.phone;
		return os;
	} // operator<<

	string getName() const {
		return name;
	}
	unsigned getNumber() const {
		return phone;
	}
private:
	string name;
	unsigned room;
	unsigned phone;
	Position* pos;
}; // class Entry

class Directory {
public:
	friend ostream & operator<<(ostream& os, const Directory& rhs);
	Directory()
		: capacity(2), size(0), entries(new Entry*[2])
	{
		// Should we do this?  What do you think?
		for (size_t i = 0; i < capacity; i++) {
			entries[i] = nullptr;
		} // for
	} // Directory()

	Directory& operator=(const Directory& rhs) {
		cout << "operator=(const Directory& rhs)" << endl;
		if (this != &rhs) {
			delete[] entries;
			size = rhs.size;
			capacity = rhs.capacity;
			entries = new Entry*[capacity];

			for (size_t i = 0; i < rhs.size; i++) {
				Entry e = *rhs.entries[i];
				entries[i] = &e;
			}
		}
		return *this;
	}

	Directory(const Directory& rhs) : size(rhs.size), capacity(rhs.capacity) {
		cout << "Directory(const Directory& rhs)" << endl;
		entries = new Entry*[capacity];
		for (size_t i = 0; i < size; i++) {
			entries[i] = new Entry(*rhs.entries[i]);
			//Entry e = *rhs.entries[i];
			//entries[i] = &e;
		}
	}

	unsigned operator[](const string& name) {
		for (size_t i = 0; i < size; i++) {
			if (entries[i]->getName() == name) {
				return entries[i]->getNumber();
			}
		}
	}

	void add(const string& name, unsigned room, unsigned ph, Position& pos) {
		if (size == capacity) {
			int newCapacity = 0;
			newCapacity = newCapacity * 2 + 1;
			Entry** newEntries = new Entry*[newCapacity];
			for (size_t i = 0; i < size; i++) {
				newEntries[i] = entries[i];
			}
			delete[] entries;
			entries = newEntries;
			capacity = newCapacity;
		} // if
		entries[size] = new Entry(name, room, ph, pos);
		++size;
	} // add

	~Directory() {
		cout << "~Dictionary()" << endl;
		for (size_t i = 0; i < size; i++) {
			entries[i] = nullptr;
		}
		delete[] entries;
	}
private:
	Entry** entries;
	size_t size;
	size_t capacity;
}; // class Directory

ostream& operator<<(ostream& os, const Directory& rhs) {
	cout << "operator<<(ostream& os, const Directory& rhs)" << endl;
	cout << "Directory Entries: " << endl;
	for (size_t i = 0; i < rhs.size; i++) {
		os << *rhs.entries[i] << endl;
	}
	return os;
}

void doNothing(Directory dir) { cout << dir << endl; }

int main() {

	// Model as if there are these four kinds 
	// of position in the problem:
	Position boss("Boss", 3141.59);
	Position pointyHair("Pointy Hair", 271.83);
	Position techie("Techie", 14142.13);
	Position peon("Peonissimo", 34.79);

	// Create a Directory
	Directory d;
	d.add("Marilyn", 123, 4567, boss);
	cout << d << endl;
	

	Directory d2 = d;	// What function is being used??
	d2.add("Gallagher", 111, 2222, techie);
	d2.add("Carmack", 314, 1592, techie);
	cout << d2 << endl;
	cout << d2["Gallagher"] << endl;

	cout << "Calling doNothing\n";
	doNothing(d2);
	cout << "Back from doNothing\n";

	Directory d3;
	d3 = d2;

} // main
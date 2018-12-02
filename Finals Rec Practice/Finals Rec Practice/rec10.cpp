#include <string>
#include <iostream>
using namespace std;

class Position {
public:
	Position(const string& aTitle, double aSalary)
		: title(aTitle), salary(aSalary) {}
	Position(const Position& rhs) {
		title = rhs.title;
		salary = rhs.salary;
	}
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

	Entry(const Entry& rhs) {
		name = rhs.name;
		room = rhs.room;
		phone = rhs.phone;
		pos = new Position(*rhs.pos);
	}

	friend ostream& operator<<(ostream& os, const Entry& e) {
		os << e.name << ' ' << e.room << ' ' << e.phone;
		return os;
	} // operator<<
private:
	string name;
	unsigned room;
	unsigned phone;
	Position* pos;
}; // class Entry

class Directory {
	friend ostream& operator<<(ostream& os, const Directory& rhs);
public:
	Directory()
		: capacity(2), size(0), entries(new Entry*[2])
	{
		// Should we do this?  What do you think?
		for (size_t i = 0; i < capacity; i++) {
			entries[i] = nullptr;
		} // for
	} // Directory()

	Directory(const Directory& rhs) {
		size = rhs.size;
		capacity = rhs.capacity;
		for (size_t i = 0; i < rhs.size; i++) {
			entries[i] = new Entry(*rhs.entries[i]);
		}
	}

	Directory& operator=(const Directory& rhs) {
		if (this != &rhs) {
			delete[] entries;
			size_t count = 0;
			while (count < size) {
				entries[count] = nullptr;
				++count;
			}
			size = rhs.size;
			capacity = rhs.capacity;
			for (size_t i = 0; i < rhs.size; i++) {
				entries[i] = new Entry(*rhs.entries[i]);
			}
		}
		return *this;
	}

	void add(const string& name, unsigned room, unsigned ph, Position& pos) {
		if (size == capacity) {
			// something is missing!!!  Add it!

		} // if
		entries[size] = new Entry(name, room, ph, pos);
		++size;
	} // add

	~Directory() {
		delete[] entries;
		size_t count = 0;
		while(count < size){
			entries[count] = nullptr;
			++count;
		}
	}

private:
	Entry** entries;
	size_t size;
	size_t capacity;
}; // class Directory

ostream& operator<<(ostream& os, const Directory& rhs) {
	for (size_t i = 0; i < rhs.size; i++) {
		os << *rhs.entries[i] << endl;
	}
	return os;
}

void doNothing(Directory dir) { cout << dir << endl; }

/*
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

	cout << "Calling doNothing\n";
	doNothing(d2);
	cout << "Back from doNothing\n";

	Directory d3;
	d3 = d2;

} // main

*/

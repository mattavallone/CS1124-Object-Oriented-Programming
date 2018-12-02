//Matthew Avallone
//Inheritance

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pet {
public:
	//Constructors are not inherited
	Pet(const string& name) : name(name) {}
	virtual void display() const { //virtual is used to check which Pet's display() (only needed in base class but can be repeated in child class)
		cout << "Pet" << endl;	//polymorphism
	}

protected:
	string getName() const { //protects the access from other methods
		return name;
	}

private:
	string name;
};

class Cat : public Pet {
public:
	Cat(const string& name) : Pet(name) {} //how to initiallize the child's parent constructor
	void purr() const { cout << "purrrrrrrrrrr" << endl; }
	//overriding
	void display() const { 
		cout << "Cat" << endl; 
		purr();
		Pet::display();
	}
	
private:
};

class Slug : public Pet {
public:
	Slug(const string& name) : Pet(name) {}
private:
};

class Roach : public Pet {
public:
private:
};

//Principle of Substitutability
void printAPet(const Pet& aPet) { //pass by value would've only copied Pet not Cat attributes (slicing)
	aPet.display();
}

int main() {
	Pet peeve("Peeve");
	peeve.display();
	Cat felix("Felix");
	felix.display(); //cat display method
	felix.Pet::display(); //pet display method

	printAPet(peeve);
	printAPet(felix);
	cerr << "=========\n";
	vector<Pet*> pets; //can't use a vector of Pet, must be pointers
	pets.push_back(&peeve);
	pets.push_back(&felix);

	for (size_t i = 0; i < pets.size(); i++)
		pets[i]->display();

	felix.purr();
	Cat* catPtr = &felix;
	catPtr->purr();

	Slug sluggo("Sluggo");
	sluggo.display();

	//felix = peeve; does not work, changing the foudation (Cat part of felix)
	//catPtr = &peeve ^^^same reason

	Pet* petPtr;
	petPtr = &felix;

}

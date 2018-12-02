//creating a Cat structure 9/14/15

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Cat {
	string name;
	string furColor;
	int age;
};

void displayCat(const Cat& theCat) {
	cout << theCat.name << ' ' << theCat.furColor << theCat.age << endl;
}

void openCatStream(ifstream& catStream, string& fileName) {
	catStream.open(fileName);
	if (!catStream) {
		cerr << "Failed to open" << fileName << endl;
			exit(1);
	}
}
void displayAllCats(const vector<Cat>& cats) {
	for (const Cat& c : cats) {
		displayCat(c);
	}
}

void fillCatVector(ifstream& catStream) { //cannot read from a const stream
	vector<Cat> cats;
	string name;
	string color;
	int age;
	while (catStream >> name >> color >> age) { //adding cat to cats vector
		Cat catToAdd;
		catToAdd.name = name;
		catToAdd.furColor = color;
		catToAdd.age = age;
		cats.push_back(catToAdd);
	}
}

int main{
	Cat felix;
	felix.name = "Felix";
	felix.furColor = "Orange";
	felix.age = 7;
	displayCat(felix);
	
	ifstream catStream;
	string fileName = "cats.txt";
	openCatStream(catStream, fileName);

	fillCatVector(catStream);
	catStream.close();
	displayAllCats(cats);
}
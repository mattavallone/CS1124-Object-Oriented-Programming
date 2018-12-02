//Matthew Avallone
//Recitation 3

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

struct Molecule {
	int numC;
	int numH;
	vector<string> name;
};

//void openFile(ifstream &ifs);
//void readFile(ifstream &ifs, vector<Molecule>& molecules);
//int findMax(const vector<Molecule>& molecules);
//void printName(vector<Molecule>& molecules);
//void print(vector<Molecule>& molecules);
//

void openFile(ifstream& ifs) {
	ifs.open("hydrocarbons.txt");
	if (!ifs) {
		cerr << "Could not open hydrocarbons\n";
	}
}

size_t checkDuplicate(vector<Molecule>& molecules, int cNum, int hNum) {
	for (size_t index = 0; index < molecules.size(); ++index) {
		if (molecules[index].numC == cNum && molecules[index].numH == hNum) {
			return index;
		}
	}

	return molecules.size();
}

void readFile(ifstream& ifs, vector<Molecule>& molecules) {
	char junk;
	string name;
	int cNum;
	int hNum;

	while (ifs >> name >> junk >> cNum >> junk >> hNum) {
		Molecule molecule;
		molecule.numC = cNum;
		molecule.numH = hNum;
		molecules.push_back(molecule);

		size_t value = checkDuplicate(molecules, cNum, hNum);
		if(value < molecules.size()){
				molecule.name.push_back(name);
				molecules.push_back(molecule);
			}
			else {
				molecule.name.push_back(name);
			}
	}
}

int findMax(const vector<Molecule>& molecules) {
	int maximum = 0;
	for (Molecule m : molecules) {
		
		if (m.numC > maximum) {
			maximum = m.numC;
		}
	}
	return maximum;
}

void printName(const vector<Molecule>& molecules) {
	for (Molecule m : molecules) {
		for (string name : m.name) {
			cout << name << ", ";
		}
	}
}

void print(vector<Molecule>& molecules) {
	int maxC;
	maxC = findMax(molecules);

	for (int i = 0; i < maxC; i++) {
		if (molecules[i].numC = i) {
			printName(molecules);
			cout << " " << "C" << molecules[i].numC << "H" << molecules[i].numH << endl;
		}
	}

}
int main() {
	ifstream ifs;
	openFile(ifs);
	vector<Molecule> molecules;
	readFile(ifs, molecules);
	print(molecules);
}

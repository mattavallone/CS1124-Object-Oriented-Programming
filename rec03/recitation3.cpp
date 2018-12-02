//Matthew Avallone
//Recitation 3

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "stdafx.h"
using namespace std;

void openFile(ifstream &ifs);
void readFile(ifstream &ifs, vector<Molecule>& molecules);
void print(vector<Molecule>& molecules);
int findMax(const vector<Molecule>& molecules);
void printName(vector<Molecule>& molecules);

struct Molecule {
	int numC;
	int numH;
	vector<string> name;
};

int main() {
	ifstream ifs;
	openFile(ifs);
	vector<Molecule> molecules;
	readFile(ifs, molecules);
	print(molecules);
}

void openFile(ifstream& ifs) {
	ifs.open("hydrocarbons.txt");
	if (!ifs) {
		cerr << "Could not open hydrocarbons\n";
	}
}

void readFile(ifstream& ifs, vector<Molecule>& molecules) {
	char junk;
	string name;
	int cNum;
	int hNum;

	while (ifs >> name >> junk >> cNum >> junk >> hNum) {
		Molecule m;
		for (Molecule mol : molecules) {
			if (mol.numC == cNum && mol.numH == hNum) {
				mol.name.push_back(name);
			}
			else {
				m.name.push_back(name);
				m.numC = cNum;
				m.numH = hNum;
				molecules.push_back(m);
			}
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
void printName(const vector<Molecule>& molecules) {
	for (Molecule m : molecules) {
		for (string name : m.name) {
			cout << name << ", ";
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
//Matthew Avallone
//Recitation 2-

#include "stdafx.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void openFile(ifstream& ifs);
void readFile(ifstream& ifs, vector<vector<string>>& molecule);
void print(const vector<vector<string>>& molecule);


int main()
{
	ifstream ifs;
	vector<vector<string>> molecules;
	openFile(ifs);
	readFile(ifs, molecules);
	print(molecules);
}

void openFile(ifstream& ifs) {
	ifs.open("chemicals.txt");
	if (!ifs) {
		cerr << "Couldn't open chemicals\n";
		exit(1);
	}
}

void readFile(ifstream& ifs, vector<vector<string>>& molecules) {
	string name;
	string formula;
	while (ifs >> name >> formula) {
		vector<string> molecule;
		molecule.push_back(name);
		molecule.push_back(formula);
		molecules.push_back(molecule);
	}
}

void print(const vector<vector<string>>& molecules) {
	for (vector<string> v : molecules) {
		cout << v[1] << " ";
		cout << v[0] << endl;
	}
	cout << "---------------" << endl;
	for (size_t i = 0; i < molecules.size(); i++) {
		cout<< molecules[i][1] << " ";
		cout << molecules[i][0] << endl;
	}
}
//Matthew Avallone
//Recitation 3


#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
using namespace std;

struct Molecule {
	Molecule(const string& name, int c, int h) : name(name), numCarbon(c), numHydro(h) {}
	string name;
	int numCarbon;
	int numHydro;
};

ostream& operator<<(ostream& os, const Molecule& rhs){
	os << rhs.name << " C" << rhs.numCarbon << "H" << rhs.numHydro << endl;
	return os;
}


void print(const vector<Molecule>& container) {
	for (size_t i = 0; i < container.size(); i++) {
		cout << container[i] << endl;
	}
}
/*
int main() {
	ifstream ifs("molecules.txt");
	vector<Molecule> vm;
	string name, dummy;
	int carbo, hydro;
	while (ifs >> name >> dummy) {
		
		vm.push_back(Molecule(name, carbo, hydro));
	}
	print(vm);
	ifs.close();
}
*/
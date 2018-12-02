//Matthew Avallone
//The purpose of this lab was to output the battles between warriors

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "stdafx.h"
using namespace std;

struct Warrior {
	string name;
	int strength;
};

struct Battle {
	Warrior man1;
	Warrior man2;
};

struct Status {
	vector<Warrior> warriors;
};

void openFile(istream& ifs);
void printWarriorTotal(const vector<Warrior>& warriors);
void setWarriors(ifstream& ifs, vector<Warrior>& warriors);
void printBattles(const vector<Battle>& battles, vector<Warrior>& warriors);
void setBattles(ifstream& ifs, vector<Battle>& battles, const vector<Warrior>& warriors);

int main() {
	ifstream ifs;
	openFile(ifs);
	vector<Warrior> warriors;
	setWarriors(ifs, warriors);
	vector<Battle> battles;
	setBattles(ifstream& ifs, vector<Battle> battles);
	printWarriorTotal(warriors);
}

void openFile(ifstream& ifs) {
	ifs.open("warriors.txt");
	if (!ifs) {
		cerr << "Could not open warriors" << endl;
	}
}

void printWarriorTotal(const vector<Warrior>& warriors) {
	int numOfWarriors;
	for (size_t i = 0; i < warriors.size(); ++i) {
		numOfWarriors++;
	}
	cout << "There are: " << numOfWarriors << " warriors" << endl;

	for (Warrior man : warriors) {
		cout << "Warrior: " << man.name << ", " << "strength: " << man.strength << endl;
	}
}


void setWarriors(ifstream& ifs, vector<Warrior>& warriors) {
	string type; //conatins either "warrior" or "status"
	Warrior man;
	while (ifs >> type >> man.name >> man.strength) {
		if (type == "status") { //ends the filling of warriors once all the warriors have been entered
			printWarriorTotal(warriors);
			break;
		}
		warriors.push_back(man);
	}
}

void printBattles(const vector<Battle>& battles, vector<Warrior>& warriors) {
	for (Battle fight : battles) {
		cout << fight.man1.name << " battles " << fight.man2.name << endl;

		if (fight.man1.strength > fight.man2.strength) {
			fight.man2.strength -= fight.man1.strength;
			if (fight.man2.strength <= 0) {
				cout << "He's dead, " << fight.man1.name << endl;
				fight.man2.strength = 0;
			}
			else {
				cout << fight.man1.name << " defeats " << fight.man2.name << endl;
			}
		}

		if (fight.man1.strength < fight.man2.strength) {
			fight.man1.strength -= fight.man2.strength;
			if (fight.man1.strength <= 0) {
				cout << "He's dead, " << fight.man1.name << endl;
				fight.man1.strength = 0;
			}
			else {
				cout << fight.man1.name << " defeats " << fight.man2.name << endl;
			}
		}

		if (fight.man1.strength == fight.man2.strength && fight.man1.strength != 0) {
			fight.man1.strength = 0;
			fight.man2.strength = 0;
			cout << "Mutual Annihilation: " << fight.man1.name << " and " << fight.man2.name << " die at each other's hands" << endl;
		}

		if (fight.man1.strength == fight.man2.strength && fight.man1.strength == 0) {
			cout << "Oh, NO!They're both dead! Yuck!" << endl;
		}

		for (Warrior man : warriors) { //adjusts new strengths for each warrior to the vector
			if (man.name == fight.man1.name) {
				man.strength = fight.man1.strength;
			}
			if (man.name == fight.man2.name) {
				man.strength = fight.man2.strength;
			}
		}
	}
}

void setBattles(ifstream& ifs, vector<Battle>& battles, const vector<Warrior> warriors) {
	string type;
	string name1; 
	string name2;
	Battle fight;

	while (ifs >> type >> name1 >> name2) {
		if (type == "status") {
			printBattles(battles, warriors);
			break;
		}
		for (Warrior man : warriors) {
			if (man.name == name1) {
				fight.man1 = man;
			}
			if (man.name == name2) {
				fight.man2 == man;
			}
		}
		battles.push_back(fight);
	}
}




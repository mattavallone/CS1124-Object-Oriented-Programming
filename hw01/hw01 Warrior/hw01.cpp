//Matthew Avallone
//The purpose of this lab was to output the battles between warriors
//Unable to adjust new stengths to warriors after each battle

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
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

void openFile(ifstream& ifs);
void printWarriorTotal(const vector<Warrior>& warriors);
void setWarriors(ifstream& ifs, vector<Warrior>& warriors);
void printBattles(vector<Battle>& battles, vector<Warrior>& warriors);
void setBattles(ifstream& ifs, vector<Battle>& battles, vector<Warrior>& warriors);

int main() {
	ifstream ifs;
	openFile(ifs);
	vector<Warrior> warriors;
	setWarriors(ifs, warriors);
	vector<Battle> battles;
	setBattles(ifs, battles, warriors);
	ifs.close();
	printWarriorTotal(warriors);
}

void openFile(ifstream& ifs) {
	ifs.open("warriors.txt");
	if (!ifs) {
		cerr << "Could not open warriors" << endl;
	}
}

void printWarriorTotal(const vector<Warrior>& warriors) {
	int numOfWarriors = 0;
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
	while (ifs >> type) {
		if (type == "Status") { //ends the filling of warriors once all the warriors have been entered
			printWarriorTotal(warriors);
			return;
		}
		if (type == "Warrior") {
			ifs >> man.name >> man.strength;
			warriors.push_back(man);
		}
		
	}
}


void printBattles(vector<Battle>& battles, vector<Warrior>& warriors) {
	for (Battle& fight : battles) {
		cout << fight.man1.name << " battles " << fight.man2.name << endl;

		if (fight.man1.strength == fight.man2.strength && fight.man1.strength != 0) {
			fight.man1.strength = 0;
			fight.man2.strength = 0;
			cout << "Mutual Annihilation: " << fight.man1.name << " and " << fight.man2.name << " die at each other's hands" << endl;
		}
		else if (fight.man1.strength == fight.man2.strength && fight.man1.strength == 0) {
			cout << "Oh, NO!They're both dead! Yuck!" << endl;
		}

		if (fight.man1.strength > fight.man2.strength && fight.man2.strength != 0) {
			fight.man2.strength = fight.man2.strength - fight.man1.strength;
			fight.man1.strength = fight.man1.strength - fight.man2.strength;
			if (fight.man2.strength < 0) {
				fight.man2.strength = 0;
				cout << "He's dead, " << fight.man1.name << endl;	
			}
			else {
				cout << fight.man1.name << " defeats " << fight.man2.name << endl;
			}
		}
		else if (fight.man1.strength < fight.man2.strength && fight.man1.strength != 0) {
			fight.man1.strength -= fight.man2.strength;
			fight.man2.strength -= fight.man1.strength;
			if (fight.man1.strength < 0) {
				fight.man1.strength = 0;
				cout << "He's dead, " << fight.man1.name << endl;
			}
			else {
				cout << fight.man1.name << " defeats " << fight.man2.name << endl;
			}
		}
		
		for (Warrior& man : warriors) { //adjusts new strengths for each warrior to the warriors vector
			if (man.name == fight.man1.name) {
				man.strength = fight.man1.strength;
			}
			if (man.name == fight.man2.name) {
				man.strength = fight.man2.strength;
			}

			for (Battle& duel : battles) { //adds adjusted warrior back to battles vector
				if (duel.man1.name == man.name)
					duel.man1 = man;
				if (duel.man2.name == man.name)
					duel.man2 = man;
			}
		}

		
	}
}

void setBattles(ifstream& ifs, vector<Battle>& battles, vector<Warrior>& warriors) { //
	string type;
	string name1;
	string name2;
	Battle fight;

	while (ifs >> type) {
		
		if (type == "Status") {
			printBattles(battles, warriors);
			return;
		}

		if (type == "Battle") {
			ifs >> name1 >> name2;

			for (Warrior man : warriors) {
				if (man.name == name1) {
					fight.man1 = man;
				}
				if (man.name == name2) {
					fight.man2 = man;
				}
			}
			battles.push_back(fight);
		}
		
	}
}
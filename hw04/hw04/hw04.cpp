/*
Matthew Avallone
CS1124
Section C

Some errors with dealing with the warriors and nobles; warriors arent all added to an army/displayed properly
*/

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Noble;
class Warrior;

class Warrior {
public:
	Warrior(const string& warriorName, const int warriorStrength) : name(warriorName), strength(warriorStrength){}

	string getName() const {
		return name;
	}
	int getStrength() const {
		return strength;
	}
	
	void setName(const string& aName) {
		name = aName;
	}
	void setStrength(int aStrength) {
		strength *= aStrength;
	}
	
private:
	string name;
	int strength;
};


class Noble {
public:
	Noble(const string& nobleName) : name(nobleName) {}

	void hire(Warrior& man) { //adds a warrior to end of army vector
				army.push_back(&man);
	}

	void fire(Warrior& man) { //removes a certain warrior from army
		for (size_t index = 0; index < army.size(); index++) { //finds position
			if (army[index] == &man) {
				for (size_t index2=index; index2 < army.size() - 1; index2++) { //removes the warrior at index position
					army[index2] = army[index2 + 1];
				}
				army.pop_back();
				return;
			}
		}
		cout << "You don't work for me anymore " << man.getName() << "! -- " << name << '.';
	}

	vector<Warrior*>& getArmy() {
		return army;
	}
	
	double getTotalStrength() {
		int totalStrength = 0;
		for (Warrior* man : army) {
			totalStrength += man->getStrength();
		}
		return totalStrength;
	}
	
	string getName() const {
		return name;
	}

	void adjustStrength(double factor) {
		for (size_t index = 0; index < army.size(); index++) {
			if (factor == 0) {
				army[index]->setStrength(0);

				for (Warrior*& w : army) {
					delete w;
				}
				army.clear();
			}
			else {
				army[index]->setStrength(army[index]->getStrength() * factor);
			}
		}
	}

	void battle(Noble& noble2) { //one noble battles another
		cout << name << " battles " << noble2.getName() << endl;

		if (getTotalStrength() == noble2.getTotalStrength() && getTotalStrength() != 0) {
			adjustStrength(0);
			noble2.adjustStrength(0);
			cout << "Mutual Annihalation: " << name << " and " << noble2.getName() << " die at each other's hands" << endl;
		}
		else if (getTotalStrength() == noble2.getTotalStrength() && getTotalStrength() == 0) {
			cout << "Oh, NO!They're both dead!  Yuck!" << endl;
		}

		if (getTotalStrength() > noble2.getTotalStrength() && noble2.getTotalStrength() != 0) {
				adjustStrength(noble2.getTotalStrength() / getTotalStrength());
				noble2.adjustStrength(0);
				
				cout << name << " defeats " << noble2.getName() << endl;
		}
		else if (getTotalStrength() > noble2.getTotalStrength() && noble2.getTotalStrength() == 0) {
			cout << "He's dead, " << name << endl;
		}

		if (getTotalStrength() < noble2.getTotalStrength() && getTotalStrength() != 0) {
			adjustStrength(0);
			noble2.adjustStrength(getTotalStrength() / noble2.getTotalStrength());
			cout << noble2.getName() << " defeats " << name << endl;
		}
		else if (getTotalStrength() < noble2.getTotalStrength() && getTotalStrength() == 0) {
			cout << "He's dead, " << noble2.getName() << endl;
		}
	}
private:
	string name;
	vector<Warrior*> army;
};

void openFile(ifstream& ifs);
void status(const vector<Noble*>& nobles, const vector<Warrior*>& warriors);

int main() {
	ifstream ifs;
	openFile(ifs);
	vector<Noble*> nobles;
	vector<Warrior*> warriors;
	string command;
	while (ifs >> command) {
		if (command == "Noble") {
			string name;
			ifs >> name;

			bool check = false; //checks name
			for (Noble* n : nobles) {
				if (n->getName() == name) {
					check = true;
				}
			}
			if (check == false) {
				nobles.push_back(new Noble(name));
			}
			nobles.push_back(new Noble(name));
		}
		if (command == "Warrior") {
			string name;
			int strength = 0;
			ifs >> name >> strength;

			bool check = false; //checks name
			for (Warrior* w : warriors) {
				if (w->getName() == name) {
					check = true;
				}
			}
			if (check == false) {
				warriors.push_back(new Warrior(name, strength));
			}
			
		}
	

		if (command == "Status") {
			status(nobles, warriors);
		}

		if (command == "Hire") {
			string nobleName, warriorName;
			ifs >> nobleName >> warriorName;
			bool nobleExists = false;
			for (size_t i = 0; i < nobles.size(); i++) {
				if (nobles[i]->getName() == nobleName) {
					nobleExists = true;
				}
			}
			bool warriorExists = false;
			for (size_t i = 0; i < warriors.size(); i++) {
				if (warriors[i]->getName() == warriorName) {
					warriorExists = true;
				}
			}
			if (warriorExists && nobleExists) {
				for (size_t index = 0; index < nobles.size(); index++) {
					if (nobles[index]->getName() == nobleName) {
						for (size_t i = 0; i < warriors.size(); i++) {
							if (warriors[i]->getName() == warriorName) {
								nobles[index]->hire(*warriors[i]);
							}
						}
					}
				}
				for (size_t index = 0; index < warriors.size(); index++) { //finds position
					if (warriors[index]->getName() == warriorName) {
						for (size_t i = index; i < warriors.size()-1; i++) { //deletes the warrior at i position
							warriors[i] = warriors[i + 1];
						}
					}
					warriors.pop_back();
				}
			}
		}

		if (command == "Fire") {
			string nobleName, warriorName;
			ifs >> nobleName >> warriorName;

			bool nobleExists = false;
			for (size_t i = 0; i < nobles.size(); i++) {
				if (nobles[i]->getName() == nobleName) {
					nobleExists = true;
				}
			}
			bool warriorExists = false;
			for (size_t i = 0; i < warriors.size(); i++) {
				if (warriors[i]->getName() == warriorName) {
					warriorExists = true;
				}
			}
			if (nobleExists && warriorExists) {
				for (size_t index = 0; index < nobles.size(); index++) {
					if (nobles[index]->getName() == nobleName) {
						for (Warrior*& man : warriors) {
							if (man->getName() == warriorName) {
								nobles[index]->fire(*man);
								warriors.push_back(man);
							}
						}
					}
				}
			}
			
		}

		if (command == "Clear") {
			for (Noble*& n : nobles) {
				delete n;
			}
			nobles.clear();
			for (Warrior*& w : warriors) {
				delete w;
			}
			warriors.clear();
		}
		if (command == "Battle") {
			string nobleName1, nobleName2;
			ifs >> nobleName1 >> nobleName2;
			for (size_t index = 0; index < nobles.size(); index++) {
				if (nobles[index]->getName() == nobleName1) {
					for (size_t i = index; i < nobles.size(); i++) {
						if (nobles[i]->getName() == nobleName2) {
							nobles[index]->battle(*nobles[i]);
						}
					}
				}
			}		
		}
	}
	ifs.close();
}

void openFile(ifstream& ifs) { //opens the file
	ifs.open("nobleWarriors.txt");
	if (!ifs) {
		cerr << "Could not open nobleWarriors" << endl;
	}
}

void status(const vector<Noble*>& nobles, const vector<Warrior*>& warriors) {
	cout << "Status" << endl;
	cout << "======" << endl;
	cout << "Nobles: " << endl;
	for (Noble* noble : nobles) {
		cout << noble->getName() << " has an army of " << noble->getArmy().size() << endl;
		for (Warrior* man : noble->getArmy()) {
			cout << "	" << man->getName() << ": " << man->getStrength() << endl;
		}
	}
	cout << "Unemployed Warriors: " << endl; 
	int unemployedCounter = 0;	//keeps track of unemployed warriors
	for (size_t index = 0; index < warriors.size(); index++) {
			cout << warriors[index]->getName() << ": " << warriors[index]->getStrength() << endl;
			++unemployedCounter;
	}
	if (unemployedCounter == 0) {
		cout << "NONE" << endl;
	}
}


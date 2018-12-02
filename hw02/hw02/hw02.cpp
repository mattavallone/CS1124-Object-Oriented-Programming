//Matthew Avallone
//CS1124
//Section C
//HW02

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Weapon {
public:
	Weapon(string name = "No Name", int strength = 0) : weaponName(name), weaponStrength(strength) {}

	string& getWeaponName() {
		return weaponName;
	}
	int getWeaponStrength() {
		return weaponStrength;
	}

	void setWeaponName(const string& name) {
		weaponName = name;
	}
	void setWeaponStrength(int strength) {
		weaponStrength = strength;
	}


private:
	string weaponName;
	int weaponStrength;
};


class Warrior {
public:
	Warrior(Weapon tool, string aName)
		: weapon(tool), name(aName) {}

	string& getName() {
		return name;
	}
	Weapon& getWeapon() {
		return weapon;
	}

	void setName(const string& aName) {
		name = aName;
	}
	void setWeapon(string& name, int strength) {
		weapon.setWeaponName(name);
		weapon.setWeaponStrength(strength);
	}
	
	void battle(Warrior& warrior2, vector<Warrior>& warriors) {
		cout << name << " battles " << warrior2.getName() << endl;
		
		if (getWeapon().getWeaponStrength() == warrior2.getWeapon().getWeaponStrength() && weapon.getWeaponStrength() != 0) { //when they're equal in strength but not dead
			weapon.setWeaponStrength(0);
			warrior2.getWeapon().setWeaponStrength(0);
			cout << "Mutual Annihilation: " << name << " and " << warrior2.getName() << " die at each other's hands" << endl;
		}
		else if (weapon.getWeaponStrength() == warrior2.getWeapon().getWeaponStrength() && weapon.getWeaponStrength() == 0) { //when they're both dead already
			cout << "Oh, NO!They're both dead! Yuck!" << endl;
		}

		if (weapon.getWeaponStrength() > warrior2.getWeapon().getWeaponStrength() && warrior2.getWeapon().getWeaponStrength() != 0) { //when warrior 1 is stronger than warrior 2
			weapon.setWeaponStrength(weapon.getWeaponStrength() - warrior2.getWeapon().getWeaponStrength());
			warrior2.getWeapon().setWeaponStrength(warrior2.getWeapon().getWeaponStrength() - weapon.getWeaponStrength());
			if (warrior2.getWeapon().getWeaponStrength() < 0) {
				warrior2.getWeapon().setWeaponStrength(0);
				cout << "He's dead, " << name << endl;
			}
			else {
				cout << name << " defeats " << warrior2.getName() << endl;
			}
		}
		else if (weapon.getWeaponStrength() < warrior2.getWeapon().getWeaponStrength() && weapon.getWeaponStrength() != 0) { //when warrior 2 is stronger than warrior 1
			weapon.setWeaponStrength(weapon.getWeaponStrength() - warrior2.getWeapon().getWeaponStrength());
			warrior2.getWeapon().setWeaponStrength(warrior2.getWeapon().getWeaponStrength() - weapon.getWeaponStrength());
			if (weapon.getWeaponStrength() < 0) {
				weapon.setWeaponStrength(0);
				cout << "He's dead, " << name << endl;
			}
			else {
				cout << warrior2.getName() << " defeats " << name << endl;
			}
		}

		for (Warrior& man : warriors) { //adjusts the changed warrior in the vector
			if (man.getName() == name) {
				man.setWeapon(weapon.getWeaponName(), weapon.getWeaponStrength());
			}
			if (man.getName() == warrior2.getName()) {
				man = warrior2;
			}
		}

	}
private:
	string name;
	Weapon weapon;
};

void openFile(ifstream & ifs);
void status(const vector<Warrior>& warriors);

int main() {
	ifstream ifs;
	openFile(ifs);
	vector<Warrior> warriors;
	string command;

	while (ifs >> command) {
		if (command == "Warrior") {
			string name, weaponName;
			int strength;
			ifs >> name >> weaponName >> strength;
			warriors.push_back(Warrior(Weapon(weaponName, strength), name));
		}

		if (command == "Status") {
			status(warriors);
		}

		if (command == "Battle") {
			string name1, name2;
			ifs >> name1 >> name2;
			Warrior man1(Weapon("", 0), ""), man2(Weapon("", 0), "");

			for (Warrior& warrior : warriors) {
				if (warrior.getName() == name1) {
					man1 = warrior;
				}
				if (warrior.getName() == name2) {
					man2 = warrior;
				}
			}
			man1.battle(man2, warriors);
		}
	}
	ifs.close();
}

void status(const vector<Warrior>& warriors) {
	int numOfWarriors = 0;
	for (size_t i = 0; i < warriors.size(); ++i) {
		numOfWarriors++;
	}
	cout << "There are: " << numOfWarriors << " warriors" << endl;

	for (Warrior man : warriors) {
		cout << "Warrior: " << man.getName() << ", " << "Weapon: " << man.getWeapon().getWeaponName() << ", " << man.getWeapon().getWeaponStrength() << endl;
	}
}

void openFile(ifstream& ifs) {
	ifs.open("warriors.txt");
	if (!ifs) {
		cerr << "Could not open warriors" << endl;
	}
}


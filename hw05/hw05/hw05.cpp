//Matthew Avallone
//CS1124
//Section C
//October 30 2015

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Protector {
	
public:
	Protector(const string& name, int strength) : name(name), strength(strength) {}

	void setJobStatus(bool status) { //used to determine the state of employment
		isHired = status;
	}

	bool getJobStatus() { //returns employment status (if in an army)
		return isHired;
	}
	int getStrength() {
		return strength;
	}
	void setStrength(double newStr) {
		strength *= newStr;
	}

	virtual void battleSound() {};
protected:
	string getName() {
		return name;
	}
private:
	string name;
	int strength; 
	bool isHired = false;
};

class Wizard : public Protector {
public:
	Wizard(const string& name, int strength) : Protector(name, strength) {}
	void battleSound() {
		cout << "POOF" << endl;
	}
private:
};

class Warrior : public Protector {
public: 
	Warrior(const string name, int strength) : Protector(name, strength) {}
	void battleSound() {}

private:
};

class Archer : public Warrior {
public:
	Archer(const string& name, int strength) : Warrior(name, strength) {}

	void battleSound() {
		cout << "TWANG!		" << getName() << " says: Take that in the name of my Lord: ";
	}
private:
};

class Swordsman : public Warrior {
public:
	Swordsman(const string& name, int strength) : Warrior(name, strength) {}

	void battleSound() {
		cout << "CLANG!		" << getName() << " says: Take that in the name of my Lord: ";
	}
private:
};

class Noble {
	friend bool operator>(Noble& n1, Noble& n2);
	friend bool operator<(Noble& n1, Noble& n2);
	friend bool operator==(Noble& n1, Noble& n2);
public:
	Noble(const string name) : name(name) {}

	void battle(Noble& noble2) {
		cout << name << " battles " << noble2.getName() << endl;

		if (*this > noble2 && noble2.getStrength() > 0) {
			setStrength(noble2.getStrength() / getStrength());
			noble2.setStrength(0);
			cout << name << " defeats " << noble2.getName() << endl;
		}
			else {
				cout << "He's dead, " << noble2.getName() << endl;
			}
		if (*this < noble2 && getStrength() > 0){
			setStrength(0);
			noble2.setStrength(getStrength() / noble2.getStrength());
			cout << noble2.getName() << " defeats " << name << endl;
		}
		else {
			cout << "He's dead, " << name << endl;
		}

		if (*this == noble2 && getStrength() > 0){
			setStrength(0);
			noble2.setStrength(0);
			cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
		}
	}

	virtual int getStrength() = 0;
	virtual void setStrength(double str) = 0;

	string getName() {
		return name;
	}
private:
	string name;
};

class PersonWithStrengthToFight : public Noble {
public:
	PersonWithStrengthToFight(const string& name, int strength) : Noble(name), strength(strength) {}

	int getStrength() {
		return strength;
	}
	void setStrength(double str) {
		strength *= str;
	}
private:
	int strength;
};

class Lord : public Noble {
public:
	Lord(const string& name) : Noble(name) {}

	void hires(Protector& man) {
		if (man.getJobStatus() == false) { //checks to make sure Protector is unemployed
			army.push_back(&man);
			man.setJobStatus(true); //employs the Protector
		}
	}
	int getStrength() { //returns the sum of the army's strength
		int strength = 0;
		for (Protector* prtr : army) {
			strength += prtr->getStrength();
		}
		return strength;
	}
	void setStrength(double str) {
		if (str != 0) {
			for (Protector*& prtr : army) { //changes the strength of each Protector
				prtr->battleSound();
				cout << getName() << endl;
				prtr->setStrength(str);
			}
		}
		else {
			for (Protector*& prtr : army) {
				delete prtr;
			}
			army.clear();
		}
	}

private:
	vector<Protector*> army;
};

bool operator>(Noble& n1, Noble& n2) {
	return n1.getStrength() > n2.getStrength();
}
bool operator<(Noble& n1, Noble& n2) {
	return n1.getStrength() < n2.getStrength();
}
bool operator==(Noble& n1, Noble& n2) {
	return n1.getStrength() == n2.getStrength();
}

int main() {
	Lord sam("Sam");
	Archer samantha("Samantha", 200);
	sam.hires(samantha);
	Lord joe("Joe");
	PersonWithStrengthToFight randy("Randolf the Elder", 250);
	joe.battle(randy);
	joe.battle(sam);
	Lord janet("Janet");
	Swordsman hardy("TuckTuckTheHardy", 100);
	Swordsman stout("TuckTuckTheStout", 80);
	janet.hires(hardy);
	janet.hires(stout);
	PersonWithStrengthToFight barclay("Barclay the Bold", 300);
	janet.battle(barclay);
	janet.hires(samantha);
	Archer pethora("Pethora", 50);
	Archer thora("Thorapleth", 60);
	Wizard merlin("Merlin", 150);
	janet.hires(pethora);
	janet.hires(thora);
	sam.hires(merlin);
	janet.battle(barclay);
	sam.battle(barclay);
	joe.battle(barclay);
}

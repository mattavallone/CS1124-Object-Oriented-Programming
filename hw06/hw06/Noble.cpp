#include <vector>
#include <iostream>
#include <string>
using namespace std;

#include "Noble.h"
#include "Warrior.h"


namespace WarriorCraft {

	Noble::Noble(const string& nobleName) : name(nobleName) {}

	void Noble::hire(Warrior& man) { //adds a warrior to end of army vector
		army.push_back(&man);
		man.setLeader(this);
	}

	void Noble::remove(Warrior& man) { //removes a certain warrior from army
		for (size_t index = 0; index < army.size(); index++) { //finds position
			if (army[index] == &man) {
				for (index; index < army.size() - 1; index++) { //removes the warrior at index position
					army[index] = army[index + 1];
				}
				army.pop_back();
				return;
			}
		}
	}

	string Noble::getName() const {
		return name;
	}

	double Noble::getTotalStrength() { //returns the strength of the noble's army
		double totalStrength = 0;
		for (size_t armyIndex = 0; armyIndex < army.size(); ++armyIndex) {
			totalStrength += (army[armyIndex]->getStrength());
		}
		return totalStrength;
	}

	void Noble::reduceStrength(double factor) { //reduces the strength of the noble's warriors
		for (Warrior*& man : army) {
			man->setStrength((man->getStrength()) * factor);
		}
	}

	void Noble::battle(Noble& otherNoble) { 
		cout << name << " battles " << otherNoble.getName() << endl;

		if (otherNoble.getTotalStrength() == getTotalStrength()) {
			if (getTotalStrength() == 0)
				cout << "Oh, NO! They're both dead! Yuck!" << endl;
			else {
				otherNoble.army.clear();
				army.clear();
				cout << "Mutual Annihalation: " << name << " and " << otherNoble.getName() << " die at each other's hands" << endl;
			}
		}
		else if (getTotalStrength() > otherNoble.getTotalStrength()) {
			if (otherNoble.getTotalStrength() == 0)
				cout << "He's dead, " << name << endl;
			else {
				double reductionFactor = (otherNoble.getTotalStrength() / getTotalStrength());
				otherNoble.army.clear();
				this->reduceStrength(reductionFactor);
				cout << name << " defeats " << otherNoble.getName() << endl;
			}
		}
		else {
			if (getTotalStrength() == 0)
				cout << "He's dead, " << otherNoble.getName() << endl;
			else {
				double reductionFactor = (getTotalStrength() / otherNoble.getTotalStrength());
				army.clear();
				otherNoble.reduceStrength(reductionFactor);
				cout << otherNoble.getName() << " defeats " << name << endl;
			}
		}
	}


	ostream& operator<<(ostream& os, const Noble& n) { //displays the noble and his army
		os << n.getName() << " has an army of " << n.army.size() << endl;
		if (n.army.size() != 0) {
			for (Warrior* man : n.army) {
				os << "	" << man->getName() << ": " << man->getStrength() << endl;
			}
		}
		return os;
	}
}
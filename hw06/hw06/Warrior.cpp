#include <vector>
#include <string>
#include <iostream>
using namespace std;


#include "Warrior.h"
#include "Noble.h"

using namespace std;

namespace WarriorCraft {
	Warrior::Warrior(const string& warriorName, const double warriorStrength) : name(warriorName), strength(warriorStrength), leader(nullptr) {}

	string Warrior::getName() const { //returns name of warrior
		return name;
	}

	double Warrior::getStrength() const { //returns warriors strength
		return strength;
	}

	void Warrior::setStrength(double aStrength) { //sets strength of warrior
		strength *= aStrength;
	}
	void Warrior::setLeader(Noble* noble) { //sets leader
		leader = noble;
	}

	void Warrior::runaway() { //warrior runs away
		cout << name << " flees in terror, abandoning his lord, " << leader->getName() << endl;
		leader->remove(*this);
		leader = nullptr;
	}
}
//Matthew Avallone
//CS1124 
//Section C

//the noble that calls the battle method has an army size of 0, not sure why

#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Warrior {
public:
	Warrior(const string& warriorName = "No Name", const int warriorStrength = 0) : name(warriorName), strength(warriorStrength) {}

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
	Noble(const string& nobleName = "No Name") : name(nobleName) {}

	void hire(Warrior& man) { //adds a warrior to end of army vector
		army.push_back(&man);
	}

	void fire(Warrior& man) { //removes a certain warrior from army
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
	
	vector<Warrior*>& getArmy() {
		return army;
	}

	string getName() const {
		return name;
	}
	
	
	
	void display() { //displays the noble and his army
		cout << name << " has an army of " << army.size() << endl;
		for (Warrior* man: army) {
			cout << "	" << man->getName() << ": " << man->getStrength() << endl;
		}
	}

	void battle(Noble& noble2) { //one noble battles another
		cout << name << " battles " << noble2.getName() << endl;
			
		if (army.size() == noble2.getArmy().size() && army.size() != 0) {
			army.clear();
			noble2.getArmy().clear();
			cout << "Mutual Annihalation: " << name << " and " << noble2.getName() << " die at each other's hands" << endl;
		}
		else if (this->army.size() == noble2.getArmy().size() && army.size() == 0) {
			cout << "Oh, NO!They're both dead!  Yuck!" << endl;
		}

		if (army.size() > noble2.getArmy().size() && noble2.getArmy().size() != 0 && army.size() > 0) {
			for (Warrior*& man : army) {
				man->setStrength((noble2.getArmy().size() / army.size()));
			}
			noble2.getArmy().clear();
			cout << name << " defeats " << noble2.getName() << endl;
		}
		else if(army.size() > noble2.getArmy().size() && noble2.getArmy().size() == 0 && army.size() > 0) {
			cout << "He's dead, " << name << endl;
		}

		if (army.size() < noble2.getArmy().size() && army.size() != 0 && noble2.getArmy().size() > 0) {
			for (Warrior*& otherMan : noble2.getArmy()) {
				otherMan->setStrength((army.size() / noble2.getArmy().size()));
			}
			army.clear();
			cout << noble2.getName() << " defeats " << name << endl;
		}
		else if(army.size() < noble2.getArmy().size() && army.size() == 0 && noble2.getArmy().size() > 0){
			cout << "He's dead, " << noble2.getName() << endl;
		}
	}
private:
	string name;
	vector<Warrior*> army;
};




int main() {
	Noble art("King Arthur");
	Noble lance("Lancelot du Lac");
	Noble jim("Jim");
	Noble linus("Linus Torvalds");
	Noble billie("Bill Gates");

	Warrior cheetah("Tarzan", 10);
	Warrior wizard("Merlin", 15);
	Warrior theGovernator("Conan", 12);
	Warrior nimoy("Spock", 15);
	Warrior lawless("Xena", 20);
	Warrior mrGreen("Hulk", 8);
	Warrior dylan("Hercules", 3);

	jim.hire(nimoy);
	lance.hire(theGovernator);
	art.hire(wizard);
	lance.hire(dylan);
	linus.hire(lawless);
	billie.hire(mrGreen);
	art.hire(cheetah);

	jim.display();
	lance.display();
	art.display();
	linus.display();
	billie.display();

	art.fire(cheetah);
	art.display();

	art.battle(lance);
	jim.battle(lance);
	linus.battle(billie);
	billie.battle(lance);
}

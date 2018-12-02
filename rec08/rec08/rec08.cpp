//Matthew Avallone
//CS1124
//Section C

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Instrument {
public:
	virtual void makeSound() = 0;
	virtual void play() = 0;
private:
};

class Percussion : public Instrument {
public:
	void makeSound() override {
		cout << "To make a sound... hit me!" << endl;
	}
private:
};

class Cymbal : public Percussion{
public:
	void play() {
		cout << "Crash";
	}
private:
};

class Drum : public Percussion {
public:
	void play() {
		cout << "Boom";
	}
private:
};

class Strings : public Instrument {
public:
	Strings(unsigned pitch) : pitch(pitch) {}
	void makeSound() override {
		cout << "To make a sound... bow a string with pitch " << pitch << endl;
	}
private:
	unsigned pitch;

};

class Violin : public Strings {
public:
	Violin(unsigned pitch) : Strings(pitch) {}

	void play() {
		cout << "Screech";
	}
private:
};

class Cello : public Strings {
public:
	Cello(unsigned pitch) : Strings(pitch) {}

	void play() {
		cout << "Squawk";
	}
private:
};

class Brass : public Instrument {
public:
	Brass(int size) : size(size) {}

	void makeSound() override {
		cout << "To make a sound... blow on mouthpiece of size " << size << endl;
	}
private:
	int size;
};

class Trumpet : public Brass {
public:
	Trumpet(int size) : Brass(size) {}

	void play() {
		cout << "Toot";
	}
private:
};

class Trombone : public Brass {
public:
	Trombone(int size) : Brass(size) {}

	void play() {
		cout << "Blat";
	}
private:
};

class MILL {
public:
	void dailyTestPlay() {
		for (Instrument* instru : inventory) {
			if (instru != NULL) {
				instru->makeSound();
			}
		}
	}

	void receiveInstr(Instrument& instru) {
		//instru.makeSound();
		inventory.push_back(&instru);
	}

	Instrument* loanOut() {
		if (inventory.size() == 0) {
			return NULL;
		}
		Instrument* loan = inventory[0];
		for (size_t index = 0; index < inventory.size() -1; index++) {
			inventory[index] = inventory[index+1];
		}
		inventory.pop_back();
		return loan;
	}
private:
	vector<Instrument*> inventory;
};


class Musician {
public:
	Musician() : instr(NULL) {}

	void acceptInstr(Instrument & i) { instr = &i; }

	Instrument* giveBackInstr() {
		Instrument* tmp(instr);
		instr = NULL;
		return tmp;
	}

	void testPlay() const {
		if (instr != NULL)
			instr->play();
		else
			cerr << "have no instr\n";
	}

	Instrument* getInstru() {
		return instr;
	}
private:
	Instrument* instr;
};

class Orchestra {
public:
	void addPlayer(Musician& player) {
		if (musicians.size() == 25) {
			return;
		}
		musicians.push_back(&player);
	}

	void play() {
		for (Musician*& player : musicians) {
			if (player->getInstru() != NULL) {
				player->testPlay();
			}
		}
		cout << endl;
	}
private:
	vector<Musician*> musicians;
};


// PART TWO
int main()
{
	// The initialization phase

	Drum drum;
	Cello cello(673);
	Cymbal cymbal;
	Trombone tbone(4);
	Trumpet trpt(12);
	Violin violin(567);

	MILL mill;
	mill.receiveInstr(trpt);
	mill.receiveInstr(violin);
	mill.receiveInstr(tbone);
	mill.receiveInstr(drum);
	mill.receiveInstr(cello);
	mill.receiveInstr(cymbal);

	Musician bob;
	Musician sue;
	Musician mary;
	Musician ralph;
	Musician jody;
	Musician morgan;

	Orchestra orch;



	// THE SCENARIO

	//Bob joins the orchestra without an instrument.
	orch.addPlayer(bob);

	//The orchestra performs
	cout << "orch performs\n";
	orch.play();

	//Sue gets an instrument from the MIL2 and joins the orchestra.
	sue.acceptInstr(*mill.loanOut());
	orch.addPlayer(sue);

	//Ralph gets an instrument from the MIL2.
	ralph.acceptInstr(*mill.loanOut());

	//Mary gets an instrument from the MIL2 and joins the orchestra.
	mary.acceptInstr(*mill.loanOut());
	orch.addPlayer(mary);

	//Ralph returns his instrument to the MIL2.
	mill.receiveInstr(*ralph.giveBackInstr());

	//Jody gets an instrument from the MIL2 and joins the orchestra.
	jody.acceptInstr(*mill.loanOut());
	orch.addPlayer(jody);

	// morgan gets an instrument from the MIL2
	morgan.acceptInstr(*mill.loanOut());

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Ralph joins the orchestra.
	orch.addPlayer(ralph);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	// bob gets an instrument from the MIL2
	bob.acceptInstr(*mill.loanOut());

	// ralph gets an instrument from the MIL2
	ralph.acceptInstr(*mill.loanOut());

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Morgan joins the orchestra.
	orch.addPlayer(morgan);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	system("pause");

} // main

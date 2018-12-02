//Matthew Avallone
//Tasks 1-5

#include <iostream>
#include <vector>
using namespace std;

class Sandwich {

public:
	Sandwich(int someCheese = 1, int someTomato = 2, double someMustard = .05, double someMayo = 1) 
		: bread(2), cheese(someCheese), tomato(someTomato), mustard(someMustard), mayonnaise(someMayo) {}

	void display() const { //displays the contents of a sandwich
		cout << "Bread: " << bread << endl << "Cheese: " << cheese << endl << "Tomato: " << tomato << endl << "Mayo: " << mayonnaise << endl << "Mustard: " << mustard << endl;
	}

	int getBread() const {
		return bread;
	}
	int getCheese() const {
		return cheese;
	}

	int getTomato() const {
		return tomato;
	}
	double getMayo() const {
		return mayonnaise;
	}
	double getMustard() const {
		return mustard;
	}
	void setCheese(int someCheese) {
		cheese = someCheese;
	}
	void setTomato(int someTomato) {
		tomato = someTomato;
	}
	void setMayo(double someMayo) {
		mayonnaise = someMayo;
	}
	void setMustard(double someMustard) {
		mustard = someMustard;
	}

private:
	const int bread;
	int cheese;
	int tomato;
	double mayonnaise =1;
	double mustard;
};

class SandwichTruck {
public:
	SandwichTruck(vector<Sandwich>& sw) : sandwiches(sw) {}

	void checkBeforeLeaving() { //checks the contents of each sandwich;
		for (size_t index = 0; index < sandwiches.size(); index ++) {
			cout << "Order " << (index + 1) << endl;
			sandwiches[index].display();
			cout << endl;
		}

		cout << "All set to leave" << endl;
	}

	void insertSandwich(Sandwich& sw) { //inserts a sandwich
		sandwiches.push_back(sw);
	}

private:
	vector<Sandwich> sandwiches;
};

int main() {
	/*
	Sandwich sandwich(1, 2, .05, 1);
	sandwich.display();
	cout << "Bread: " << sandwich.getBread() << endl; 
	cout << "Cheese: " << sandwich.getCheese() << endl;
	sandwich.setCheese(5);
	cout << "Cheese: " << sandwich.getCheese() << endl;
	vector<Sandwich> sandwiches;
	sandwiches.push_back(sandwich);
	SandwichTruck truck(sandwiches);
	Sandwich sandwich2(2, 3, .1, 2);
	truck.insertSandwich(sandwich2);
	*/

	vector<Sandwich> orders;
	Sandwich order1;
	orders.push_back(order1);
	Sandwich order2;
	order2.setMustard(0.0);
	orders.push_back(order2);
	Sandwich order3(2);
	orders.push_back(order3);
	Sandwich order4;
	orders.push_back(order4);
	SandwichTruck truck(orders);
	truck.checkBeforeLeaving();
}
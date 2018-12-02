//Matthew Avallone
//9/28/15


#include <iostream>
#include <string>
using namespace std;

class Person {
public:
	Person(const string& name) : name(name), spouse(nullptr) {}
	void display(ostream& os = cout) const {
		cout << "Name: " << name << ", marital status: ";
		if (spouse != nullptr) {
			cout << spouse->name << endl;
		}
		else
			{
				cout << "Single";
			}
	}
	
	bool marries(Person& betrothed) {
		if (spouse == nullptr && betrothed.spouse == nullptr) {
			spouse = &betrothed;
			betrothed.spouse = this; //this points to Person*
			return true;
		}
		return false;
	}

private:
	string name;
	Person *spouse;
};

int main() {
	Person john("John");
	Person mary("Mary");
	john.display();
	mary.display();
	john.marries(mary);
	john.display();
	mary.display();


}
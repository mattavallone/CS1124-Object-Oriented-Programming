//Matthew Avallone
//CS1124
//Section C
//Recitiation 6

#include <vector>
#include <string>
#include <iostream>
using namespace std;


class Student {
public:
	Student(const string& name) :name(name), grades(13, -1) {}

	void displayStudent() {
		cout << "Student: " << name << "; Grades: ";
		for (size_t index = 0; index < grades.size(); index++) {
			cout << grades[index] << ' ';
		}
		cout << endl;
	}
	void setGrade(int grade, int week) {
		grades[week - 1] = grade;
	}
	string getName() {
		return name;
	}
private:
	string name;
	vector<int> grades;
};

class TimeSlot {
public:
	TimeSlot(const string& day = "", int hour = 0) : day(day), hour(hour) {}

	void display() const {
		cout << day << ": " << (hour-12);
		if (hour > 11) {
			cout << "PM" << endl;
		}
		else {
			cout << "AM" << endl;
		}
	}
private:
	string day;
	int hour;
};

class LabSection {
public:
	LabSection(const string& name, const string& day, int hour) : name(name), time(TimeSlot(day, hour)) {}

	void display() {
		cout << "Section: " << name << ' ';
		time.display();
		for (Student* student : students) {
			student->displayStudent();
		}
	}

	void reset() {
		students.clear();
	}

	void addStudent(const string& name) {
		students.push_back(new Student(name));
	}

	void addGrade(const string& studName, int grade, int week) {
		for (size_t index = 0; index < students.size(); index++) {
			if (students[index]->getName() == studName) {
				students[index]->setGrade(grade, week);
			}
		}
	}

private:
	string name;
	vector<Student*> students;
	const TimeSlot time;
};

class LabWorker {
public:
	LabWorker(const string& name) : name(name){}

	void addSection(LabSection& sec) {
		section = &sec;
	}

	void addGrade(const string& studName, int grade, int labNumber) {
		section->addGrade(studName, grade, labNumber);
	}

	void displayGrades() {
		cout << name << " has ";
		section->display();
	}
private:
	string name;
	LabSection* section;
};


int main() {

	// lab workers
	LabWorker moe("Moe");
	LabWorker jane("Jane");

	// sections and setup and testing
	LabSection secA2("A2", "Tuesday", 16);
	//secA2.loadStudentsFromFile( "A2.txt" );
	secA2.addStudent("John");
	secA2.addStudent("George");
	secA2.addStudent("Paul");
	secA2.addStudent("Ringo");

	cout << "\ntest A2\n";    // here the modeler-programmer checks that load worked
	secA2.display();          // YOU'll DO THIS LATER AS: cout << secA2 << endl;
	moe.addSection(secA2);
	moe.displayGrades();       // here the modeler-programmer checks that adding the Section worked

	LabSection secB3("B3", "Thursday", 11);
	//secB3.loadStudentsFromFile( "B3.txt" );
	secB3.addStudent("Thorin");
	secB3.addStudent("Dwalin");
	secB3.addStudent("Balin");
	secB3.addStudent("Kili");
	secB3.addStudent("Fili");
	secB3.addStudent("Dori");
	secB3.addStudent("Nori");
	secB3.addStudent("Ori");
	secB3.addStudent("Oin");
	secB3.addStudent("Gloin");
	secB3.addStudent("Bifur");
	secB3.addStudent("Bofur");
	secB3.addStudent("Bombur");

	cout << "\ntest B3\n";    // here the modeler-programmer checks that load worked
	secB3.display();          // YOU'll DO THIS LATER AS: cout << secB3 << endl;
	jane.addSection(secB3);
	jane.displayGrades();      // here the modeler-programmer checks that adding Instructor worked


							   // setup is complete, now a real world scenario can be written in the code
							   // [NOTE: the modeler-programmer is only modeling joe's actions for the rest of the program]

							   // week one activities  
	cout << "\nModeling week: 1\n";
	moe.addGrade("John", 7, 1);
	moe.addGrade("Paul", 9, 1);
	moe.addGrade("George", 7, 1);
	moe.addGrade("Ringo", 7, 1);
	cout << "End of week one\n";
	moe.displayGrades();

	// week two activities
	cout << "\nModeling week: 2\n";
	moe.addGrade("John", 5, 2);
	moe.addGrade("Paul", 10, 2);
	moe.addGrade("Ringo", 0, 2);
	cout << "End of week two\n";
	moe.displayGrades();

	//test that reset works  // NOTE: can we check that the heap data was dealt with?
	cout << "\ntesting reset()\n";
	secA2.reset();
	secA2.display();
	moe.displayGrades();

} 
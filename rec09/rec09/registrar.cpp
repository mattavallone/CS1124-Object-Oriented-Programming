#include "Registrar.h"
#include "Course.h"
#include "Student.h"
#include <string>
#include <iostream>
using namespace std;
namespace BrooklynPoly {

	void Registrar::addCourse(const string& cor) {
		courses.push_back(new Course(cor));
	}
	void Registrar::addStudent(const string& kid) {
		students.push_back(new Student(kid));
	}
	void Registrar::enrollStudentInCourse(const string& studName, const string& corName) {
		for (Course*& cors : courses) {
			if (cors->getName() == corName) {
				cors->addStudent(studName);
			}
		}
	}
	void Registrar::cancelCourse(const string& corName) {
		for (size_t index = 0; index < courses.size(); index++) {
			if (courses[index]->getName() == corName) {
				delete courses[index];
				for (size_t i = index; i < courses.size() - 1; i++) {
					courses[i] = courses[i + 1];
				}
				courses.pop_back();
				return;
			}
		}
	}
	void Registrar::printReport() {
		for (Course* cor : courses) {
			cout << cor->getName() << ": " << endl;
			for (Student* stud : students) {
				cout << "	" << stud->getName() << endl;
			}
		}
	}
}
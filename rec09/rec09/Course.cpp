#include "Course.h"
#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

namespace BrooklynPoly {
	Course::Course(const string& name) : name(name) {}
		string Course::getName() {
			return name;
		}
		
		void Course::addStudent(const string& studName) {
			bool isNotThere = true;
			for (Student* stud : scholars) {
				if (stud->getName() == studName) {
					isNotThere = false;
				}
			}
			if (isNotThere) {
				scholars.push_back(new Student(studName));
			}
		}
		
}
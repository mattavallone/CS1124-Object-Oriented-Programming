#include "Student.h"
#include "Course.h"
#include <string>
#include <iostream>
using namespace std;

namespace BrooklynPoly {
	Student::Student(const std::string& name) :name(name) {}
	string Student::getName() {
		return name;
	}
}
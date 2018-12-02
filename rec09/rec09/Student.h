#ifndef STUD_H
#define STUD_H

#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

namespace BrooklynPoly {
	class Course;
	class Student {
	public:
		Student(const std::string& name);

		std::string getName();
	private:
		std::string name;
		std::vector<Course*> classes;
	};
}

#endif
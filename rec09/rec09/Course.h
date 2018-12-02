#ifndef COR_H
#define COR_H

#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

namespace BrooklynPoly {
	class Student;
	class Course {
	public:
		Course(const std::string& name);
		std::string getName();
		void addStudent(const std::string& studName);
	private:
		std::string name;
		std::vector<Student*> scholars;
	};
}

#endif
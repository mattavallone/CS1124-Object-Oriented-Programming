#ifndef REG_H
#define REG_H

#pragma once
#include <vector>

namespace BrooklynPoly {
	class Student;
	class Course;
	class Registrar {
	public:
		void addCourse(const std::string& cor);
		void addStudent(const std::string& kid);
		void enrollStudentInCourse(const std::string& studName, const std::string& corName);
		void cancelCourse(const std::string& corName);
		void printReport();
	private:
		std::vector<Student*> students;
		std::vector<Course*> courses;
	};
}

#endif
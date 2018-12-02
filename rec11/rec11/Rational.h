#ifndef RAT_H
#define RAT_H
#include <ostream>
#include <istream>
#pragma once

namespace CS1124 {

	class Rational {
		friend std::istream& operator>>(std::istream& is, Rational& rhs);
		friend std::ostream& operator<<(std::ostream& os, Rational& rhs);\
		friend bool operator==(Rational& lhs, Rational& rhs);
		friend bool operator==(int numb, Rational& rhs);
		friend Rational& normalize(Rational& number);
	public:
		Rational();
		Rational(const int num);
		Rational& operator+=(Rational& rhs);
		Rational& operator++();
		Rational operator++(int);
	private:
		int num;
		int denom;
	};

	Rational& normalize(Rational& number);
	std::istream& operator>>(std::istream& is, Rational& rhs);
	std::ostream& operator<<(std::ostream& os, Rational& rhs);
	bool operator==(Rational& lhs, Rational& rhs);
	bool operator==(Rational& lhs, Rational& rhs);
	bool operator!=(Rational& lhs, Rational& rhs);
	Rational operator+(Rational& lhs, Rational& rhs);
	Rational& operator--(Rational& rhs);
	Rational operator--(Rational& rhs, int);
}




#endif

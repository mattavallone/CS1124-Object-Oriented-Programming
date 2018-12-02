#include "Rational.h"
using namespace std;

namespace CS1124 {
	Rational::Rational() : num(0), denom(1) {}
	Rational::Rational(const int num) : num(num), denom (1) {}
	
	Rational& Rational::operator+=(Rational& rhs) {
		normalize(*this);
		normalize(rhs);
		num = (num * rhs.denom + denom * rhs.num);
		denom = (rhs.denom * denom);
		normalize(*this);
		return *this;
	}
	Rational& Rational::operator++() {
		++num;
		return *this;
	}
	Rational Rational::operator++(int) {
		Rational copy = *this;
		++num;
		return copy;
	}

	int greatestCommonDivisor(int x, int y) {
		while (y != 0) {
			int temp = x % y;
			x = y;
			y = temp;
		}
		return x;
	}
	
	Rational& normalize(Rational& number) {
		number.num /= greatestCommonDivisor(number.num, number.denom);
		number.denom /= greatestCommonDivisor(number.num, number.denom);
		return number;
	}
	
	istream & operator>>(istream & is, Rational & rhs)
	{ return is >> rhs.num >> rhs.denom; }
	ostream & operator<<(ostream & os, Rational & rhs)
	{ 
		if (rhs.num == rhs.denom) {
			return os << rhs.num << endl;
		}
		if (rhs.num == 0) {
			return os << "0" << endl;
		}
		normalize(rhs);
		return os << rhs.num << "/" << rhs.denom << endl; }

	bool operator==(Rational& lhs, Rational& rhs) {
		normalize(lhs);
		normalize(rhs);
		return (lhs.num == rhs.num && lhs.denom == rhs.denom);
	}

	bool operator==(int numb, Rational& rhs) {
		Rational number(numb);
		return number == rhs;
	}

	bool operator!=(Rational& lhs, Rational& rhs) {
		return !(lhs == rhs);
	}

	Rational operator+(Rational& lhs, Rational& rhs) {
		Rational result = lhs;
		result += rhs;
		return result;
	}
	Rational& operator--(Rational& rhs) {
		return rhs += Rational(-1);
	}
	Rational operator--(Rational& rhs, int) {
		Rational copy = rhs;
		rhs += Rational(-1);
		return copy;
	}
}
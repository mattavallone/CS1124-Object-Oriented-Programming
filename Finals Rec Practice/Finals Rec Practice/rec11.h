#ifndef REC11
#define REC11

#include <iostream>
#include <string>

namespace rec11 {
	class Rational {
		friend std::ostream& operator<<(std::ostream& os, const Rational& rhs);
		friend std::istream& operator>>(std::istream& is, const Rational& rhs);
		friend bool operator==(const Rational& lhs, const Rational& rhs);
	public:
		Rational(int num, int den);
		Rational& operator+=(const Rational& rhs);
		Rational& operator++();
		void gcm(const Rational& rhs);
	private:
		int num;
		int denom;
	};
}

#endif
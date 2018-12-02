#include "rec11.h"
#include <iostream>
using namespace std;

namespace rec11 {
	Rational::Rational(int num, int den) : num(num), denom(den) {}
	/*
	int Rational::gcm(const Rational& rhs) {
		int half = denom / 2;
		int gcd = 1;
		for (int i = 2; i < half; i++) {
			if (num%i == 0 && denom%i == 0) {
				if (rhs.num%i == 0 && rhs.denom%i == 0) {
					gcd = i;
				}
			}
		}
		return gcd;
	}
	
	Rational& Rational::operator+=(const Rational& rhs) {

	}
	*/
}
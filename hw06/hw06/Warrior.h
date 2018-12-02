#ifndef WARRIOR_H
#define WARRIOR_H

#include "Noble.h"
#include <string>
#pragma once

namespace WarriorCraft{
	class Noble;
	class Warrior {
	public:
		Warrior(const std::string& warriorName, const double warriorStrength);
		std::string getName() const;
		double getStrength() const;
		void setStrength(double aStrength);
		void setLeader(Noble* noble);
		void runaway();
	private:
		std::string name;
		double strength;
		Noble* leader;
	};
}

#endif
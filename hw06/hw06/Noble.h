#ifndef NOBLE_H
#define NOBLE_H
#pragma once

#include "Warrior.h"
#include <string>
#include <vector>

namespace WarriorCraft{
	class Warrior;
	class Noble{
	friend std::ostream& operator<<(std::ostream& os, const Noble& n);
	public:
		Noble(const std::string& nobleName);
		void hire(Warrior& man);
		void remove(Warrior& man);
		double getTotalStrength();
		std::string getName() const;
		void battle(Noble& noble2);
		void reduceStrength(double factor);
	private:
		std::string name;
		std::vector<Warrior*> army;
	};

	std::ostream& operator<<(std::ostream& os, const Noble& n);
}
#endif
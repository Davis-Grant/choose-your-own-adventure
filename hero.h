#ifndef HERO_H
#define HERO_H

#include <iostream>
using namespace std;

#include "character.h"
#include "shield.h"

class Hero : public Character{	
	Shield shield;
public:
	//constructors
	Hero();
	Hero(string);
	Hero(const Hero&);
	//getters
	bool hasShield() const;
	//setters
	void addShield(Shield);
	//combat
	int attack();
	int block(int);
	//operator overload
	friend ostream& operator<<(ostream&, const Hero&);
};

#endif
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
using namespace std;

#include "linkedlist.h"
#include "sword.h"
#define MAX_SWORDS 5

class Character{
protected:
	string name;
	int health;
	LinkedList<Sword> swords;
	Sword sword;
public:
	//constructors
	Character();
	Character(string);
	Character(const Character&);
	//getters
	string getName() const;
	int getHealth() const;
	bool hasSword() const;
	//setters
	void addHealth(int);
	void takeHit(int);
	void addSword(Sword);
	void addSecondSword(Sword);
	void equipSword();
	//combat
	virtual int attack() = 0;
	virtual int block(int) = 0;
	//operator overload
	friend ostream& operator<<(ostream&, const Character&);
};
#endif
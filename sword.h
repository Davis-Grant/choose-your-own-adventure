#ifndef SWORD_H
#define SWORD_H

#include <iostream>
#include <string>
using namespace std;

class Sword{
	string name;
	int damage;
	int block;
public:
    //constructors
	Sword();
	Sword(string, int, int);
	Sword(const Sword&);
    //getter
	string getName() const;
    //combat
	int Strike() const;
	int Parry() const;
    //operator overload
	friend ostream& operator<<(ostream&, const Sword&);
};
#endif
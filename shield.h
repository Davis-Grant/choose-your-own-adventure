#ifndef SHIELD_H
#define SHIELD_H

#include <iostream>
#include <string>
using namespace std;

class Shield{
	string name;
	int block;
public:
    //constructor
	Shield();
	Shield(string, int);
	Shield(const Shield&);
	//getter
	string getName() const;
	//combat
	int Block() const;
	//operator overload
	friend ostream& operator<<(ostream&, const Shield&);
};
#endif
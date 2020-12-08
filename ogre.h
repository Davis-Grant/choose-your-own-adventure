#ifndef OGRE_H
#define OGRE_H

#include "character.h"

class Ogre : public Character{
public:
	//constructor
	Ogre();
	//combat
	int attack();
	int block(int);
	//operator overload
	friend ostream& operator<<(ostream&, const Ogre&);
};

#endif
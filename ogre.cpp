#include "ogre.h"
//constructor
Ogre::Ogre(){
	name = "Bad Guy!";
	health = 6;
	sword = Sword("Hellfire", 9, 4);
}
//combat
int Ogre::attack(){
	return sword.Strike();
}
int Ogre::block(int damage){
	if(damage > 0){
		damage -= sword.Parry();
		health -= damage;	
	}
	return damage;
}
//operator overload
ostream& operator<<(ostream& out, const Ogre& ogre){
	out << ogre.name << ": " << ogre.health << endl;
	if(ogre.hasSword()){
		out << ogre.sword << endl;
	}
	return out;
}
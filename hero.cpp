#include "hero.h"

Hero::Hero(){
	health = 10;
}

Hero::Hero(string newName){
	name = newName;
	health = 10;
}

Hero::Hero(const Hero& rhs){
	health = rhs.health;
	sword = rhs.sword;
	shield = rhs.shield;
}
//getters
bool Hero::hasShield() const{
	return shield.getName() != "";
}
//setters
void Hero::addShield(Shield newShield){
	shield = newShield;
}
//combat
int Hero::attack(){
	return sword.Strike();
}
int Hero::block(int damage){
	if(damage > 0){
		if(hasShield()){
			damage -= shield.Block();
		}
		else if(hasSword()){
			damage -= sword.Parry();
		}
		health -= damage;	
	}
	return damage;
}
//operator overload
ostream& operator<<(ostream& out, const Hero& hero){
	out << hero.name << ": " << hero.health << endl;
	if(hero.hasSword()){
		out << hero.sword << endl;
	}
	if(hero.hasShield()){
		out << hero.shield << endl;
	}
	return out;
}
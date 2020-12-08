#include "sword.h"
//constructors
Sword::Sword() : name(""), damage(0), block(0){ }
Sword::Sword(string newName, int newDamage, int newBlock) : name(newName), damage(newDamage), block(newBlock){ }
Sword::Sword(const Sword& rhs){
	name = rhs.name;
	damage = rhs.damage;
	block = rhs.block;
}
//getter
string Sword::getName() const{
	return name;
}
//combat
int Sword::Strike() const{ 
	return damage; 
}
int Sword::Parry() const{ 
	return block;
}
//operator overload
ostream& operator<<(ostream& out, const Sword& sword){
	out << sword.name << " sword\nAttack damage: " << sword.damage << endl;
	out << "Parry block: " << sword.block;
	return out;
}
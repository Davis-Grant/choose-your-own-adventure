#include "character.h"
//constructors
Character::Character(){
	health = 0;
}
Character::Character(string newName){
	name = newName;
	health = 0;
}
Character::Character(const Character& rhs){
	health = rhs.health;
	sword = rhs.sword;
}
//getters
string Character::getName() const{
	return name;
}
int Character::getHealth() const{
	return health;
}
bool Character::hasSword() const{
	return swords.getLength() > 0;
}
//setters
void Character::addHealth(int newHealth){
	health += newHealth;
}
void Character::takeHit(int newHealth){
	health -= newHealth;
}
void Character::addSword(Sword newSword){
	swords.insert(1, newSword);
	equipSword();
}
void Character::equipSword(){
	int choice;

	cout << name << ", choose a sword" << endl;
	for(int i = 0; i < swords.getLength(); i++){
		cout << i + 1 << ": " << swords.getEntry(i + 1) << endl;
	}
	cin >> choice;
	sword = swords.getEntry(choice);
}
//operator overload
ostream& operator<<(ostream& out, const Character& character){
	out << character.name << ": " << character.health << endl;
	if(character.hasSword()){
		out << character.sword << endl;
	}
	return out;
}
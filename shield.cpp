#include "shield.h"
//constructors
Shield::Shield(){
	name = "";
	block = 0;
}
Shield::Shield(string newName, int newBlock){
	name = newName;
	block = newBlock;
}
Shield::Shield(const Shield& rhs){
	name = rhs.name;
	block = rhs.block;
}
//getter
string Shield::getName() const{
	return name;
}
//combat
int Shield::Block() const{ 
	return block; 
}
//operator overload
ostream& operator<<(ostream& out, const Shield& shield){
	out << shield.name << " shield: " << shield.block;
	return out;
}
#include <iostream>
using namespace std;

#include "hero.h"
#include "ogre.h"

void chest(Hero&);
void bag(Hero&);
void rock(Hero&);
void ogre(Hero&);
void fight(Hero&, Ogre&);

int main(){
	string name;
	cout << "What's you player's name? ";
	cin >> name;
	Hero player(name);

	cout << "***CHOOSE YOUR OWN ADVENTURE***" << endl;
	chest(player);
	bag(player);
	rock(player);
	ogre(player);
	
	return 0;
}

void chest(Hero& hero){
	int userChoice;

	cout << "You're walking through the woods and come upon a chest." << endl << "Do you open it? " << endl;
	cout << "1 - yes 2 - no" << endl;
	cin >> userChoice;

	if(userChoice == 1){
		string dicerName = "Devilish Dicer";
		int dicerDamage = 8;
		int dicerParry = 3;

		Sword dicer(dicerName, dicerDamage, dicerParry);

		cout << endl << "You found the \"" << dicerName << "\" sword!" << endl;
		cout << "It causes " << dicerDamage << " damage when striking and can block " << dicerParry << " damage when parrying." << endl;
		
		hero.addSword(dicer);
	}
	else if(userChoice == 2){
		cout << endl << "As you pass the chest, you stub your toe on it and lose a health point." << endl;
		hero.takeHit(1);
	}
	cout << endl << "Current Stats:" << endl << hero << endl;
}

void bag(Hero& hero){
	int userChoice;

	cout << "As you pass a pond, you notice a bag on the ground." << endl << "Do you open it? " << endl;
	cout << "1 - yes 2 - no" << endl;
	cin >> userChoice;

	if(userChoice == 1){
		int wallBlock = 6;
		string wallName = "Wall of Ice";

		Shield wall(wallName, wallBlock);

		cout << endl << "You found the \"" << wallName << "\" shield!" << endl;
		cout << "It can block " << wallBlock << " damage when struck." << endl;
		
		hero.addShield(wall);
	}
	else if(userChoice == 2){
		cout << endl << "While passing the pond, your foot gets wet and eventually you get a blister. Lose a health point." << endl;
		hero.takeHit(1);
	}

	cout << endl << "Current Stats:" << endl << hero << endl;
}

void rock(Hero& hero){
	int userChoice;

	cout << "As you pass a rock, you notice a sword sticking out of it." << endl << "Do you pull it out? " << endl;
	cout << "1 - yes 2 - no" << endl;
	cin >> userChoice;

	if(userChoice == 1){
		string nailName = "Fingernail of Doom";
		int nailDamage = 10;
		int nailParry = 5;

		Sword nail(nailName, nailDamage, nailParry);

		cout << endl << "You found the \"" << nailName << "\" sword!" << endl;
		cout << "It causes " << nailDamage << " damage when striking and can block " << nailParry << " damage when parrying." << endl;
		
		hero.addSecondSword(nail);
	}
	else if(userChoice == 2){
		cout << endl << "While passing the rock, you stumble and scrape your knee. Lose a health point." << endl;
		hero.takeHit(1);
	}

	cout << endl << "Current Stats:" << endl << hero << endl;
}

void ogre(Hero& hero){
	Ogre badGuy;
	int userChoice;

	cout << "A giant ogre approaches!" << endl << "Do you fight or flee? ";
	cout << "1 - fight 2 - flee" << endl;
	scanf("%d", &userChoice);
	cout << endl;

	if(userChoice == 1){
		if(!hero.hasSword() && !hero.hasShield()){
			hero.takeHit(badGuy.attack());
			cout << "You can't fight or defend yourself. :'(" << endl;
			cout << "Plus, you have a stubbed toe and a blister. You die!" << endl;
		}	
		else{
			fight(hero, badGuy);
			if(hero.getHealth() <= 0 && badGuy.getHealth() <= 0){
				cout << "You die but take the ogre down with you!" << endl;
			}
			else if(hero.getHealth() > 0 && badGuy.getHealth() <= 0){
				cout << "You vanquish the loathsome ogre with sword and shield!!" << endl;
			}
			else if(hero.getHealth() <= 0 && badGuy.getHealth() > 0){
				cout << "Our brave hero has perished against the ogre! :'(" << endl;
			}
		}
	}
	else{
		cout << "As you turn to run, you trip on a log and the ogre steps on you. You die!" << endl;
		hero.takeHit(10);
	}
}

void fight(Hero& hero, Ogre& ogre){
	int userChoice, heroDamage, orcDamage;
	cout << hero << endl << ogre << endl;

	do{
		heroDamage = hero.block(ogre.attack());
		orcDamage = ogre.block(hero.attack());

		if(hero.hasSword() && !hero.hasShield()){
			cout << endl << "You have a sword to fight with! But no shield and can only parry. :(" << endl;
		}
		else if(!hero.hasSword() && hero.hasShield()){
			cout << endl << "You only have a shield and can do the ogre no harm!" << endl;
		}
		else{
			cout << endl << "You're winning!" << endl;
		}

		cout << "The ogre takes " << orcDamage << " and you take " << heroDamage << " damage!" << endl;
		cout << hero << endl << ogre << endl;
	}while(hero.getHealth() > 0 && ogre.getHealth() > 0);
}
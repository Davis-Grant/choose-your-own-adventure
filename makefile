adventureList: driver.o hero.o character.o sword.o shield.o ogre.o
	g++ -o adventureList driver.o hero.o character.o sword.o shield.o ogre.o

driver.o: driver.cpp linkedlist.h hero.h sword.h ogre.h
	g++ -c driver.cpp

hero.o: hero.cpp hero.h shield.h character.h
	g++ -c hero.cpp

ogre.o: ogre.cpp ogre.h character.h
	g++ -c ogre.cpp

character.o: character.cpp character.h sword.h
	g++ -c character.cpp

sword.o: sword.cpp sword.h
	g++ -c sword.cpp

shield.o: shield.cpp shield.h
	g++ -c shield.cpp

clean:
	rm *.o

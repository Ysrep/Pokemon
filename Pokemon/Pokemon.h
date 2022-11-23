#include <iostream>
#include <string>

using namespace std;

class Pokemon {
private :
	string name;
	int hp;
	int attack;
	int defense;
	int attack_spe;
	int defense_spe;
	int speed;
	string type;
	int ev[6];
	int iv[6];
	string nature;
	string talent;

public :
	Pokemon();
};
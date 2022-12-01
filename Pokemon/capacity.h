#include <iostream>
#include <string>
#include "type.h"

using namespace std;

class Capacity {
private :
	Type type;
	int power;
	int accurate;
	string name;
	string effect;

public:
	Capacity(Type t, int p, int a, string n, string e);
};
#pragma once
#include <iostream>
#include <string>
#include "type.h"

using namespace std;

class Capacity {
public :
	Type type;
	int power;
	int accurate;
	string name;
	string effect;
	Capacity();
	Capacity(Type t, int p, int a, string n, string e);
};
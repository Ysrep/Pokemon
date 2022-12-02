#include <iostream>
#include <string>
#include "capacity.h"

using namespace std;

Capacity::Capacity()
{
}

Capacity::Capacity(Type t, int p, int a, string n, string e) {
	type = t;
	power = p;
	accurate = a;
	name = n;
	effect = e;
}
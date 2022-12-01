#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Type {
private :
	string name;
	vector<Type> faiblesse;

public :
	Type();
	Type(string n);
};
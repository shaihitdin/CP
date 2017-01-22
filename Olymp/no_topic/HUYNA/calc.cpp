#include <iostream>
#include <math.h>

using namespace std;


void guide () {
	cout << "Type help for instructions";
}

void print_tutorial () {
	cout << "";
}


int main () {

	guide ();
	
	while (1) {
		string s;
		getline (cin, s);
		stringstream ss = s, ss2 = s;
		ss >> s;
		if (s == "help") {
		
		}				
	}

	
	return 0;
}
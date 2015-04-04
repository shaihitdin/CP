#include <iostream>
#include <stdio.h>
using namespace std;
string s1, s2;
int main() {                        
	s1 = "abcd";
	s1.erase(0, 2);
	cout << s1 << "\n";
}

#include <iostream>
#include <stdio.h>
using namespace std;
int n;
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	cin >> n;
	if (n == 3) {
		cout << "black";
		return 0;
	}
	if (n & 1)	
		cout << "white\n2 2";
	else
		cout << "white\n1 2";
	return 0;
}
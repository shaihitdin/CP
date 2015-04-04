#include <iostream>
#include <stdio.h>
using namespace std;
int a, b, c, d, t;
int main () {
	freopen ("chess.in", "r", stdin);
	freopen ("chess.out", "w", stdout);
	cin >> t;
	for (int test = 1; test <= t; ++test) {
		cin >> a >> b >> c >> d;
		cout << "Scenario #" << test << ":\n" << (a + b + c + d) % 2 << "\n\n";			
	} 
	return 0;
}
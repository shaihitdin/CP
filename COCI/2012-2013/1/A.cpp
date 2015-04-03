#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
string s, t;
bool u[256];
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	cin >> s;
	t = "CAMBRIDGE";
	for (auto it : t)
		u[it] = 1;
	for (auto it : s) {
		if (!u[it])
			cout << it;
	}
	return 0;
}
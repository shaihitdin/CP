#include <bits/stdc++.h>

using namespace std;

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	
	int n = 1000;

	int x = 1e9 / 3;
	int y = x + 1;

	int part = n / 4;
	
	for (int i = 0; i < part; i += 2) {
		cout << 1 << "," << x << ",";
	}
	
	for (int i = 0; i < part; i += 2) {
		cout << x << "," << 1 << ",";
	}
	
	for (int i = 0; i < part; i += 2) {
		cout << 1 << "," << y << ",";
	}
	
	for (int i = 0; i < part; i += 2) {
		cout << y << "," << 1 << ",";
	}

	return 0;
}
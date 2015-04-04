#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int a, b, z;
int ans;
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	cin >> a >> b;
	z = (a - b);
	if (z == 0) {
		cout << "infinity";
		return 0;
	}
	int i = 1;
	for (; i * i < z; ++i) {
		if (z % i == 0 && i > b) {
			++ans;
			cerr << i << " ";
		}
		if (z % (z / i) == 0 && (z / i) > b) {
			++ans;
			cerr << (z / i) << " ";
		}
	}
	if (z % i == 0 && i > b) {
		cerr << i << " ";
		++ans;
	}
	cout << ans;
   	return 0;
}
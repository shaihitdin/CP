#include <bits/stdc++.h>

using namespace std;

int xp, yp, xv, yv;

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> xp >> yp >> xv >> yv;

	if (xp <= xv && yp <= yv) {
		cout << "Polycarp";
	} else if (xv <= xp && yv <= yp) {
		cout << "Vasiliy";
	}
	else {
		if (xp + yp <= max (xv, yv)) {
			cout << "Polycarp";
		} else {
			cout << "Vasiliy";
		}
	}
	return 0;
}
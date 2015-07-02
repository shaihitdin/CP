#include <bits/stdc++.h>

using namespace std;


inline bool rec (const int &turn, const int &odd, const int &even, const int &LEFT) {
	if (LEFT == 0)
		return odd & 1;
	if (turn == 1) {
		if (even)
			if (rec (turn ^ 1, odd, even - 1, LEFT - 1))
				return 1;
		if (odd)
			if (rec (turn ^ 1, odd - 1, even, LEFT - 1))
				return 1;
		return 0;
	} else {
		if (even)
			if (!rec (turn ^ 1, odd, even - 1, LEFT - 1))
				return 0;
		if (odd)
			if (!rec (turn ^ 1, odd - 1, even, LEFT - 1))
				return 0;
		return 1;
	}
}

int main () {
    #ifndef ONLINE_JUDGE
	freopen ("in", "r", stdout);
	freopen ("out", "w", stdout);
	#endif

	for (int odd = 0; odd <= 14; ++odd) {
		for (int even = 0; even <= 14; ++even) {
			for (int LEFT = 1; LEFT <= odd + even; ++LEFT) {
				cout << "odd == " << odd << " & " << "even == " << even << " & " << "LEFT == " << LEFT << " and result is " << rec (1, odd, even, LEFT) << "\n";
			}
			cout << "\n";
		}
	}

	return 0;
}
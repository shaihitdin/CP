#include <bits/stdc++.h>

using namespace std;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	srand (time (0));

	cout << "{";

	for (int i = 0; i < 500; ++i) {
		cout << i;
		if (i + 1 != 1500) {
			cout << ",";
		} else {
			cout << "}\n";
		}
	}
	for (int i = 500; i < 1000; ++i) {
		cout << 1000 + i;
		if (i + 1 != 1500) {
			cout << ",";
		} else {
			cout << "}\n";
		}
	}
	for (int i = 1000; i < 1500; ++i) {
		cout << 3000 + i;
		if (i + 1 != 1500) {
			cout << ",";
		} else {
			cout << "}\n";
		}
	}

	for (int i = 0; i < 500; ++i) {
		cout << i;
		if (i + 1 != 1500) {
			cout << ",";
		} else {
			cout << "}\n";
		}
	}
	for (int i = 500; i < 1000; ++i) {
		cout << 1000 + i;
		if (i + 1 != 1500) {
			cout << ",";
		} else {
			cout << "}\n";
		}
	}
	for (int i = 1000; i < 1500; ++i) {
		cout << 3000 + i;
		if (i + 1 != 1500) {
			cout << ",";
		} else {
			cout << "}\n";
		}
	}

	return 0;
}
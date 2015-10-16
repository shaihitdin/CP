#include <bits/stdc++.h>

using namespace std;

int main () {

	#ifdef LOCAL
	freopen ("in", "w", stdout);
	#endif

	int n = 2e5;

	srand (time (0));
	
	for (int i = 1; i <= n; ++i) {
		cout << char ('a' + (rand () % 26));
	}

	cout << endl;
	
	for (int i = 1; i <= n; ++i) {
		cout << char ('a' + (rand () % 26));
	}

	cout << endl;
	
	return 0;
} 
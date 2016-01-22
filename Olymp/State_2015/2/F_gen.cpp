#include <bits/stdc++.h>

using namespace std;

int main () {

	#ifdef LOCAL
	freopen ("in", "w", stdout);
	#endif

	int n = 30, k = 100;

	cout << n << " " << k << "\n";
	
	for (int i = 1; i <= n; ++i) {
		cout << rand () << " ";
	}

	return 0;
}
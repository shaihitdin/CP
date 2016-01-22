#include <bits/stdc++.h>

using namespace std;

int main () {

	#ifdef LOCAL
	freopen ("in", "w", stdout);
	#endif

	srand (time (0));
	
	int n = 10;

	cout << n << "\n";
	
	for (int i = 1; i <= n; ++i) {
		cout << rand () << " " << 1 + (rand () % 10000) << "\n";
	}
	
	return 0;
}
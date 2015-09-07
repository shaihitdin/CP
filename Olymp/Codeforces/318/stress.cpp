#include <bits/stdc++.h>

using namespace std;

int main () {

	#ifdef LOCAL
	freopen ("in", "w", stdout);
	#endif

	int n = 3e4;
	int m = n / 3;
	cout << n << " " << n / 3 << "\n";

	for (int i = 1; i <= n; ++i) {
		cout << n << " ";
	}
	
	cout << "\n";

	for (int i = 1; i <= n; ++i) {
		cout << n << " ";
	}
	
	cout << "\n";

	while (m--) {
		cout << 1 << " " << 2 << "\n";
	}
	
	return 0;
}
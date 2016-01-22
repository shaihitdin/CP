#include <bits/stdc++.h>

using namespace std;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	int n = 100, m;
	m = (n * (n - 1)) / 2;
	cout << n << " " << m << endl;

	int k = 10;
	int can_do = k * (k - 1) / 2;

	for (int i = 1; i <= k; ++i) {
		cout << 1 << " " << 1 << endl;
	}

	for (int i = 1; i <= can_do; ++i) {
		cout << 2 << " " << 0 << endl;
	}

	for (int i = 1; i <= n - 1 - k; ++i) {
		cout << 3 << " " << 1 << endl;
	}
	
	for (int i = 1; i <= m - (k + can_do + n - 1 - k); ++i) {
		cout << 4 << " " << 0 << endl;
	}
	
	return 0;
}
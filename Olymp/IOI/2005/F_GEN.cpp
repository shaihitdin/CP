#include <bits/stdc++.h>

using namespace std;

int main () {

	freopen ("in", "w", stdout);

	int n, k;

	n = 100;
	k = 50;

	cout << n << " " << k << "\n";

	for (int i = 1; i <= k; ++i) {
		cout << 1 << " " << i - 1 << " " << 1 << "\n";
	}
	for (int i = k + 1; i <= n; ++i) {
		cout << 1000 << " " << k << " " << 1000 << "\n";
	}

	return 0;
}
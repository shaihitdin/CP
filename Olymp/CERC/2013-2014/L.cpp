#include <bits/stdc++.h>

using namespace std;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int t;
	
	cin >> t;

	while (t--) {
		long long n;
		cin >> n;
		cout << (1ll << n) - 1 << "\n";
	}

	return 0;
}
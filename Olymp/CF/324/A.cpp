#include <bits/stdc++.h>

using namespace std;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int n, t;
	
	cin >> n >> t;

	if (t == 10) {
		if (n == 1) {
			cout << -1;
		} else {
			cout << 1;
			for (int i = 2; i <= n; ++i)
				cout << 0;
		}
	} else {
		for (int i = 1; i <= n; ++i) {
			cout << t;
		}
	}

	return 0;
}
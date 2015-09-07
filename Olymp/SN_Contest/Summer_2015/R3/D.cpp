#include <bits/stdc++.h>

using namespace std;

const int N = 101;

int n, x[N], y[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n;
	int ans = 1e9;

	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
		for (int j = 1; j < i; ++j) {
			ans = min (ans, max (abs (x[i] - x[j]), abs (y[i] - y[j])) * max (abs (x[i] - x[j]), abs (y[i] - y[j])));
		}
	}

	cout << ans;
	
	return 0;
}
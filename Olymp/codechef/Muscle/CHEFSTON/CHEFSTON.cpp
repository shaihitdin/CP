#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1e5 + 1;
long long x[N], y[N];
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio(0);
	int t, n, k;
	cin >> t;
	for (int test = 1; test <= t; ++test) {
		cin >> n >> k;
		long long profit = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> x[i];
		}
		for (int i = 1; i <= n; ++i) {
			cin >> y[i];
			profit = max (profit, (k / x[i]) * y[i]);
		}
		cout << profit << "\n";
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 1001;

typedef long long ll;

ll ans = 1e12;
ll x[N], y[N], n;

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
		if (x[i] > y[i]) {
			swap (x[i], y[i]);
		}
	}
	for (int len = 1; len < N; ++len) {
		ll sum = 0;
		for (int i = 1; i <= n; ++i) {
			if (len < x[i]) {
				sum = 1e12;
				break;
			}
			else if (len < y[i]) {
				sum += y[i];
			}
			else {
				sum += x[i];
			}
		}
		ans = min (ans, sum * len);
	}
	cout << ans;
	return 0;
}
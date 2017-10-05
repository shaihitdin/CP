#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int t;
	cin >> t;

	for (int test = 1; test <= t; ++test) {
		cout << "Case #" << test << ": ";
		long long d, n, k[N], s[N];
		cin >> d >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> k[i] >> s[i];
		}
		double ans = 1e55;
		for (int i = 1; i <= n; ++i) {
			double T = (d - k[i]) / ((double)s[i]);
			ans = min (ans, d / T);
		}
		cout << fixed;
		cout << setprecision (7);
		cout << ans << "\n";
	}
	
	return 0;
}
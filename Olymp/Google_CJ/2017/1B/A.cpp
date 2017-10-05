#include <bits/stdc++.h>

using namespace std;

const int N = 1010;



int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif


	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int t;
	cin >> t;

	for (int _ = 1; _ <= t; ++_) {
		cout << "Case #" << _ << ": ";
		int n;
		double k[N], s[N], d;
		cin >> d >> n;

		for (int i = 1; i <= n; ++i)
			cin >> k[i] >> s[i];
		double l = 0, r = 2e9;
		for (int cnt = 0; cnt <= 100; ++cnt) {
			double x = (r + l) / 2;
			bool ok = 1;
			for (int i = 1; i <= n; ++i) {
				if ((d - k[i]) / s[i] > d / x)
					ok = 0;
			}
			if (ok)
				l = x;
			else
				r = x;
		}
		cout << fixed;
		cout << setprecision (6);
		cout << l << "\n";
	}


	return 0;
}
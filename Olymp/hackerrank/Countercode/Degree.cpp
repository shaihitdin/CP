#include <bits/stdc++.h>

using namespace std;

const int N = 50020;

int u[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;
		memset (u, 0, sizeof (u));
		if (n == 1) {
			cout << n << " " << m - 1 << "\n";
			continue;
		}
		int l = 1, r = n;
		for (int i = 1; i < m; ++i) {
			if (i & 1) {
				if (u[l] < u[1]) {
					++u[l];
					++l;
				} else {
					++u[1];
					l = 2;
				}
			} else {
				if (u[r] < u[n]) {
					++u[r];
					--r;
				} else {
					++u[n];
					r = n - 1;
				}
			}
		}
		if (m & 1) {
			if (u[l] < u[1]) {
				cout << l << " " << u[l] << "\n";
			} else {
				cout << 1 << " " << u[1] << "\n";
			}
		} else {
			if (u[r] < u[n]) {
				cout << r << " " << u[r] << "\n";
			} else {
				cout << n << " " << u[n] << "\n";
			}
		}
	}

	return 0;
}
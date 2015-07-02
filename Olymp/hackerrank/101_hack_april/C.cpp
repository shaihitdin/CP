#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3010;

const ll inf = 1e18;

ll d[N][N];

int test, n, d, m[N];

int main () {
    /*
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	*/
	cin >> test;

	for (int t = 1; t <= test; ++t) {
		
		cin >> n >> d;

		for (int i = 1; i <= n; ++i)
			cin >> m[i];

		/*
		
		sort (m + 1, m + n + 1);
		
		ll ans = 0;

		for (int i = n; i > 1; --i)
			ans = max (ans, (n - i + 1) * 1ll * d + m[i]);
		
		ans = max (ans, (n - 1) * 1ll * d + m[1]);

		cout << ans << "\n";
		*/

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				d[i][j] = inf;
		d[1][1] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				d[i][j + 1] = min (d[i][j + 1], d[i][j] + d);
				d[
			}
		}
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 105;

typedef long long ll;

int n, l, r;

set <ll> d[N][N];

int a[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);

	cin >> n >> l >> r;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	d[0][0].insert (0);

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < n; ++j) {
			for (auto it : d[i][j]) {
				ll sum = 0;
				for (int k = j + 1; k <= n; ++k) {
					sum += a[k];
					d[i + 1][k].insert (it | sum);
					while (d[i + 1][k].size () > 100)
						d[i + 1][k].erase (d[i + 1][k].find (*d[i + 1][k].rbegin ()));
				}
			}
		}
	}
		
	ll ans = 1e18;

	for (int i = l; i <= r; ++i)
		for (auto it : d[i][n])
			ans = min (ans, it);

	cout << ans << "\n";
		
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;
int a[N], b[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int t;
	cin >> t;

	while (t--) {
		int n, m, x;
		cin >> n >> m >> x;
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		for (int i = 1; i <= m; ++i) {
			cin >> b[i];
			b[i] += b[i - 1];
			b[i] = min (b[i], x + 1);
		}
		for (int s = 0, i = 0; i <= n && s <= x; s += a[++i]) {
			int sc = upper_bound (b + 1, b + m + 1, x - s) - b;
			ans = max (ans, i + sc - 1);
		}
		cout << ans << "\n";
	}

	return 0;
}
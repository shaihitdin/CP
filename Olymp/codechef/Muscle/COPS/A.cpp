#include <bits/stdc++.h>

using namespace std;

bool u[101];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);

	int t;
	
	cin >> t;

	while (t--) {
		memset (u, 0, sizeof (u));
		int m, x, y;
		cin >> m >> x >> y;
		while (m--) {
			int st;
			cin >> st;
			for (int j = max (1, st - x * y); j <= min (100, st + x * y); ++j)
				u[j] = 1;
		}
		int ans = 0;
		for (int i = 1; i <= 100; ++i)
			ans += !u[i];
		cout << ans << "\n";
	}

	return 0;
}
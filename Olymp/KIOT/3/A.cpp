#include <bits/stdc++.h>

using namespace std;


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> k;
	for (int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].emplace_back (y);
		g[y].emplace_back (x);
	}

	l = 0, r = n - 1;

	while (r - l > 1) {
		int mid = (r + l) >> 1;
		for (int i = 1; i + mid - 1 <= n; ++i) {
			
		}
	}

	
	return 0;
}
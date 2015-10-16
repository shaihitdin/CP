#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

int d[N], h[N], n, m;

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);

	cin >> n >> m;

	for (int i = 1; i <= m; ++i)
		cin >> d[i] >> h[i];
	
	for (int i = 1; i < m; ++i) {
		if (d[i + 1] - d[i] < abs (h[i] - h[i + 1])) {
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
		
	int now = h[1] + (d[1] - 1);
	int mx = now;

	for (int i = 1; i < m; ++i) {
		int l = 0, r = d[i + 1] - d[i] + 1;
		while (r - l > 1) {
			int mid = (r + l) >> 1;
			if (h[i] + mid - (d[i + 1] - (d[i] + mid)) <= h[i + 1])
				l = mid;
			else
				r = mid;
		}
		mx = max (mx, h[i] + l);
	}

	mx = max (mx, n - d[m] + h[m]);

	cout << mx;

	return 0;
}
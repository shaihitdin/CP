#include <bits/stdc++.h>

using namespace std;

map <int, bool> Map;

const int N = 1001;
int ans, w[N], m, t, r;
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	cin >> m >> t >> r;
	for (int i = 1; i <= m; ++i)
		cin >> w[i];
	for (int i = 1; i <= m; ++i) {
		int need = r;
		for (int j = w[i] - 1; j >= w[i] - t; --j)
			need -= Map[j];
		for (int j = w[i] - 1; need && j >= w[i] - t; --j) {
			if (Map[j])	continue;
			Map[j] = 1;
			++ans;
			--need;
		}
		if (need) {
			cout << -1;
			return 0;
		}
	}
	cout << ans;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int n, m, temp, ans;

const int N = 1e6 + 1;

int main () {
	#ifndef ONLINE_JUDGE	
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	cin >> n >> m;

	for (int i = 0; i < N; ++i) {
		int u1 = i * 2, u2 = i;
		if (n - u1 < 0 || m - u2 < 0)
			break;
		int tmpn = n - u1, tmpm = m - u2;
		temp = min (tmpn, tmpm / 2);
		ans = max (ans, i + temp);
	}
	cout << ans;
	return 0;
}
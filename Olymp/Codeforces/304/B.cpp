#include <bits/stdc++.h>

using namespace std;

int cnt[10000];

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio (0);

	int n;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		++cnt[x];
	}

	int now = 0, ans = 0;
	
	for (int i = 1; i < 10000; ++i) {
		cnt[i] += now;
		ans += now;
		now = max (0, cnt[i] - 1);
	}

	cout << ans << "\n";

	return 0;
}
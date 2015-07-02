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
		cin >> cnt[i];
	}

	sort (cnt + 1, cnt + n + 1);
	
	int ans = 0;
	
	for (int i = 1; i <= n; ++i)
		if (cnt[i] == cnt[i - 1])
			++ans, cnt[i] += 1;

	cout << ans << "\n";

	return 0;
}
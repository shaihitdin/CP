#include <bits/stdc++.h>

using namespace std;

const int N = 3e6 + 100;

int n, cnt[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		++cnt[x];
	}
	
	int ans = 0;
	
	for (int i = 0; i < N - 1; ++i) {
		cnt[i + 1] += cnt[i] / 2;
		cnt[i] = cnt[i] & 1;
		ans += cnt[i];
	}
	
	cout << ans;
	
	return 0;
}
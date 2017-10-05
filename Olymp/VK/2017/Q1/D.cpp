#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 100;

int cnt[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n, k;

	cin >> n >> k;

	while (n--) {
		int x;
		cin >> x;
		++cnt[x];
	}

	
	long long ans = 0;

	for (int i = 0; i <= 1e4; ++i) {
		for (int j = i; j <= 1e4; ++j) {
			if (__builtin_popcount (i ^ j) == k) {
				if (i == j) {
					ans = ans + (cnt[i] * 1ll * (cnt[i] - 1)) / 2;
				} else {
					ans = ans + (cnt[i] * 1ll * cnt[j]);
				}
			}
		}
	}
	
	cout << ans;
	return 0;
}
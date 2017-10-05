#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int ll

const int N = 1e5 + 100;

int a[N];
int used[N], total[N], cnt[N];


inline int guess_pow (int x) {
	for (int y = 0;; ++y) {
		if ((1ll << y) == x)
			return y;
	}
}

main () {

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
		if (__builtin_popcount (x) == 1) {
			cnt[guess_pow (x)]++;
		}
	}
	
	for (int i = 1; i < 66; ++i) {
		if (cnt[i] > cnt[i - 1]) {
			cout << -1;
			return 0;
		}
	}			
	
	
	
	return 0;
}
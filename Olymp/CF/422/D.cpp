#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 100, bpr = 1e9 + 7;

typedef long long ll;

ll d[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int l, r, t;
	cin >> t >> l >> r;

	for (int i = 1; i < N; ++i)
		d[i] = i * 1ll * (i - 1) / 2;

	for (int i = 1; i < N; ++i) {
		for (int j = i + i, x = 2, n = i + i; j < N; j += i, ++x, n += i) {
			d[n] = min (d[n], d[i] + x * 1ll * (x - 1) / 2 * i);
		}
	}	

	ll ans = 0, pw = 1;
	
	for (int i = 1; i < N; ++i)
		d[i] %= bpr;
	
	while (l <= r) {
		ans = (ans + d[l] * 1ll * pw) % bpr;
		pw = pw * t % bpr;
		++l;
	}
	
	cout << ans;
	return 0;
}
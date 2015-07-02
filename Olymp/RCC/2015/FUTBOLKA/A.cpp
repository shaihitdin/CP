#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll bpr = 1e9 + 7;

const int N = 151;

inline ll bin_pow (const ll &el, const ll &p) {
	if (!p)
		return 1;
	if (p & 1)
		return (el * 1ll * bin_pow (el, p - 1)) % bpr;
	ll mid = bin_pow (el, p / 2);
	return (mid * 1ll * mid) % bpr;
}

ll f[N];

bool u[N][N];

int main () {
    /*
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	*/
	ios_base :: sync_with_stdio (0);

	int t;

	cin >> t;
	
	f[0] = 1;
	for (int i = 1; i < N; ++i)
		f[i] = (f[i - 1] * 1ll * i) % bpr;
	
	while (t--) {
		int n, k;
		string s;
		cin >> n >> k;
		cin >> s;
		ll cnt1 = 0, cnt2 = 0;
		for (auto it : s)
			if (it == '1')
				++cnt1;
			else
				++cnt2;
		memset (u, 0, sizeof (u));
		u[cnt2][cnt1] = 1;
		for (int cnt = n; cnt > k; --cnt) {
			for (int i = 0; i <= cnt; ++i) {
				int j = cnt - i;
				if (!u[i][j])
					continue;
				if (i >= 2)
					u[i - 2][j] = 1;
				if (j >= 3)
					u[i][j - 3] = 1;
			}
		}
		ll ans = 0;
		for (int i = 0; i <= k; ++i) {
			int j = k - i;
			if (!u[i][j])
				continue;
			ll res = f[k];
			res = (res * 1ll * bin_pow (f[j], bpr - 2)) % bpr;
			res = (res * 1ll * bin_pow (f[k - j], bpr - 2)) % bpr;
			ans += res;
			ans %= bpr;
		}
		cout << ans << "\n";
	}
	
	return 0;
}
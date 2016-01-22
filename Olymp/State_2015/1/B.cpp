#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100, oo = 1e9;

ll x[N], y[N], z[N], pref[N][8], suff[N][8];
int n;

inline bool bit (int mask, int pos) {
	return (mask >> pos) & 1;
}

inline ll calc (int pos, int mask) {
	ll res = 0;
	if (bit (mask, 0))
		res += x[pos];
	else
		res -= x[pos];
	if (bit (mask, 1))
		res += y[pos];
	else
		res -= y[pos];
	if (bit (mask, 2))
		res += z[pos];
	else
		res -= z[pos];
	return res;
}

int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif
	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> x[i] >> y[i] >> z[i];
	for (int i = 0; i < 8; ++i) {
		pref[0][i] = -oo;
		for (int j = 1; j <= n; ++j)
			pref[j][i] = max (calc (j, i), pref[j - 1][i]);
		suff[n + 1][i] = -oo;
		for (int j = n; j >= 1; --j)
			suff[j][i] = max (calc (j, i), suff[j + 1][i]);
	}		
	int nn = (1 << 3) - 1;
	ll ans = -oo;	
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < 8; ++j)
			ans = max (ans, calc (i, j) + max (pref[i - 1][nn ^ j], suff[i + 1][nn ^ j]));
	cout << ans << "\n\n\n";
	
	return 0;
}
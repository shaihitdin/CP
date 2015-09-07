#include <bits/stdc++.h>

using namespace std;

const int N = 20, bpr = 1e9 + 7;

#define prev ca1231231n

inline bool bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;
}

inline void add (int &a, const int &b) {
	a += b;
	if (a >= bpr)
		a -= bpr;
}

int a[N], now[N], nxt[1 << 17][N], d[N][1 << 17], prev[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif	
	
	int t;

	cin >> t;

	while (t--) {
		int n, k, l;
		cin >> n >> k >> l;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		memset (nxt, 0, sizeof (nxt));
		for (int i = 0; i < (1 << n); ++i) {
			prev[0] = i & 1;
			for (int j = 1; j < n; ++j)
				prev[j] = prev[j - 1] + bit (i, j);

			for (int add_val = 1; add_val <= k; ++add_val) {
				now[0] = prev[0];
				now[0] |= (add_val == a[0]);
				nxt[i][add_val] = now[0];
				for (int j = 1; j < n; ++j) {
					now[j] = now[j - 1];
					if (prev[j] > now[j - 1] || (add_val == a[j] && prev[j - 1] == now[j - 1])) {
						now[j] += 1;
						nxt[i][add_val] |= (1 << j);
					}
				}
			}
		}
		
		memset (d, 0, sizeof (d));
		d[0][0] = 1;
		for (int i = 0; i < n; ++i) {
			for (int mask = 0; mask < (1 << n); ++mask) {
				for (int new_el = 1; new_el <= k; ++new_el) {
					add (d[i + 1][nxt[mask][new_el]], d[i][mask]);
				}
			}
		}
		
		int ans = 0;
		for (int mask = 0; mask < (1 << n); ++mask)
			if (__builtin_popcount (mask) == l)
				add (ans, d[n][mask]);

		cout << ans << "\n";
	}
	return 0;
}
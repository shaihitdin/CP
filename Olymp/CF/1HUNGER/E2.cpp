#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 10, bpr = 1e9 + 7;


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif


	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	register char b[N][18];
	register float ans[N], precalc[61];
	register char ans_c[N][18];
	register char c[N][18];
	register bool prime[61];
	register int n, m, a[N];
	register char pw[61][7];
	register char precalc_div[61][61], precalc_mult[61][61];
	register char kth_prime[61];
	register bool divv[N][61];

	memset (b, 0, sizeof (b));
	memset (ans, 0, sizeof (ans));
	memset (precalc, 0, sizeof (precalc));
	memset (ans_c, 0, sizeof (ans_c));
	memset (c, 0, sizeof (c));
	memset (pw, 0, sizeof (pw));
	memset (precalc_div, 0, sizeof (precalc_div));
	memset (precalc_mult, 0, sizeof (precalc_mult));
	memset (prime, 1, sizeof (prime));
	memset (divv, 0, sizeof (divv));

	int cnt = 0;
	
	prime[1] = 0;

	for (int i = 2; i <= 60; ++i) {
		for (int j = 2; j * j <= i; ++j) {
			if (i % j == 0)
				prime[i] = 0;
		}
		if (prime[i])
			kth_prime[++cnt] = i;
	}
	
	for (int i = 1; i <= 60; ++i)
		precalc[i] = log2 (i);
	
	scanf ("%d%d", &n, &m);
	
	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);

	for (int i = 1; i <= n; ++i) {
		int x = a[i];
		while (x != 1) {
			for (int j = 1; j <= cnt; ++j) {
				int k = kth_prime[j];
				if (x % k == 0) {
					++c[i][j];
					x /= k;
					break;
				}
			}
		}
	}
	
	for (int i = 1; i <= 60; ++i) {
		pw[i][0] = 1;
		for (int j = 1; j <= 6; ++j) {
			if (pw[i][j - 1] * 1ll * i > 60)
				break;
			pw[i][j] = pw[i][j - 1] * i;
		}
	}
	
	for (int i = 1; i <= 60; ++i)
		for (int j = 1; j <= i; ++j)
			precalc_div[i][j] = i / j;
	
	for (int i = 1; i <= 60; ++i)
		for (int j = 1; j <= 60; ++j)
			precalc_mult[i][j] = i * j;
	
	for (int len = 1; len <= n; ++len) {
		int mxpos = 1;
		for (int i = len; i <= n; ++i) {
			int j = i - len + 1, lcm = 1;
			if (divv[j][a[i]] || a[i] == 1) {
				if (ans[mxpos] > ans[j])
					mxpos = j;
				continue;
			}
			for (int it = 1; it <= cnt; ++it) {
				int k = kth_prime[it];
				if (c[i][it]) {
					lcm = precalc_mult[lcm][pw[k][min (b[j][it], c[i][it])]];
					b[j][it] = max (b[j][it], c[i][it]);
				}
			}
			int x = a[i] / lcm;
			ans[j] += precalc[x];
			while (x != 1) {
				for (int it = 1; it <= cnt; ++it) {
					int k = kth_prime[it];
					if (x % k == 0) {
						x /= k;
						for (int l = 60 / k; l >= 1; --l)
							if (divv[j][l])
								divv[j][l * k] = 1;
						divv[j][k] = 1;
						break;
					}
				}
			}
			if (ans[mxpos] > ans[j])
				mxpos = j;
		}
		for (int it = 1; it <= cnt; ++it) {
			ans_c[len][it] = b[mxpos][it];
		}
	}
	
	while (m--) {
		int x;
		scanf ("%d", &x);
		int now = 1;
		for (int i = 1; i <= cnt; ++i) {
			int j = kth_prime[i];
			now = (now * 1ll * pw[j][ans_c[x][i]]) % bpr;
		}
		printf ("%d\n", now);
	}
	
	return 0;
}
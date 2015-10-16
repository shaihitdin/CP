#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 10, bpr = 1e9 + 7;

int b[N][19];
double ans[N], precalc[61];
int ans_c[N][19];
int c[N][19];
bool prime[61];
int n, m, a[N];
int pw[61][7];
int kth_prime[19];
bool divv[N][61];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif


	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	memset (prime, 1, sizeof (prime));

	int cnt = 0;
	
	for (int i = 2; i <= 60; ++i) {
		for (int j = 2; j * j <= i; ++j) {
			if (i % j == 0)
				prime[i] = 0;
		}
		if (prime[i])
			kth_prime[++cnt] = i;
	}
	
	for (int i = 1; i <= 60; ++i)
		precalc[i] = log (i);
	
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
			if (pw[i][j - 1] * i > 60)
				break;
			pw[i][j] = pw[i][j - 1] * i;
		}
	}

	for (int len = 1; len <= n; ++len) {
		int mxpos = 1;
		for (int i = len; i <= n; ++i) {
			int j = i - len + 1, gcd = 1;
			if (divv[j][a[i]] || a[i] == 1) {
				if (ans[mxpos] > ans[j])
					mxpos = j;
				continue;
			}
			for (int it = 1; it <= cnt; ++it) {
				int k = kth_prime[it];
				if (c[i][it]) {
					gcd *= pw[k][min (b[j][it], c[i][it])];
					b[j][it] = max (b[j][it], c[i][it]);
				}
			}
			int x = a[i] / gcd;
			ans[j] += precalc[x];
			while (x != 1) {
				for (int it = 1; it <= cnt; ++it) {
					int k = kth_prime[it];
					if (x % k == 0) {
						x /= k;
						for (int l = 2; l * k <= 60; ++l)
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

		for (int it = 1; it <= cnt; ++it)
			ans_c[len][it] = b[mxpos][it];
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
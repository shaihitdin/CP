#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int n, m, a, b, x, p;
int d1[1 << N][N], d2[1 << N][N];
int d[N][N];

inline bool bit (int mask, int pos) {
	return (mask >> pos) & 1;
}


inline int bin_mult (int a, int b) {
	int res = 0;
	while (b) {
		if (b & 1)	
			res += a, b ^= 1; 
		a += a, b >>= 1;
		if (a >= p)
			a -= p;
		if (res >= p)
			res -= p;
	}
	return res;
}

int main () {

	freopen ("mitm.in", "r", stdin);
	freopen ("mitm.out", "w", stdout);
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> m >> a >> b >> x >> p;
	
	int f1, f2;
	
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		++d[u][v];
		++d[v][u];
		if (x == i) {
			f1 = u;
			f2 = v;
		}
	}
	
	d1[1 << (a - 1)][a - 1] = 1;
	d2[1 << (b - 1)][b - 1] = 1;

	for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0; j < n; ++j) {
			if (bit (i, j)) {
				for (int k = 0; k < n; ++k) {
					if (!bit (i, k)) {
						d1[i | (1 << k)][k] += bin_mult (d1[i][j], d[j][k]);
						if (d1[i | (1 << k)][k] >= p)
							d1[i | (1 << k)][k] -= p;
					}
				}
			}
		}
	}
	
	for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0; j < n; ++j) {
			if (bit (i, j)) {
				for (int k = 0; k < n; ++k) {
					if (!bit (i, k)) {
						d2[i | (1 << k)][k] += bin_mult (d2[i][j], d[j][k]);
						if (d2[i | (1 << k)][k] >= p)
							d2[i | (1 << k)][k] -= p;
					}
				}
			}
		}
	}
	
	
	for (int i = 0; i < n; ++i) {
		for (int mask = 0; mask < (1 << n); ++mask) {
			if (!bit (mask, i)) {
				for (int j = 0; j < n; ++j) {
					d2[mask | (1 << i)][j] += d2[mask][j];
					if (d2[mask | (1 << i)][j] >= p)
						d2[mask | (1 << i)][j] -= p;
				}
			}
		}
	}
	
	int ans = 0;
	
	for (int mask = 0; mask < (1 << n); ++mask) {
		ans = (ans + (d1[mask][f1] * 1ll * d2[((1 << n) - 1) ^ mask][f2])) % p;
		ans = (ans + (d1[mask][f2] * 1ll * d2[((1 << n) - 1) ^ mask][f1])) % p;
	}
	
	cout << ans;
	
	return 0;
}
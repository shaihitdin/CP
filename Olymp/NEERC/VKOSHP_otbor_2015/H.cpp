#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9 + 7, N = 21;

int d[(1 << 19)][20];
int b[N][N];
int num_athlete[N];
int a[N];

inline bool bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;
}

int main () {

	freopen ("run.in", "r", stdin);
	freopen ("run.out", "w", stdout);

	int n, k;
	
	cin >> n >> k;

	for (int i = 1; i <= k; ++i)
		cin >> a[i];
	
	int now = 0;

	num_athlete[0] = 1;
	now = 1;
	for (int i = 1; i <= k; ++i) {
		for (int j = now; j < now + a[i]; ++j)
			num_athlete[j] = i;
		now += a[i];
	}
	
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			cin >> b[i][j];
		}
	}
	
	for (int i = 0; i < (1 << n); ++i)
		for (int j = 0; j <= n; ++j)
			d[i][j] = oo;
	
	d[0][0] = 0;

	for (int mask = 0; mask < (1 << n); ++mask) {
		if (num_athlete[__builtin_popcount (mask) + 1] != num_athlete[__builtin_popcount (mask)]) {
			for (int i = 1; i <= n; ++i)
				d[mask][0] = min (d[mask][0], d[mask][i] + b[i][0]);
			for (int i = 1; i <= n; ++i)
				d[mask][i] = oo;
		}
		for (int i = 0; i <= n; ++i) {
			if (i == 0 || (bit (mask, i - 1))) {
				for (int j = 1; j <= n; ++j) {
					if (!bit (mask, j - 1))
						d[mask | (1 << (j - 1))][j] = min (d[mask][i] + b[i][j], d[mask | (1 << (j - 1))][j]);
				}
			}
		}
	}
	
	cout << d[(1 << n) - 1][0];
	
	return 0;
}
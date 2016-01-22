#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int N = 18;

inline bool bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;
}
int cdf[1 << 16];
ld d[1 << 16][N];
int n, c, m;
ld p[N];
int b[N];

inline ld calc (int mask, int i) {
	if (cdf[mask] > m)
		return 0;
	if (i == c)
		return 1;
	if (d[mask][i] == d[mask][i])
		return d[mask][i];
	ld val = 0;
	for (int j = 0; j < n; ++j) {
		if (!bit (mask, j)) {
			val = max (val, calc (mask | (1 << j), i + 1) * p[j] + calc (mask | (1 << j), i) * (1 - p[j]));
		}
	}
	d[mask][i] = val;
	return val;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	int t_num;

	cin >> t_num;

	cout.precision (7);
	cout << fixed;
	
	while (t_num--) {
		cin >> n >> c >> m;
		for (int i = 0; i < n; ++i) {
			cin >> b[i] >> p[i];
			p[i] = p[i] / 100;
		}
		memset (d, -1, sizeof (d));

		for (int mask = 0; mask < (1 << n); ++mask) {
			cdf[mask] = 0;
			for (int i = 0; i < n; ++i)
				if (bit (mask, i))
					cdf[mask] += b[i];
/*
			for (int i = 0; i <= c; ++i)
				d[mask][i] = -1;
*/
		}
		
		cout << calc (0, 0) << "\n";
	}

	return 0;
}
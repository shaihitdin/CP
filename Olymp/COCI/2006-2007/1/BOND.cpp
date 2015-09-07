#include <bits/stdc++.h>

using namespace std;

const int N = 22, NN = 1 << 20;

double d[2][NN], prob[N][N];

inline bool bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cout.precision (6);
	cout << fixed;

	int n;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int x;
			cin >> x;
			prob[i][j] = x / 100.0;
		}
	}

	d[1][0] = 1;

	
	for (int i = 0; i < n; ++i) {
		int st = i & 1;
		for (int mask = 0; mask < (1 << n); ++mask)
			d[st][mask] = 0;
		for (int mask = 0; mask < (1 << n); ++mask)
			for (int j = 0; j < n; ++j)
				if (!bit (mask, j))
					d[st][mask | (1 << j)] = max (d[st][mask | (1 << j)], d[st ^ 1][mask] * prob[i][j]);
	}
	
	
	cout << d[(n - 1) & 1][(1 << n) - 1] * 100;
	
	
	return 0;
}
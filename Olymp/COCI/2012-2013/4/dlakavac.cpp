#include <bits/stdc++.h>

using namespace std;

const int N = 1501;

bitset <N> b[N][61], state, newstate, zero;

long long k;

int m, n, a[N];

int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	freopen ("err", "w", stderr);
	cin >> k >> m >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			b[i][0][(i * a[j]) % m] = 1;
	for (int i = 0; i < n; ++i)
		b[m][0][a[i]] = 1;
	for (int j = 1; j < 61; ++j)
		for (int i = 0; i <= m; ++i)
			for (int k = 0; k < m; ++k)
				if (b[i][j - 1][k])
					b[i][j] |= b[k][j - 1];	
	state[m] = 1;
	for (int i = 60; i >= 0; --i) {
		if ((k >> i) & 1) {
			newstate = zero;
			for (int j = 0; j <= m; ++j) {
				if (state[j]) {
					newstate |= b[j][i];
				}
			}
			state = newstate;
		}
	}
	for (int i = 0; i < m; ++i)
		if (state[i])
			cout << i << " ";
	return 0;
}
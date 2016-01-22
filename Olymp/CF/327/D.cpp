#include <bits/stdc++.h>

using namespace std;

const int N = 152, oo = 1e9;

int d[2][6200][N];
int n, k, s;
int a[N];

inline void cc (const int &v) {
	for (int j = 0; j <= s; ++j)
		for (int it = 0; it <= n + 1; ++it)
			d[v][j][it] = oo;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n >> k >> s;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	if (s > 6000) {
		sort (a + 1, a + n + 1);
		int sum = 0;
		for (int i = 1; i <= k; ++i)
			sum += a[i];
		cout << sum;
		return 0;
	}
	
	cc (1);

	d[1][s][1] = 0;
				
	for (int i = 1; i <= n; ++i) {
		int v = i & 1;
		cc (v ^ 1);
		for (int j = 0; j <= s; ++j) {
			for (int it = 1; it <= min (k, i) + 1; ++it) {
				if (d[v][j][it] == oo)
					continue;
				if (j >= i - it)
					d[v ^ 1][j - (i - it)][it + 1] = min (d[v ^ 1][j - (i - it)][it + 1], d[v][j][it] + a[i]);
				d[v ^ 1][j][it] = min (d[v ^ 1][j][it], d[v][j][it]);
			}
		}
	}
	
	
	int ans = oo;
	
	for (int i = 0; i <= s; ++i)
		ans = min (ans, d[(n + 1) & 1][i][k + 1]);
	
	cout << ans;
	
	return 0;
}
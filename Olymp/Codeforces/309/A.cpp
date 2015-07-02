#include <bits/stdc++.h>

using namespace std;

const int N = 1200, bpr = 1e9 + 7;

int a[N];
int f[N];
int d[N][N];


inline int bin_pow (const int &x, const int &y) {
	if (!y)
		return 1;
	if (y & 1)
		return (x * 1ll * bin_pow (x, y - 1)) % bpr;
	int b = bin_pow (x, y >> 1);
	return (b * 1ll * b) % bpr;
}

inline int cnk (const int &n, const int &k) {
	int res = f[n];
	res = (res * 1ll * bin_pow (f[k], bpr - 2)) % bpr;
	res = (res * 1ll * bin_pow (f[n - k], bpr - 2)) % bpr;
	return res;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int n = 0, k;
	
	cin >> k;
	
	f[0] = 1;
		
	for (int i = 1; i < N; ++i)
		f[i] = (f[i - 1] * i) % bpr;
	
	for (int i = 1; i <= k; ++i) {
		cin >> a[i];
		n += a[i];
	}

	d[n][k] = 1;

	for (int i = 1;

	
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			cerr << d[i][j] << " ";
		}
		cerr << "\n";
	}	
	return 0;
}
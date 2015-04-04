#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector <vector <ll> > matrix;

#define y1 good

int mod, n, m, x, x1, y1, x2, y2;

inline matrix c_m (matrix &a, const int &n, const int &m) {
	a.resize (n + 1);
	for (int i = 1; i <= n; ++i)
		a[i].resize (m + 1);
	return a;
}

inline matrix operator * (const matrix &a, const matrix &b) {
    matrix c;
    /*
	int m, n, q;
	n = a.size() - 1, m = b.size() - 1, q = b[1].size() - 1;
	*/
	/*
	c_m (c, n, q);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= q; ++j)
			for (int k = 1; k <= m; ++k)
				c[i][j] = (c[i][j] + (a[i][k] * b[k][j])) % mod;
	*/
	c_m (c, 2, 2);
	for (int i = 1; i <= 2; ++i)
		for (int j = 1; j <= 2; ++j)
			for (int k = 1; k <= 2; ++k)
				c[i][j] = (c[i][j] + (a[i][k] * b[k][j])) % mod;
	return c;
}

matrix zero_matrix;

/*
inline matrix zero_matrix (const int &n) {
	matrix a;
	c_m (a, n, n);
	for (int i = 1; i <= n; ++i)
		a[i][i] = 1;
	return a;
}
*/

inline matrix bin_pow (const matrix &a, const int &power) {
	if (power == 0)
		return zero_matrix;
	if (power & 1)
		return bin_pow (a, power - 1) * a;
	matrix b = bin_pow (a, power >> 1);
	return b * b;
}

inline ll bin_pow (const ll &a, const ll &power) {
	if (power == 0)
		return 1;
	if (power & 1LL)
		return (bin_pow (a, power - 1) * a) % mod;
	ll b = bin_pow (a, power >> 1LL);
	return (b * b) % mod;
}


inline ll gp (const ll &fe, const ll &x, const ll &n) {
	matrix a;
	c_m (a, 2, 2);
	a[1][1] = x;
	a[1][2] = 0;
	a[2][1] = 1;
	a[2][2] = 1;
	a = bin_pow (a, n);
	return (a[2][1] * fe) % mod;
}

int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	//ios_base :: sync_with_stdio (0);
	c_m (zero_matrix, 2, 2);
	zero_matrix[1][1] = zero_matrix[2][2] = 1;
	int q;
	scanf ("%d%d%d%d", &n, &m, &x, &q);
	for (int i = 1; i <= q; ++i) {
		scanf ("%d%d%d%d%d", &x1, &x2, &y1, &y2, &mod);
		ll res = gp (bin_pow (x, (x1 - 1) * 1ll * m + y1), x, y2 - y1 + 1);
		printf ("%I64d\n", gp (res, bin_pow (x, m), x2 - x1 + 1));
	}
	return 0;
}
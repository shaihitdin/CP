#include <bits/stdc++.h>

using namespace std;

const int N = 110, bpr = 1e9 + 7;

typedef long long ll;
typedef vector <vector <int> > matrix;

matrix zero_matrix;

inline void add (int &x, int y) {
	x += y;
	if (x >= bpr)
		x -= bpr;
}

inline matrix operator * (const matrix &a, const matrix &b) {
	matrix c;
	c.resize (a.size ());
	for (int i = 0; i < c.size (); ++i)
		c[i].resize (b[i].size ());
	for (int i = 0; i < a.size (); ++i)
		for (int k = 0; k < a[0].size (); ++k)
			for (int j = 0; j < b[0].size (); ++j)
				add (c[i][j], b[k][j] * 1ll * a[i][k] % bpr);
	return c;
}

inline matrix bin_pow (const matrix &a, ll b) {
	if (!b)
		return zero_matrix;
	if (b & 1)
		return bin_pow (a, b - 1) * a;
	auto c = bin_pow (a, b / 2);
	return c * c;
}

ll k;
int n;
ll a[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	matrix res;

	res.resize (n);
	
	for (int i = 0; i < n; ++i)
		res[i].resize (n);
	
	zero_matrix = res;

	for (int i = 0; i < n; ++i)
		zero_matrix[i][i] = 1;
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (__builtin_popcountll (a[i] ^ a[j]) % 3 == 0)
				++res[i][j];
	
	res = bin_pow (res, k - 1);
				
	int ans = 0;
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			add (ans, res[i][j]);
	
	cout << ans;
	
	return 0;
}
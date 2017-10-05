#include <bits/stdc++.h>

using namespace std;

const int bpr = 1e9 + 7, N = 1e6 + 100;

typedef long long ll;

typedef vector <vector <int> > matrix;

matrix O;

inline matrix operator * (const matrix &a, const matrix &b) {
	auto c = a;
	int n = c.size ();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			c[i][j] = 0;
		}
	}
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i)  {
			for (int j = 0; j < n; ++j) {
				c[i][j] = (c[i][j] + (a[i][k] * 1ll * b[k][j])) % bpr;			
			}
		}
	}
	return c;
}


inline matrix bin_pow (const matrix &a, const int &b) {
	if (!b)
		return O;
	if (b & 1)
		return bin_pow (a, b - 1) * a;
	auto c = bin_pow (a, b / 2);
	return c * c;
}

inline void clear (matrix &a) {
	for (int i = 0; i < a.size (); ++i)
		for (int j = 0; j < a.size (); ++j)
			a[i][j] = 0;
}

int cnt[120];
int a[N];
int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	int n, l, m;
	cin >> n >> l >> m;

	O.resize (m);
	matrix ans, tmp, tmp2;
	for (int i = 0; i < m; ++i) {
		O[i].resize (m);
	}

	ans = tmp = tmp2 = O;
	
	for (int i = 0; i < m; ++i)
		O[i][i] = 1;
	
	ans[0][0] = 1;

	
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		++cnt[x % m];
	}
	
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			tmp[i][(i + j) % m] = cnt[j];
		}
	}	
	ans = ans * tmp;

	
	memset (cnt, 0, sizeof (cnt));
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		++cnt[x % m];
		a[i] = x % m;
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			tmp[i][(i + j) % m] = cnt[j];
		}
	}	

	tmp = bin_pow (tmp, l - 2);
	ans = ans * tmp;	
	

	memset (cnt, 0, sizeof (cnt));
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		a[i] += x;
		a[i] %= m;
		++cnt[a[i]];
	}


	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			tmp[i][(i + j) % m] = cnt[j];
		}
	}	
	
	
	ans = ans * tmp;
	
	
	cout << ans[0][0];
	
	return 0;
}
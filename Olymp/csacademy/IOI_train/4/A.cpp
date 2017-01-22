/// Stupido del problemo

#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);
  
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

const int oo = 1e9, bpr = 1e9 + 7, N = 5050;

int n, k;
int c[N][N], d[N][N];

inline void add (int &x, int y) {
	x += y;
	if (x >= bpr)
		x -= bpr;
}

inline int bin_pow (int a, int b) {
	if (!b)
		return 1;
	if (b & 1)
		return bin_pow (a, b - 1) * 1ll * a % bpr;
	int c = bin_pow (a, b >> 1);
	return c * 1ll * c % bpr;
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n >> k;


	for (int i = f[0] = 1; i < N; ++i)
		f[i] = f[i - 1] * 1ll * i % bpr;
	for (int i = 0; i < N; ++i)	
		frev[i] = bin_pow (i, bpr - 2);

	int ans = f[n];
	
	for (int i = k + 1; i <= n; ++i) {
		for (int j = 1; j <=
	}
/*

	for (int i = 0; i < N; ++i) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j)
			add (c[i][j] = c[i - 1][j], c[i - 1][j - 1]);
	}

	d[1][1] = 1;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			add (d[i + 1][1], d[i][j] * 1ll * i % bpr);
			add (d[i + 1][j + 1], d[i][j]);
		}
	}
	
	int ans = 0;

	for (int i = 1; i <= k; ++i)
		add (ans, d[n][i]);
	
	cout << ans;
*/
	return 0;
}
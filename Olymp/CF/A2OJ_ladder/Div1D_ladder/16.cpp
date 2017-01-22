/// Forever

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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 2100;

#define mp make_pair

inline void add (int &x, int y) {
	x += y;
	if (x >= bpr)
		x -= bpr;
/**
	x += bpr;
	if (x >= bpr)
		x -= bpr;
**/
}

int f[N];
int ans[N][53], ansd[N][53];
int dp1[1004][53][1004];
int c[N][N];

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	

	for (int i = 0; i < N; ++i) {
		c[i][i] = c[i][0] = 1;
		for (int j = 1; j < i; ++j)
			add (c[i][j] = c[i - 1][j - 1], c[i - 1][j]);
	}

	for (int i = f[0] = 1; i < N; ++i)
		f[i] = f[i - 1] * 1ll * i % bpr;
	
	dp1[0][0][0] = 1; ///dp1[i][j][k] -------------------->          i -> mx el, j -> el cnt, k -> el sum
	
	for (int i = 0; i <= 1000; ++i) {
		for (int j = 0; j <= 50; ++j) {
			for (int k = 0; k <= 1000; ++k) {
				if (k + i <= 1000)
					add (dp1[i + 1][j + 1][k + i], dp1[i][j][k]);
				add (dp1[i + 1][j][k], dp1[i][j][k]);
			}
		}
	}
	
	for (int j = 1; j <= 50; ++j)
		for (int k = 0; k <= 1000; ++k)
			add (ans[k + j][j], dp1[1000][j][k] * 1ll * f[j] % bpr);

	for (int j = 1; j <= 50; ++j)
		for (int k = 0; k <= 1000; ++k)
			for (int k2 = 0; k2 <= k; ++k2)
				add (ansd[k][j], ans[k2][j] * 1ll * c[k - k2 + j][j] % bpr);
/*
	for (int j = 1; j <= 50; ++j)
		for (int k = 1; k <= 1000; ++k)
			add (ans[k][j], ans[k - 1][j] * 1ll * j % bpr);
	for (int j = 1; j <= 50; ++j)
		for (int k = 1; k <= 1000; ++k)
			add (ansd[k][j] = ansd[k - 1][j], ans[k][j]);
*/
	int t;

	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;
		if (k >= 50) {
			cout << 0 << "\n";
		} else {
			cout << ansd[n][k] << "\n";
		}
	}	
	
	return 0;
}
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

const int oo = 1e9, bpr = 1e9 + 9, N = 5e4 + 100, K = 1e5 + 100;

int f[K], frev[K];
int n, k, ft;
int cc[10];
int tt[21][21];
vector <int> g[N];

inline void add (int &x, int y) {
	x += y;
	if (x >= bpr)
		x -= bpr;
}

inline int bin_pow (int x, int y) {
	if (!y)
		return 1;
	if (y & 1)
		return bin_pow (x, y - 1) * 1ll * x % bpr;
	int c = bin_pow (x, y / 2);
	return c * 1ll * c % bpr;
}

inline int cnk (int n, int k) {
	if (k > n)
		return 0;
	int res = f[n];
	res = res * 1ll * frev[k] % bpr;
	res = res * 1ll * frev[n - k] % bpr;
	return res;
}

int dp[N][6][21]; //vertex, parent were k-th type, parent no. used colors

inline int calc (int v, int pt, int c) {
	if (dp[v][pt][c] != -1)
		return dp[v][pt][c];
	int kh = k - c;
	dp[v][pt][c] = 0;
	for (int i = 1; i <= ft; ++i) {
		if (i == pt)
			continue;
		for (int j = 1; j <= cc[i] && j <= kh; ++j) {
			int rval = cnk (kh, j);
			rval = rval * 1ll * tt[cc[i]][j] % bpr;
			for (auto to : g[v]) {
				if (!rval)
					break;
				rval = rval * 1ll * calc (to, i, j) % bpr;
			}
			add (dp[v][pt][c], rval);
		}
	}
	return dp[v][pt][c];
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n >> k >> ft;

	for (int i = 1; i <= ft; ++i)
		cin >> cc[i];
	
	for (int i = f[0] = 1; i < K; ++i)
		f[i] = f[i - 1] * 1ll * i % bpr;
	frev[K - 1] = bin_pow (f[K - 1], bpr - 2);
	for (int i = K - 2; i >= 0; --i)
		frev[i] = frev[i + 1] * 1ll * (i + 1) % bpr;
	
	tt[4][0] = 0, tt[4][1] = 1, tt[4][2] = 5, tt[4][3] = 15, tt[4][4] = 36;
	tt[6][0] = 0, tt[6][1] = 1, tt[6][2] = 10, tt[6][3] = 57, tt[6][4] = 240, tt[6][5] = 800, tt[6][6] = 2226;
	tt[8][0] = 0, tt[8][1] = 1, tt[8][2] = 23, tt[8][3] = 333, tt[8][4] = 2916, tt[8][5] = 16725, tt[8][6] = 70911, tt[8][7] = 241913, tt[8][8] = 701968;
	tt[12][0] = 0, tt[12][1] = 1, tt[12][2] = 96, tt[12][3] = 9099, tt[12][4] = 280832, tt[12][5] = 4073375, tt[12][6] = 36292320, tt[12][7] = 230719293, tt[12][8] = 145393143, tt[12][9] = 707296577, tt[12][10] = 666923856, tt[12][11] = 307592771, tt[12][12] = 602434508;
	tt[20][0] = 0, tt[20][1] = 1, tt[20][2] = 17822, tt[20][3] = 58076586, tt[20][4] = 93064446, tt[20][5] = 413485268, tt[20][6] = 950452260, tt[20][7] = 538866086, tt[20][8] = 665139934, tt[20][9] = 785581076, tt[20][10] = 442181785, tt[20][11] = 107114120, tt[20][12] = 816730280, tt[20][13] = 865226159, tt[20][14] = 423463876, tt[20][15] = 240865690, tt[20][16] = 492572685, tt[20][17] = 719193092, tt[20][18] = 567858965, tt[20][19] = 161082671, tt[20][20] = 438008706;


	for (int jj = 1; jj < 20; ++jj)
		for (int i = 1; i <= jj; ++i)
			for (int j = 1; j < i; ++j)
				add (tt[jj][i], bpr - (tt[jj][j] * 1ll * cnk (i, j)) % bpr);

	for (int i = 2; i <= n; ++i) {
		int x;
		cin >> x;
		g[x].eb (i);
	}
	
	memset (dp, -1, sizeof (dp));
	
	cout << calc (1, 0, 0);
	
	return 0;
}
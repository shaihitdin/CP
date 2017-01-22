/// izizi

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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 101;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

int dp[N][N][2];
int a[N];

inline int calc (int l, int r, int player) { // 0 -> minimize, 1 -> maximize
	if (dp[l][r][player] != -1)
		return dp[l][r][player];
	if (l == r)
		return a[l];
	int res = (player == 0) ? (oo) : (0);
	for (int i = l; i < r; ++i) {
		if (player == 0)
			res = min (res, min (calc (l, i, player ^ 1), calc (i + 1, r, player ^ 1)));
		else
			res = max (res, max (calc (l, i, player ^ 1), calc (i + 1, r, player ^ 1)));
	}
	return dp[l][r][player] = res;
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	srand (time (0));

	for (int test = 1; test <= 100; ++test) {
		int n = 11;
		for (int i = 1; i <= n; ++i)
			cout << (a[i] = rand () % 10 + 1) << " ";
		cout << "\n";
		memset (dp, -1, sizeof (dp));
		cout << calc (1, n, 1) << "\n";
		assert (calc (1, n, 1) == max (a[1], a[n]));
	}
	
	return 0;
}
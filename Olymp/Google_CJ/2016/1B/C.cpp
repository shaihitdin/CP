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
  
const int bpr = 1e9 + 7, N = 1100, oo = 1e9;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

struct thing {
	string a, b;
	int id;
};

inline bool operator < (const thing &a, const thing &b) {
	if (a.a == b.a)
		return a.b < b.b;
	return a.a < b.a;
}

int nw1[N][N], nw2[N][N];
int cnt[N];
thing c1[N], c2[N];
string c3[N], c4[N];
int dp[N][N];
int n;

inline int calc (int p1, int p2) {
	if (p1 == n || p2 == n)
		return 0;
	if (dp[p1][p2] != -1)
		return dp[p1][p2];
	int res = -oo;
	if (!nw1[p1][p2])
		res = max (res, calc (p1 + 1, p2));
	else
		res = max (res, calc (p1 + 1, p2) + (c1[p1 + 1].a == c1[p1].a && binary_search (c4 + 1, c4 + p2 + 1, c1[p1 + 1].b)));
	if (!nw2[p1][p2])
		res = max (res, calc (p1, p2 + 1));
	else
		res = max (res, calc (p1, p2 + 1) + (c2[p2 + 1].a == c2[p2].a && binary_search (c3 + 1, c3 + p1 + 1, c2[p2 + 1].b)));	
	return dp[p1][p2] = res;
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int test;

	cin >> test;

	for (int test_num = 1; test_num <= test; ++test_num) {
		cout << "Case #" << test_num << ": ";
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			string a, b;
			cin >> a >> b;
			c1[i] = {a, b, i};
			c2[i] = {b, a, i};
			c3[i] = a;
			c4[i] = b;
		}
		c1[n + 1] = c2[n + 1] = {"", "", 0};
		sort (c1 + 1, c1 + n + 1);
		sort (c2 + 1, c2 + n + 1);
		sort (c3 + 1, c3 + n + 1);
		sort (c4 + 1, c4 + n + 1);
		memset (cnt, 0, sizeof (cnt));
		for (int i = 0; i <= n; ++i) {
			++cnt[c1[i].id];
			for (int j = 0; j <= n; ++j) {
				++cnt[c2[j].id];
				nw1[i][j] = !cnt[c1[i + 1].id];
				nw2[i][j] = !cnt[c2[j + 1].id];
			}
			for (int j = 0; j <= n; ++j)
				--cnt[c2[j].id];
		}
		memset (dp, -1, sizeof (dp));
		cout << calc (0, 0) << "\n";
	}
	
	return 0;
}
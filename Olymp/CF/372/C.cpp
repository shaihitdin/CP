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
#include <iomanip>

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
#define int ll

const int oo = 1e9, bpr = 1e9 + 7, N = 1e5 + 100;

inline void dfs_sz (int v, int p = -1) {
	sz[v] = 1;
	for (auto to : g[v]) {
		int to = e.fe;
		if (banned[to] || to == p)
			continue;
		dfs_sz (to, v);
		sz[v] += sz[to];
	}
}

inline int dfs_root (int v, int p = -1) {
	for (auto e : g[v]) {
		int to = e.fe;
		if (banned[to] || to == p)
			continue;
		if (sz[to] * 2 >= sz[v])
			return dfs_root (to, v);
	}
	return v;
}

inline void dfs_calc (int v, int p, int lvl) {
	for (auto e : g[v]) {
		int to = e.fe;
		int cost = e.se;
		if (banned[to] || to == p)
			continue;
		calcup[to] = (calcup[v] + pw[lvl + 1] * cost) % M;
		calcdown[to] = (calcdown[v] * 10 + cost) % M;
		dfs_calc (to, v, lvl + 1);
	}
}

inline void dfs (int v) {
	dfs_sz (v, 0);
	v = dfs_root (v, 0);
	dfs_calc (v, 0, -1);

}


main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n >> M;

	for (int i = 1; i < n; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		g[x].eb (mp (y, z));
		g[y].eb (mp (x, z));
	}

	Find (1);


	return 0;
}
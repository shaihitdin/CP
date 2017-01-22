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

const int oo = 1e9, bpr = 1e9 + 7, N = 3e5 + 100;

int sz[N];
vector <int> g[N];
int ans[N];
int p[N];

inline bool can_be_centroid (int root, int v) {
	int total_sz = sz[root] - 1;
	for (auto to : g[v]) {
		if (sz[to] * 2 > sz[root])
			return 0;
		total_sz -= sz[to];
	}
	return (total_sz) * 2 <= sz[root];
}

inline void dfs (int v) {
	sz[v] = 1;
	for (auto to : g[v]) {
		dfs (to);
		sz[v] += sz[to];
	}
}

inline int dfs2 (int root, int v) {
	if (can_be_centroid (root, v))
		return v;
	for (auto to : g[v]) {
		int val = dfs2 (root, to);
		if (val)
			return val;
	}
	return 0;
}

inline void dfs1 (int v) {
	if (g[v].size () == 0) {
		ans[v] = v;
		return;
	}
	int mxs = g[v][0];
	for (auto to : g[v]) {
		dfs1 (to);
		if (sz[mxs] < sz[to])
			mxs = to;
	}
	int cc = ans[mxs];
	while ((sz[v] - sz[cc]) * 2 > sz[v])
		cc = p[cc];
	ans[v] = cc;
}


int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int n, q;

	cin >> n >> q;

	for (int i = 2; i <= n; ++i) {
		int x;
		cin >> x;
		g[x].eb (i);
		p[i] = x;
	}
	
	dfs (1);
	dfs1 (1);
	
	
	while (q--) {
		int v;
		cin >> v;
		cout << ans[v] << "\n";
	}
	
	return 0;
}
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

const int oo = 1e9, bpr = 1e9 + 7, N = -1;

bool root[N];
vector <int> g[N], av;
int ans[N];
int u[N];

inline bool is_parent (int x, int y) {
	return tin[x] <= tin[y] && tout[y] <= tout[x];
}

inline void M (int &x, int y) {
	if (x == -1 || y == -1)
		return x == -1 ? y : x;
	if (x != y) {
		cout << -1;
		exit (0);
	}
}

inline void dfs2 (int v) {
	tin[v] = ++timer;
	for (auto to : g[v])
		dfs2 (to);
	tout[v] = ++timer;
}

inline void dfs (int v) {
	for (auto to : g[v])
		dfs (to);
	int k = -1;
	for (auto to : g[v])
		M (k, ans[to]);
	M (k, a[v]);
	if (k == a[v])
		ans[v] = -1;
	if (is
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n >> m;

	memset (root, 1, sizeof (root))
	
	for (int i = 1; i <= m; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].eb (b);
		root[b] = 0;
	}
	
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	memset (ans, -1, sizeof (ans));
	
	for (int i = 1; i <= n; ++i) {
		if (root[i])
			dfs (i);
		
	}
	
	return 0;
}
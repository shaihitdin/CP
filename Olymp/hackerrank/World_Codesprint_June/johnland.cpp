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

const int oo = 1e9, bpr = 1e9 + 7, N = 4e5 + 100;


struct edge {
	int cost, from, to;
};

inline bool operator < (const edge &a, const edge &b) {
	return a.cost < b.cost;
}

int p[N];
vector <pair <int, int> > g[N];
vector <edge> e;
int sz[N];
ll ans[N];
int n, m;

inline int get_p (int x) {
	return p[x] = ((x == p[x]) ? x : get_p (p[x]));
}

inline void Merge (int x, int y) {
	x = get_p (x), y = get_p (y);
	p[x] = y;
}

inline void dfs (int v, int p = -1) {
	sz[v] = 1;
	for (auto to : g[v]) {
		if (to.fe == p)
			continue;
		dfs (to.fe, v);
		sz[v] += sz[to.fe];
		ans[to.se] += sz[to.fe] * 1ll * (n - sz[to.fe]);
	}
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> m;

	for (int i=  1; i <= m; ++i) {
		int x, y, c;
		cin >> x >> y >> c;
		e.pb ({c, x, y});
	}

	for (int i = 1; i <= n; ++i)
		p[i] = i;
	
	sort (e.begin (), e.end ());
	
	for (auto it : e) {
		if (get_p (it.from) != get_p (it.to)) {
			g[it.from].eb (mp (it.to, it.cost));
			g[it.to].eb (mp (it.from, it.cost));
			Merge (it.to, it.from);
		}
	}
	
	dfs (1);
	

	int lst = 0;

	for (int i = 0; i + 1 < N; ++i) {
		ans[i + 1] += ans[i] / 2;
		ans[i] %= 2;
		if (ans[i])
			lst = i;
	}
	
	for (int i = lst; i >= 0; --i)
		cout << ans[i];
	
	return 0;
}
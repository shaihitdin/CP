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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 5e4 + 100;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

int tin[N], tout[N], timer;
int s[N], ek[N];
int p[N], a[N];
vector <int> g[N];
int lvl[N];


inline void dfs (int v, int pp) {
	lvl[v] = lvl[pp] + 1;
	p[v] = pp;
	tin[v] = ++timer;
	for (auto to : g[v]) {
		if (to == pp)
			continue;
		dfs (to, v);
	}
	tout[v] = ++timer;
}

inline bool is_parent (const int &v, const int &u) { // is vertex u is parent of v
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

inline void dfs2 (int v, int f, int pp) {
	ek[f] ^= a[v];
	ek[lvl[v]] ^= a[v];
	for (auto to : g[v]) {
		if (to == pp)
			continue; 
		dfs2 (to, v + 1, v);
	}
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int n;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	for (int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].eb (y);
		g[y].eb (x);
	}
	
	dfs (1, 1);
	
	for (int i = 2; i <= n; ++i)
		s[lvl[i]] ^= a[i], ek[lvl[i]] ^= a[i];

	int q;

	cin >> q;

	while (q--) {
		int x, y;
		cin >> x >> y;
		if (is_parent (y, x)) {
			cout << "INVALID\n";
			continue;
		}		
		dfs2 (x, lvl[y] + 1, p[x]);
		bool flag = 0;
		for (int i = 1; i <= n; ++i)
			flag |= (ek[lvl[i]] > 0);
		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
		dfs2 (x, lvl[y] + 1, p[x]);
	}
	
	return 0;
}
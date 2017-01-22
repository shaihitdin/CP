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
int sumval[N];
int sumxor[N];

inline void dfs2 (int v, int pp, int v2, int v3) {
	sumval[v] = a[v];
	sumxor[v] = 0;
	for (auto to : g[v]) {
		if (to == pp || to == v2 || to == p[v])
			continue;
		dfs2 (to, v, v2, v3);
		sumval[v] += sumval[to];
		sumxor[v] ^= sumxor[to];
	}
	if (v3 == v) {
		dfs2 (v2, v, v2, v3);
		sumval[v] += sumval[v2];
		sumxor[v] ^= sumxor[v2];
	}
	sumxor[v] ^= sumval[v];
}

inline void dfs (int v, int pp) {
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
	
	int q;

	cin >> q;

	while (q--) {
		int x, y;
		cin >> x >> y;
		if (is_parent (y, x)) {
			cout << "INVALID\n";
			continue;
		}
		dfs2 (1, 1, x, y);
		cerr << sumxor[1] << " ";
		if (sumxor[1]) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
	return 0;
}
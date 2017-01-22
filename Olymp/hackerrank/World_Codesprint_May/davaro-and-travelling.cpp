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

const int oo = 1e9, bpr = 1e9 + 7, N = 1e5 + 100;

vector <pair <int, pair <int, int> > > cc;
set <int> Set[N];
set <pair <int, int> > megaq[N];
int p[N];
vector <int> c[N], g[N];
int n, m, q, x[N], y[N], k[N];
int ans[N];


int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n >> m >> q;

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		Set[i].insert (x);
		p[i] = i;
		c[i].eb (i);
	}
	
	for (int i = 1; i <= m; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		cc.eb (mp (z, mp (x, y)));
	}
	
	sort (cc.begin (), cc.end ());

	for (int i = 1; i <= q; ++i) {
		cin >> x[i] >> y[i] >> k[i];
		ans[i] = oo;
		g[x[i]].eb (i);
		g[y[i]].eb (i);
		if (x[i] == y[i] && k[i] == 1)
			ans[i] = 0;
	}
	
	sort (cc.begin (), cc.end ());
	
	for (auto it : cc) {
		int v = p[it.se.fe], u = p[it.se.se];
		if (v == u)
			continue;
		if (c[v].size () < c[u].size ())
			swap (u, v);
		for (auto s : Set[u])
			Set[v].insert (s);
		for (auto s : c[u]) {
			c[v].eb (s);
			p[s] = v;
		}
		for (auto s : c[u])
			for (auto keke : g[s])
				if (p[x[keke]] == p[y[keke]])
					megaq[v].insert (mp (k[keke], keke));		
		while (megaq[v].size () && megaq[v].begin () -> fe <= Set[v].size ()) {
			ans[megaq[v].begin () -> se] = min (ans[megaq[v].begin () -> se], it.fe);
			megaq[v].erase (megaq[v].begin ());
		}
	}
	
	for (int i = 1; i <= q; ++i) {
		if (ans[i] == oo)
			cout << -1 << "\n";
		else
			cout << ans[i] << "\n";
	}	
	return 0;
}
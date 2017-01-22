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

const int oo = 1e18, bpr = 1e9 + 7, N = 1010;

int n, m, L, s, t;
set <pair <int, int> > Set;
vector <pair <int, int> > cc, g[N];
int d1[N], dn[N];
vector <int> upd1[N], updn[N];

inline void run_dijkstra (int v, int d[]) {
	for (int i = 0; i < n; ++i)
		d[i] = oo;
	d[v] = 0;
	Set.insert (mp (d[v], v));
	while (Set.size ()) {
		int v = (*Set.begin ()).se;
		Set.erase (Set.begin ());
		for (auto e : g[v]) {
			int to = e.fe;
			int cost = e.se;
			if (d[to] > d[v] + cost) {
				Set.erase (mp (d[to], to));
				d[to] = d[v] + cost;
				p[to] = v;
				Set.insert (mp (d[to], to));
			}
		}
	}
}

vector <pair <int, pair <int, int> > > ccc;

main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n >> m >> L >> s >> t;

	for (int i = 1; i <= m; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		if (z == 0) {
			cc.eb (mp (x, y));
			continue;
		}
		g[x].eb (mp (y, z));
		g[y].eb (mp (x, z));
		ccc.eb (mp (z, mp (x, y)));
	}

	run_dijkstra (s, d1, p1);
	run_dijkstra (t, dn, pn);
	
	for (int i = 1; i <= n; ++i) {
		upd1[p1[i]].eb (i);
		upd2[pn[i]].eb (i);
	}
	
	
	
	if (d1[t] < L) {
		cout << "NO\n";
		return 0;
	}	

	bool flag = 0;
	vector <int> ans;
	for (auto it : cc) {
		int x = it.fe;
		int y = it.se;
		if (d1[x] > d1[y])
			swap (x, y);
		if (flag) {
			ans.eb (oo);
			continue;
		}
		if (dn[y] < dn[x] && d1[y] > d1[x] && d1[x] + dn[y] + 1 <= L) {
			int should = min (L - d1[x] - dn[y], d1[y] - d1[x]);
			ans.eb (should);
			flag = 1;
		} else {
			ans.eb (oo);
			continue;
		}
	}	
	
	if (!flag && d1[t] != L) {
		cout << "NO\n";
		return 0;
	}
	
	cout << "YES\n";

	for (int i = 0; i < cc.size (); ++i) {
		cout << cc[i].fe << " " << cc[i].se << " " << ans[i] << "\n";
	}
	
	for (int i = 0; i < ccc.size (); ++i) {
		cout << ccc[i].se.fe << " " << ccc[i].se.se << " " << ccc[i].fe << "\n";
	}
	return 0;
}
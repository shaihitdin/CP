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

const int oo = 1e16, bpr = 1e9 + 7, N = 6e5 + 100, sz = (1 << 17);

vector <pair <int, int> > g[N];
vector <int> li;

inline void upd (int v, int Tl, int Tr, int l, int r, int x, bool flag, int z) {
	if (Tl > r || Tr < l)
		return;
	if (l <= Tl && Tr <= r) {
		li.eb (v);
		return;
	}
	int mid = (Tl + Tr) / 2;
	upd (v + v, Tl, mid, l, r, x, flag, z);
	upd (v + v + 1, mid + 1, Tr, l, r, x, flag, z);
}

int d[N];

main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n, m, s;

	cin >> n >> m >> s;

	for (int i = 1; i < sz; ++i) {
		g[i].eb (mp (i + i, 0));
		g[i].eb (mp (i + i + 1, 0));
		g[2 * sz + i + i].eb (mp (2 * sz + i, 0));
		g[2 * sz + i + i + 1].eb (mp (2 * sz + i, 0));
	}

	for (int i = sz + 1; i <= sz; ++i) {
		g[i].eb (mp (2 * sz + i, 0));
		g[2 * sz + i].eb (i, 0);
	}
	
	for (int i = 1; i <= m; ++i) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, y, z;
			cin >> x >> y >> z;
			x += sz;
			y += sz;
			g[x].eb (mp (y, z));
			g[y].eb (mp (x, z));
		} else {
			int v, l, r, z;
			cin >> v >> l >> r >> z;
			v += sz;
			l += sz;
			r += sz;
			li.clear ();
			if (t == 2) {
				upd (1ll, sz + 1ll, sz + sz - 1, l, r, v, 0ll, z);
			} else {
				upd (1ll, sz + 1ll, sz + sz - 1, l, r, v, 1ll, z);
			}
			for (auto it : li) {
				if (t == 2) {
					g[v].eb (mp (it, z));
				} else {
					g[it + 2 * sz].eb (mp (v, z));
				}
			}
		}
	}

  	for (int i = 0; i <= 4 * sz; ++i)
  		d[i] = oo;

  	s += sz;

  	d[s] = 0;

  	set <pair <int, int > > Set;

  	Set.insert (mp (d[s], s));

  	while (Set.size ()) {
  		int v = Set.begin () -> se;
		Set.erase (Set.begin ());
		for (auto to : g[v]) {
			if (d[to.fe] > d[v] + to.se) {
				Set.erase (mp (d[to.fe], to.fe));
				d[to.fe] = d[v] + to.se;
				Set.insert (mp (d[to.fe], to.fe));
			}
		}
  	}

  	for (int i = 1 + sz; i <= sz + n; ++i) {
  		if (d[i] == oo) {
  			cout << "-1 ";
  		}
  		else {
  			cout << d[i] << " ";
  		}
  	}

  	return 0;
}

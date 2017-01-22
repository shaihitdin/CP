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

const int oo = 1e18, bpr = 1e9 + 7, N = 2e5 + 100, sz = (1 << 19);

vector <pair <int, int> > g[N];

int a[N];
int ans[N];
int d[N];
int tin[N], tout[N], timer;
int b[N], c[N];
vector <int> cc, qu[N];

inline void dfs (int v) {
	tin[v] = ++timer;
	for (auto to : g[v]) {
		d[to.fe] = d[v] + to.se;
		dfs (to.fe);
	}
	tout[v] = timer;
}

struct node {
	int x;
	node *l, *r;
	node () {
		x = 0;
		l = r = 0;
	}
	node (int xx) {
		x = xx;
		l = r = 0;
	}
	node (node *Tl, node *Tr) {
		x = Tl -> x + Tr -> x;
		l = Tl;
		r = Tr;
	}
};

node *root[N];

inline node* Build (int Tl, int Tr) {
	if (Tl == Tr)
		return new node (0);
	int mid = (Tl + Tr) / 2;
	return new node (Build (Tl, mid), Build (mid + 1, Tr));
}


inline int get (node *t, int Tl, int Tr, int l, int r) {
	if (Tl > r || Tr < l)
		return 0;
	if (l <= Tl && Tr <= r)
		return t -> x;
	int mid = (Tl + Tr) / 2;
	return get (t -> l, Tl, mid, l, r) + get (t -> r, mid + 1, Tr, l, r);
}

inline node* upd (node *t, int Tl, int Tr, int x) {
	if (Tl > x || Tr < x)
		return t;
	if (Tl == x && Tr == x)
		return new node (t -> x + 1);
	int mid = (Tl + Tr) / 2;
	return new node (upd (t -> l, Tl, mid, x), upd (t -> r, mid + 1, Tr, x));
}

main() {

	#ifdef LOCAL
	freopen("in", "r", stdin);
	#endif

	srand(23523);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];	

	for (int i = 2; i <= n; ++i) {
		int p, z;
		cin >> p >> z;
		g[p].eb (mp (i, z));
	}
	
	dfs (1);
	
	for (int i = 1; i <= n; ++i)
		b[i] = d[i] - a[i];
	
	for (int i = 1; i <= n; ++i)
		cc.eb (b[i]);
	for (int i = 1; i <= n; ++i)
		cc.eb (d[i]);
	
	sort (cc.begin (), cc.end ());
	cc.resize (unique (cc.begin (), cc.end ()) - cc.begin ());

	for (int i = 1; i <= n; ++i)
		b[i] = lower_bound (cc.begin (), cc.end (), d[i] - a[i]) - cc.begin ();
	
	for (int i = 1; i <= n; ++i)
		c[tin[i]] = b[i];

	for (int i = 1; i <= n; ++i)
		qu[tout[i]].eb (i);
	
	root[0] = Build (0, cc.size ());
	
	
	for (int i = 1; i <= n; ++i) {
		root[i] = upd (root[i - 1], 0, cc.size (), c[i]);
		for (auto v : qu[i]) {
			ans[v] = get (root[i], 0, cc.size (), 0, lower_bound (cc.begin (), cc.end (), d[v]) - cc.begin ()) - get (root[tin[v]], 0, cc.size (), 0, lower_bound (cc.begin (), cc.end (), d[v]) - cc.begin ());
		}
	}
	
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << " ";
	
	return 0;
}
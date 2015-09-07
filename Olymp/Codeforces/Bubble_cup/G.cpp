#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100;

int st[N];
int d[N], d2[N], p[N];
bool u[N];

int n, m;
vector <pair <int, int> > g[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);


	cin >> n >> m;
	
	for (int i = 0; i < m; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		g[x].emplace_back (make_pair (y, z));
		g[y].emplace_back (make_pair (x, z));
	}

	d[0] = 1;
	d2[n - 1] = 1;

	int stq = 0, enq = 0;

	st[enq++] = n - 1;

	while (stq < enq) {
		int v = st[stq++];
		for (auto to : g[v]) {
			if (!to.second && !d2[to.first]) {
				p[to.first] = v;
				d2[to.first] = d2[v] + 1;
				st[enq++] = to.first;
			}
		}
	}
	
	
	stq = enq = 0;

	st[enq++] = 0;
	
	while (stq < enq) {
		int v = st[stq++];
		for (auto to : g[v]) {
			if (!d[to.first]) {
				d[to.first] = d[v] + 1;
				st[enq++] = to.first;
			}
		}
	}
	
	
	int mn = 1e9;
	
	for (int i = 0; i < n; ++i)
		if (d2[i])
			mn = min (mn, d[i]);

	vector <int> now, nxt;

	for (int i = 0; i < n; ++i)
		if (d2[i] && d[i] == mn)
			nxt.emplace_back (i);
	
	for (auto v : nxt)
		u[v] = 1;

	bool ok = 0;
	
	for (int i = 0; i < n; ++i)
		if (!d2[i])
			d2[i] = 1e9;
	
	
	while (nxt.size ()) {
		now = nxt;
		nxt.clear ();
		int x = 10;
		
		for (auto v : now)
			for (auto to : g[v])
				if (d[to.first] + 1 == d[v])
					x = min (x, to.second);
		
		for (auto v : now)
			for (auto to : g[v])
				if (d[to.first] + 1 == d[v] && x == to.second)
					d2[to.first] = min (d2[to.first], d2[v]);

		for (auto v : now)
			for (auto to : g[v])
				if (d[to.first] + 1 == d[v] && to.second == x && !u[to.first] && d2[to.first] == d2[v])
					nxt.emplace_back (to.first), p[to.first] = v, u[to.first] = 1;
		
		if (x == 10)
			break;
		cout << x;
		ok = 1;
	}
	
	
	if (!ok)
		cout << 0;
	
	cout << "\n";
	
	vector <int> ans;
	
	int v = 0;

	
	while (v != n - 1) {
		ans.emplace_back (v), v = p[v];
	}
	ans.emplace_back (n - 1);

	cout << ans.size () << "\n";

	for (auto v : ans)
		cout << v << " ";

	return 0;
}
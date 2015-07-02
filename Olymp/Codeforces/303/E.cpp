#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 100;

typedef long long ll;

const ll inf = 1e16;

#define mkp make_pair

int n, m;
int x[N], y[N], c[N], st;
int p[N], a[N];
bool u[N];
ll d[N];
vector <int> g[N];
set <pair <int, int> > Set;

inline bool cmp (const int &x, const int &y) {
	return c[x] < c[y];
}

int main () {
    #ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);

	cin >> n >> m;

	for (int i = 1; i <= m; ++i) {
		cin >> x[i] >> y[i] >> c[i];
		g[x[i]].push_back (i);
		g[y[i]].push_back (i);
	}

	cin >> st;
	
	for (int i = 1; i <= n; ++i)
		d[i] = inf;

	d[st] = 0;

	Set.insert (mkp (d[st], st));

	while (Set.size ()) {
		int v = Set.begin () -> second;
		Set.erase (Set.begin ());
		for (auto it : g[v]) {
			int to = (x[it] == v) ? y[it] : x[it];
			if (d[to] > d[v] + c[it]) {
				Set.erase (mkp (d[to], to));
				d[to] = d[v] + c[it];
				Set.insert (mkp (d[to], to));
			}
		}
	}
	
	ll ans = 0;

	for (int i = 1; i <= m; ++i)
		a[i] = i;
	
	sort (a + 1, a + m + 1, cmp);
	
	for (int it = 1; it <= m; ++it) {
		int i = a[it];
		if (d[x[i]] > d[y[i]])
			swap (x[i], y[i]);
		if (!u[y[i]] && d[x[i]] + c[i] == d[y[i]]) {
			u[y[i]] = 1;
			p[y[i]] = i;
		}
	}
	
	memset (u, 0, sizeof (u));
	
	for (int i = 1; i <= n; ++i) {
		u[p[i]] = 1;
		ans += c[p[i]];
	}
	
	cout << ans << "\n";
	
	for (int i = 1; i <= m; ++i)
		if (u[i])
			cout << i << " ";
	return 0;
}
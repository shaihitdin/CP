#include <bits/stdc++.h>

using namespace std;

#define mkp make_pair
#define F first
#define S second
struct mine {
	int x, y;
	mine (const int &t1, const int &t2) {
		x = t1;
		y = t2;
	}
};
const int N = 1e5 + 1, inf = 1e9;
inline bool operator < (const mine &a, const mine &b) {
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

set <pair <mine, int> > s;
vector <pair <int, int> > g[N];
vector <int> ans;
bool u[N];
int pe[N], a[N], b[N], c[N], n, m, d[N], d2[N];
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d%d", &n, &m);
	for (int i = m; i; --i) {
		scanf ("%d%d%d", &a[i], &b[i], &c[i]);
		g[a[i]].push_back (mkp (b[i], i));
		g[b[i]].push_back (mkp (a[i], i));
	}
	for (int i = 2; i <= n; ++i)
		d[i] = inf;
	s.insert (mkp ((mine){0, 0}, 1));
	while (s.size()) {
		auto temp = *s.begin();
		int v = temp.S, dist = d[v], bad = d2[v];
		s.erase (s.begin ());
		for (auto to : g[v]) {
			
			if (d[to.F] > dist + 1 || (d[to.F] == dist + 1 && bad + (!c[to.S]) < d2[to.F])) {
				s.erase (mkp ((mine){d[to.F], d2[to.F]}, to.F));
				d[to.F] = dist + 1;
				d2[to.F] = bad + (!c[to.S]);
				pe[to.F] = to.S;
				s.insert (mkp ((mine){d[to.F], d2[to.F]}, to.F));
			}
		}
	}
	int v = n;
	while (v != 1) {
		u[pe[v]] = 1;
		v = (v == a[pe[v]]) ? b[pe[v]] : a[pe[v]]; 
	}
	for (int i = 1; i <= m; ++i) {
		if (u[i] != c[i]){
			ans.push_back (a[i]);
			ans.push_back (b[i]);
			ans.push_back (!c[i]);	
		}
	}
	printf ("%d\n", ans.size() / 3);
	for (int i = 0; i < ans.size(); i += 3) {
		printf ("%d %d %d\n", ans[i], ans[i + 1], ans[i + 2]);
	}
	return 0;
}
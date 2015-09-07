#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100;

int mn[N], mx[N], tmn[N], tmx[N], n;
vector <int> ans, g[N];

inline void dfs (const int &v) {
	tmn[v] = 0;
	tmx[v] = 1;
	for (auto to : g[v]) {
		dfs (to);
		tmn[v] += tmn[to];
		tmx[v] += tmx[to];
	}
	tmn[v] = max (tmn[v], mn[v]);
	tmx[v] = min (tmx[v], mx[v]);
}

inline void place (const int &v, int cnt) {
	int mncan = 0;
	for (auto to : g[v])
		mncan += tmn[to];
	cnt -= mncan;
	for (auto to : g[v]) {
		int add = tmx[to] - tmn[to];
		add = min (add, cnt);
		cnt -= add;
		place (to, tmn[to] + add);
	}
	if (cnt == 1)
		ans.emplace_back (v);
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	scanf ("%d", &n);

	for (int i = 1; i <= n; ++i) {
		int fl;
		scanf ("%d%d%d", &mn[i], &mx[i], &fl);
		while (fl--) {
			int x;
			scanf ("%d", &x);
			g[i].emplace_back (x);
		}
	}
	
	dfs (1);
	place (1, tmn[1]);
	
	printf ("%d\n", ans.size ());

	for (auto it : ans)
		printf ("%d ", it);
	
	return 0;
}
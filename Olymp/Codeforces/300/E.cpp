#include <bits/stdc++.h>

using namespace std;

const int N = 1e6, inf = 1e9;

int d1[N], d2[N];

vector <int> g[N];

int cnt[N];

inline void dfs (const int &v) {
	if (!g[v].size ()) {
		cnt[v] = 1;
		return;
	}
	for (auto to : g[v]) {
		dfs (to);
		cnt[v] += cnt[to];
	}
}


inline void tactic1 (const int &v, const int &t, const int &l) {
	if (!g[v].size ()) {
		d1[v] = l;
		return;
	}

	if (t == 1) {
		for (auto to : g[v]) {
			tactic1 (to, !t, l + (cnt[v] - cnt[to]));
			d1[v] = max (d1[v], d1[to]);
		}
	} else {
		d1[v] = inf;
		for (auto to : g[v]) {
			tactic1 (to, !t, l);
			d1[v] = min (d1[v], d1[to]);
		}	
	}
}

inline void tactic2 (const int &v, const int &t, const int &r) {
	if (!g[v].size ()) {
		d2[v] = r;
		return;
	}
	
	if (t == 1) {
		for (auto to : g[v]) {
			tactic2 (to, !t, r);
			d2[v] = max (d2[v], d2[to]);
		}
	} else {
		d2[v] = inf;
		for (auto to : g[v]) {
			tactic2 (to, !t, r - (cnt[v] - cnt[to]));
			d2[v] = min (d2[v], d2[to]);
		}	
	}
}

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	int n;

	scanf ("%d", &n);

	int x, y;
	
	for (int i = 1; i < n; ++i) {
		scanf ("%d%d", &x, &y);
		g[x].push_back (y);
	}
	
	dfs (1);

	tactic1 (1, 1, 1);
	
	cout << d1[1] << " ";
	
	tactic2 (1, 1, cnt[1]);

	cout << d2[1] << " ";
	
	return 0;
}
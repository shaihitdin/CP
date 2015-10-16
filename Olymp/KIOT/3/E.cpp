#include <bits/stdc++.h>

using namespace std;

int cnt;

const int N = 1e5 + 100;

#define end canfskf

int t1[N], t2[N];
int lvl[N], pos[N], beg[N];
vector <int> g[N];
int end[N];

inline int get (int t[], int x) {
	int res = 0;
	for (; x >= 0; x = (x & (x + 1)) - 1)
		res += t[x];
	return res;
}

inline void upd (int t[], int x, const int &delta) {
	for (; x < N; x = (x | (x + 1)))
		t[x] += delta;
}

inline int dfs (const int &v, const int &p, const int &bg) {
	pos[v] = ++cnt;
	lvl[v] = lvl[p] + 1;
	beg[v] = bg;
	for (auto to : g[v]) {
		if (to == p)
			continue;
		end[v] = dfs (to, v, bg);
	}
	if (!end[v])
		return end[v] = pos[v];
	return end[v];
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n, m;
	
	cin >> n >> m;

	for (int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].emplace_back (y);
		g[y].emplace_back (x);
	}

	for (auto to : g[1])
		dfs (to, 1, cnt + 1);
	
	//t2 -> exact tree, t1 -> all nodes with lvl x

	while (m--) {
		int q_type;
		cin >> q_type;
		int v, x, d;
		if (q_type == 0) {
			cin >> v >> x >> d;
			if (v == 1) {
				upd (t1, 0, x);
				upd (t1, d + 1, -x);
				continue;
			}
			if (beg[v] + d <= pos[v]) {
				upd (t2, pos[v] - d, x);
			} else {
				upd (t1, 0, x);
				upd (t1, d - (pos[v] - beg[v]), -x);
/*
				upd (t2, beg[v], -x);
				upd (t2, min (end[v], beg[v] + d - (pos[v] - beg[v]) - 1), x);
*/
				upd (t2, min (end[v] + 1, beg[v] + d - (pos[v] - beg[v]) - 1), x);

			}
			upd (t2, min (end[v], pos[v] + d) + 1, -x);
		} else {
			cin >> v;
			if (v == 1) {
				cout << get (t1, lvl[v]) << "\n";
			} else {
				cout << get (t1, lvl[v]) + get (t2, pos[v]) << "\n";
			}
		}
		for (int v = 1; v <= n; ++v) {
			if (v == 1) {
				cerr << get (t1, lvl[v]) << " ";
			} else {
				cerr << get (t1, lvl[v]) + get (t2, pos[v]) << " ";
			}		
		}
		cerr << "\n";
	}

	return 0;
}
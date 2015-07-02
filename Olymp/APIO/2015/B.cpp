#include <bits/stdc++.h>

using namespace std;

#define mkp make_pair
#define F first
#define S second

const int N = 2002, M = 30002, inf = 31000;

short n, m, pos[M], jump[M];

vector <short> g[N];

short d[N][M];

queue <pair <short, short> > st;

bool u[N];

int main () {

	/*
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	*/

	ios_base :: sync_with_stdio (0);

	cin >> n >> m;

	for (int i = 0; i < m; ++i)
		cin >> pos[i] >> jump[i];
	
	for (int i = 0; i < m; ++i)
		g[pos[i]].push_back (i);
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			d[i][j] = inf;

	for (auto it : g[pos[0]]) {
		d[pos[0]][it] = 0;
		st.push (mkp (pos[0], it));
	}		


	while (st.size ()) {
		int v1 = st.front ().F, v2 = st.front ().S;
		st.pop ();
		for (int to = v1 - jump[v2]; to <= v1 + jump[v2]; to += jump[v2] + jump[v2]) {
			if (to >= 0 && to < n && d[to][v2] == inf) {
				d[to][v2] = d[v1][v2] + 1, st.push (mkp (to, v2));
				if (!u[to]) {
					u[to] = 1;
					for (auto it : g[to])
						d[to][it] = d[to][v2], st.push (mkp (to, it));
				}
			}
		}
	}

	short ans = inf;
	
	for (int i = 0; i < m; ++i)
		ans = min (ans, d[pos[1]][i]);

	if (ans == inf)
		cout << -1;
	else
		cout << ans;

	cout << "\n";
	
	return 0;
}
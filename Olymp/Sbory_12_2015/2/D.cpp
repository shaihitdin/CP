#include <bits/stdc++.h>

using namespace std;

const int N = 2100, oo = 1e9;

vector <pair <int, int> > gg[N];

int d[5][N];
int n;

inline void dijkstra (int d[], int v) {
	for (int i = 1; i <= n; ++i)
		d[i] = oo;
	set <pair <int, int> > Set;
	d[v] = 0;
	Set.insert (make_pair (d[v], v));
	while (Set.size ()) {
		int u = Set.begin () -> second;
		Set.erase (Set.begin ());
		for (auto to : gg[u]) {
			if (d[to.first] > d[u] + to.second) {
				Set.erase (make_pair (d[to.first], to.first));
				d[to.first] = d[u] + to.second;
				Set.insert (make_pair (d[to.first], to.first));
			}
		}
	}
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int t_num;

	cin >> t_num;

	while (t_num--) {
		int m, t;
		cin >> n >> m >> t;
		int s, g, h;
		cin >> s >> g >> h;
		for (int i = 1; i <= n; ++i)
			gg[i].clear ();
		int cost = 0;
		for (int i = 1; i <= m; ++i) {
			int x, y, z;
			cin >> x >> y >> z;
			if ((x == g && y == h) || (x == h && y == g))
				cost = z;
			gg[x].emplace_back (make_pair (y, z));
			gg[y].emplace_back (make_pair (x, z));
		}
		bool u[N];
		memset (u, 0, sizeof (u));
		for (int i = 1; i <= t; ++i) {
			int x;
			cin >> x;
			u[x] = 1;
		}
		dijkstra (d[0], s);
		dijkstra (d[1], g);
		dijkstra (d[2], h);
		for (int i = 1; i <= n; ++i) {
			if (u[i]) {
				if (d[1][i] < d[2][i]) {
					if (d[1][i] + d[0][h] + cost == d[0][i])
						u[i] = 1;
					else
						u[i] = 0;
				} else {
					if (d[2][i] + d[0][g] + cost == d[0][i])
						u[i] = 1;
					else
						u[i] = 0;
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (u[i])
				cout << i << " ";
		}
		cout << "\n";
	}

	return 0;
}
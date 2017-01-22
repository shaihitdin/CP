#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

set <int> c[N * 3], g[N];

int st[2][N], stq[2], enq[2];
int color[N];
int n;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		color[i] = i;
		c[i].insert (i);
	}	

	int fire = n;
	
	while (228) {
		char q_type;
		cin >> q_type;
		if (q_type == 'E')
			return 0;
		int a, b;
		cin >> a >> b;
		if (q_type == 'C') {
			g[a].insert (b);
			g[b].insert (a);
			if (c[color[a]].size () < c[color[b]].size ())
				swap (a, b);
			int xx = color[b];
			for (auto it : c[xx]) {
				c[color[a]].insert (it);
				color[it] = color[a];
			}
			c[xx].clear ();
		} else if (q_type == 'D') {
			g[a].erase (b);
			g[b].erase (a);
			stq[0] = enq[0] = stq[1] = enq[1] = 0;
			st[0][enq[0]++] = a;
			st[1][enq[1]++] = b;
			set <int> u;
			u.insert (a);
			u.insert (b);
			for (int pw = 2;; pw <<= 1) {
				for (int i = 0; i < 2; ++i) {
					while (stq[i] != enq[i]) {
						int v = st[i][stq[i]];
						for (auto it : g[v]) {
							if (u.insert (it).second) {
								st[i][enq[i]++] = it;
								if (enq[i] == pw)
									goto end;
							}
						}
						stq[i]++;
					}
					end:;
				}
				if (stq[0] == enq[0] || stq[1] == enq[1])
					break;
			}
			int cc = color[a];
			++fire;
			if (stq[0] == enq[0]) {
				for (int i = 0; i < enq[0]; ++i) {
					c[fire].insert (st[0][i]);
					c[cc].erase (st[0][i]);
					color[st[0][i]] = fire;
				}
			} else {
				for (int i = 0; i < enq[1]; ++i) {
					c[fire].insert (st[1][i]);
					c[cc].erase (st[1][i]);
					color[st[1][i]] = fire;
				}
			}
		} else if (q_type == 'T') {
			if (color[a] == color[b])
				cout << "YES\n";
			else
				cout << "NO\n";
			fflush (stdout);
		}
	}
}
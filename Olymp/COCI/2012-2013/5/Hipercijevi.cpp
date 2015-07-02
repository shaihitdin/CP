#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

const int N = 2e5;

vector <pii> g[N];

int st[N * 2], stq = N, enq = N;

int n, d[N];

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	ios_base :: sync_with_stdio (0);

	int n, k, m;

	scanf ("%d%d%d", &n, &k, &m);

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= k; ++j) {
			int x;
			scanf ("%d", &x);
			g[x].push_back (pii (n + i, 0));
			g[n + i].push_back (pii (x, 1));
		}
	}

	for (int i = 1; i <= n + m; ++i)
		d[i] = N;

	d[1] = 1;
	st[enq++] = 1;

	while (stq < enq) {
		int v = st[stq++];
		for (auto it : g[v]) {
			int to = it.first, dist = it.second;
			if (d[to] > d[v] + dist) {
				d[to] = d[v] + dist;
				if (dist == 1) {
					st[enq++] = to;
				} else {
					st[--stq] = to;
				}
			}
		}
	}

	if (d[n] != N)
		printf ("%d", d[n]);
	else
		printf ("-1");

	return 0;
}
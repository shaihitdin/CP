#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
const int N = (2e5) + 1, M = 501, inf = 1e9;
int d[N][M], dist[N], temp[M], stq, enq, st[N], v, b[N], from;
vector <int> g[N];
int n, m, p, a[N];
bool cmp (const int &x, const int &y) {
	return dist[x] > dist[y];
}
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d%d", &p, &a[i]);
		g[p].push_back (i);
	}
	stq = enq = 0;
	st[enq++] = 0;
	while (stq < enq) {
		v = st[stq++];
		for (auto to : g[v]) {
			dist[to] = dist[v] + 1;
			st[enq++] = to;
		}
	}
	for (int i = 1; i <= n; ++i)
		b[i] = i;
	sort (b + 1, b + n + 1, cmp);
	for (int i = 1; i <= n; ++i) {
		from = b[i];
		for (int to : g[from]) {
			for (int j = 0; j <= m; ++j)
				temp[j] = 0;
			for (int j = 1; j <= m; ++j)
				for (int k = 0; k + j <= m; ++k)
					temp[j + k] = max (d[from][k] + d[to][j], temp[j + k]);
			for (int j = 0; j <= m; ++j)
				d[from][j] = max (d[from][j], temp[j]);
		}
		d[from][1] = max (d[from][1], a[from]);
	}
	printf ("%d", d[b[n]][m]);
	return 0;
}
#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
const int N = (2e5) + 1, M = 501, inf = 1e9;
int d[N][M], dist[N], temp[M], stq, enq, st[N], v, b[N], from;
vector <int> g[N];
int n, m, p, a[N];
inline int g_max (const int &x, const int &y) {
	return x > y ? x : y;
}
inline bool cmp (const int &x, const int &y) {
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
	int l, r, mid1, mid2;
	for (int i = 1; i <= n; ++i) {
		from = b[i];
		for (int to : g[from]) {
			memset (temp, 0, sizeof(temp[0]) * (m + 1));
			for (int j = 1; j <= m; ++j) {
				l = 0, r = j;
				while (r - l > 2) {
					mid1 = (r + l) >> 1;
					mid2 = mid1 + 1;
					if (d[from][mid1] + d[to][j - mid1] > d[from][mid2] + d[to][j - mid2])
						r = mid2;
					else
						l = mid1;
				}
				for (int k = l; k <= r; ++k)
					temp[j] = g_max (temp[j], d[from][k] + d[to][j - k]);
			}
			for (int j = 1; j <= m; ++j)
				d[from][j] = g_max (d[from][j], temp[j]);
		}
		d[from][1] = g_max (d[from][1], a[from]);
	}
	printf ("%d", d[b[n]][m]);
	return 0;
}
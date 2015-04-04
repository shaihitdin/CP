#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
const int inf = 1e9;
const int N = 2e5;
vector <int> g[N];
int st[N], stq, enq;
int d[12][N], dist[N], num[12][N];
int s[N], n, m, x, y;
inline bool cmp (const int &x, const int &y) {
	return dist[x] < dist[y];
}
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf ("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i = 1; i <= 11; ++i)
		for (int j = 1; j <= n; ++j)
			d[i][j] = inf;
	for (int i = 1; i <= n; ++i)
		dist[i] = inf;
	scanf ("%d", &x);
	for (int i = 1; i <= x; ++i) {
		scanf ("%d", &y);
		dist[y] = 0;
		d[1][y] = 0;
		num[1][y] = y;
		st[++enq] = y;
	}
	while (stq < enq) {
		int v = st[++stq];
		for (auto to : g[v]) {
			if (dist[to] == inf) {
				dist[to] = dist[v] + 1;
				st[++enq] = to;
			}
		} 
	}
	for (int i = 1; i <= n; ++i)
		s[i] = i;
	sort (s + 1, s + n + 1, cmp);
	for (int i = 1; i <= 11; ++i)
		for (int j = 1; j <= n; ++j) {
			int from = s[j];
			for (auto to : g[from]) {
				bool flag = 0;
				for (int k = 1; k < i; ++k) {
					if (num[k][from] == num[i - 1][to]) {
						flag = 1;
						k = i;
					}
				}
				if (!flag && d[i][from] > d[i - 1][to] + 1) {
					d[i][from] = d[i - 1][to] + 1;
					num[i][from] = num[i - 1][to];
				}
				if (d[i][from] > d[i][to] + 1) {
					d[i][from] = d[i][to] + 1;
					num[i][from] = num[i][to];
				}
			}
		}
	int k;
	scanf ("%d", &k);
	for (int i = 1; i <= n; ++i)
			if (d[k + 1][i] == inf)
				printf ("-1 ");
			else
				printf ("%d ", num[k + 1][i]);
	return 0;
}
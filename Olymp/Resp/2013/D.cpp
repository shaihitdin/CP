#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
const int N = (5e5) + 1;
const long long inf = 1e15;
long long d[1 << 12];
bool u[N];
vector <int> g[N], gr[N], top, gg[N];
int col[N], s[N];
int b, n, m, k, x, cnt;
int TL;
int t_mask[N], mask[N];
int sz;
void TLE () {
	if (TL <= clock() * 1000 / CLOCKS_PER_SEC)
    	exit(1);		
}
void top_sort (const int &v) {
	u[v] = 1;
	for (auto to : g[v])
		if (!u[to])
			top_sort (to);
	top.push_back(v);
}
void dfs (const int &v, const int &color) {
	u[v] = 1;
	col[v] = color;
	for (auto to : gr[v])
		if (!u[to])
			dfs (to, color);  
}
void dfs1 (const int &v) {
	u[v] = 1;
	for (auto x : gg[v]) {
		if (!u[x])
			dfs1(x);
		t_mask[v] |= t_mask[x];
	}
}
int main (int argc, char *argv[]) {
	TL = atoi(argv[1]);
	freopen ("D.in", "r", stdin);
	freopen ("D.out", "w", stdout);
	scanf ("%d%d%d", &b, &n, &m);
	for (int i = 0; i < (1 << b); ++i)
		d[i] = inf;
	for (int i = 0; i < b; ++i) {
		scanf ("%d", &k);
		for (int j = 1; j <= k; ++j) {
			scanf ("%d", &x);
			++cnt;
			s[cnt] = x;
			mask[cnt] = (1 << i);
		}
	}
	for (int i = n + 1; i <= n + m; ++i) {
		scanf ("%d%d", &s[i], &k);
		for (int j = 1; j <= k; ++j) {
			scanf ("%d", &x);
			g[i].push_back(x);
			gr[x].push_back(i);
		}
	}
	for (int i = 1; i <= n + m; ++i)
		if (!u[i])
			top_sort(i);
	memset (u, 0, sizeof(u));
	reverse (top.begin(), top.end() );
	for (auto x : top)
		if (!u[x])
			dfs(x, ++sz);
	memset (u, 0, sizeof(u));
	for (int i = 1; i <= n; ++i)
		u[col[i]] = 1, t_mask[col[i]] = mask[i];
	for (int i = n + 1; i <= n + m; ++i)
		for (auto x : g[i])
			gg[col[i]].push_back(col[x]);
	for (int i = 1; i <= sz; ++i)
		if (!u[i])
			dfs1(i);

	for (int i = 1; i <= n + m; ++i)
		d[t_mask[col[i]]] = min (s[i] * 1LL, d[t_mask[col[i]]]);
	d[0] = 0;
	for (int i = 0; i < (1 << b); ++i)
		for (int j = 0; j < (1 << b); ++j)
			d[i | j] = min (d[i | j], d[j] + d[i]);
	TLE();
	printf ("%I64d", d[(1 << b) - 1]);
	return 0;
}
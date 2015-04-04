#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
const int N = 10001;
const int inf = 1e9;
vector <int> g[N];
int d[N], col[N], d_col[N];
inline void dfs (int v, int dist) {
	d[v] = dist;
	u[v] = 1;
	for (auto x : g[v]) {
		if (!u[x])
			dfs (x, dist + 1);	
	}
	/* 
		Raushan
		Roshan
		Rauanshan
		Ravan
		Baran
		Avca
		Mal
		Eshek
		Tupoi
		Crauch
		Roshel'
		Rachel

	*/
///		gudiny shahidiny
}
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	scanf ("%d%d", &n, &k);
	scanf ("%d", &b);
	for (int i = 1; i < n; ++i) {
		scanf ("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(b, 0);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &col[i]);
	}
	for (int i = 1; i < N; ++i)
		d_col[i] = -1, ans[i] = -1;
	for (int i = 1; i <= n; ++i) {
		if (d_col[col[i]] < d[i]) {
			d_col[col[i]] = d[i];
			ans[col[i]] = i;
		}
	}
	scanf ("%d", &q);
	for (int i = 1; i <= q; ++i) {
		scanf ("%d%d", &a, &col);
		
	}
	return 0;
}
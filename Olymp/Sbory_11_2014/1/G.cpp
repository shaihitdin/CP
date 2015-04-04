#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
vector <int> g[1001],gr[1001];
vector <int> top_sort;
bool u[1001],d[100001],banned[1001];
vector <int> l;
int n,k,x;
int num[1001];
void dfs1 (int v) {
	u[v] = 1;
	for (int i = 0; i < g[v].size(); ++i) {
		if (!u[g[v][i]] && !banned[g[v][i]]) {
			dfs1(g[v][i]);
		}
	}
	top_sort.push_back(v);
}
int dfs2 (int v) {
	u[v] = 1;
	int res = 1;
	for (int i = 0; i < g[v].size(); ++i) {
		if (!u[g[v][i]]) {
			res += dfs2(g[v][i]);
		}
	}
	return res;
}
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		if (x == i) {
			continue;
		}
		g[i].push_back (x);
		gr[x].push_back (i);
	}
	d[n] = 1;
	for (int i = 1; i <= n; ++i) {
		if (!u[i]) {
			dfs1 (i);
		}
	}
	memset (u, 0, sizeof(u));
	reverse (top_sort.begin(), top_sort.end());
	for (int i = 0; i < top_sort.size(); ++i) {
		int v = top_sort[i];
		if (!u[v] && !banned[v]) {
			l.push_back (dfs2 (v));
		}		
	}
	for (int i = 0; i < l.size(); ++i) {
		cerr << l[i] << " ";
		for (int j = 0; j <= n; ++j) {
			if (d[j]) {
				d[j - l[i]] = 1;
			}
		}
	}
	d[0] = 1;
	while (!d[k]) --k;
	cout << k;
	return 0;
}
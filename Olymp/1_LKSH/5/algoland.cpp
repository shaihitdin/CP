#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<utility>
#include<iostream>
#include<string.h>
using namespace std;
#define mkp make_pair
#define F first
#define S second
const int N = 10001;
vector<pair <int, int> > a[N];
int  x, y, z, n, m, s, f;
long long d[N], d1[N];
bool u[N];
void dfs(int v) {
	u[v] = 1;
	for(int i = 0; i < (int)a[v].size(); ++i) {
		int to = a[v][i].F;
		if(u[to]) {
			d[v] = min(d[v], max(d[to], a[v][i].S*1ll));
		} else {
			d[to] = max(d[v], a[v][i].S*1ll);
			dfs(to);
			d[v] = min(d[v], d[to]);
		}
	}
}
void dfs1(int v) {
	u[v] = 1;
	for(int i = 0; i < (int)a[v].size(); ++i) {
		int to = a[v][i].F;
		if(u[to]) {
			d1[v] = min(d1[v], max(d[to]+(a[v][i].S*1ll), d1[to]));
		} else {
			d1[to] = max(d[v]+(a[v][i].S*1ll), d1[v]);
			dfs1(to);
			d1[v] = min(d1[v], max(d1[to], d[to]+(a[v][i].S*1ll)));
		}
	}
}
int main() {
		freopen("algoland.in", "r", stdin);
		freopen("algoland.out", "w", stdout);
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= m; ++i) {
			scanf("%d %d %d", &x, &y, &z);
			a[x].push_back(mkp(y, z));
			a[y].push_back(mkp(x, z));
		}
		scanf("%d %d", &s, &f);
		dfs(s);
		for(int i = 1; i <= n; ++i) {
			u[i] = 0;
		}
		dfs1(s);
		printf("%lld", d1[f]);
return 0;}
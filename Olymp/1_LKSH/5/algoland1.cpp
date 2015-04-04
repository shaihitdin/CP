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
pair<long long,long long> d1[N];
bool u[N];
void dfs1(int v) {
	u[v] = 1;
	for(int i = 0; i < (int)a[v].size(); ++i) {
		if(d1[v].F>d1[v].S)
		 	swap(d1[v].F,d1[v].S);
		int to = a[v][i].F;
		if(u[to]) {
			
		} else {

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
		dfs1(s);
		for(int i = 1; i <= n; ++i) {
			cerr<<d1[i]<<" ";
		}
		printf("%lld", d1[f]);
return 0;}
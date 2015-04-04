#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
const int N = 501*501, M = 10001*50;
long long n, m, x, y, cap, cost, sz;
long long d[N], s, f, i;
vector<long long> v[N];
long long q[N], stq, enq;
struct edge {
	long long y, cap, flow;
}e[M];
long long push, pos[N], ans;
inline void add_edge() {
	edge e1 = {y, 1, 0}, e2 = {x, 0, 0};
	v[x].push_back(sz);
	e[sz++] = e1;
	v[y].push_back(sz);
	e[sz++] = e2;
}
inline bool bfs() {
	q[++enq] = s;
	d[s] = 1;
	while(stq < enq) {
		x = q[++stq];
		for(i = 0; i < (int)v[x].size(); ++i) {
			int id = v[x][i], to = e[id].y;
			 if (d[to] == 0 && e[id].flow < e[id].cap)
			 	d[to] = d[x]+1, q[++enq] = to;
		}
	}
	return d[f] != 0;
}
inline long long dfs(long long x, long long flow = 1000000001*1ll) {
	if(x == f) return flow;
	if(!flow) return 0;
	for(; pos[x] < (int)v[x].size(); ++pos[x]) {
		int id = v[x][pos[x]], to = e[id].y;
		if(d[to] == d[x]+1) {
			int pushed = dfs(to, min(flow, e[id].cap-e[id].flow));
			if(pushed) {
				e[id].flow += pushed;
				e[id^1].flow -= pushed;
				return pushed;
			}
		}
	}
	return 0;
}
inline void dinitz() {
	while(bfs()) {
		while(true) {
			push = dfs(s);
			if(!push) break;
			ans += push;
		}
		memset(pos, 0, sizeof(pos));
		memset(d, 0, sizeof(d));
		enq = stq = 0;
	}
return ;}
int main() {
	freopen("pairs.in", "r", stdin);
	freopen("pairs.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for(i = 1; i <= n; ++i) {
		while(true) {
			scanf("%lld", &y);
			if(y == 0)	break;
			y += n;
			x = i;
			add_edge();
		}
	}
	s = n+m+1, f = n+m+2;
	for(i = 1; i <= n; ++i) {
		x = s;
		y = i;
		add_edge();
	}
	for(i = n+1; i <= n+m; ++i) {
		x = i;
		y = f;
		add_edge();
	}
	dinitz();
	printf("%lld\n", ans);
	for(i = 1; i <= n; ++i) {
		for(int j = 0; j < (int)v[i].size(); ++j) {
			int id = v[i][j];
			if(e[id].flow > 0) {
				printf("%lld %lld\n", i, e[id].y-n);
			}
		}
	}
return 0;}
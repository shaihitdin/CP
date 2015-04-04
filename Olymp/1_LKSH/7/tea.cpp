#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
const int N = 51*51*2;
long long n, m, x, y, cap, cost, sz;
long long d[N], s, f, i;
vector<long long> v[N];
long long q[N], stq, enq;
long long push, pos[N], ans;

struct edge {
	long long y, cap, flow;
}e[N];

inline void add_edge() {
	edge e1 = {y, cap, 0}, e2 = {x, 0, 0};
	v[x].push_back(sz);
	e[sz++] = e1;
	v[y].push_back(sz);
	e[sz++] = e2;
}

inline bool bfs() {
	q[++enq] = s;
	d[s] = 1;
	while (stq < enq) {
		x = q[++stq];
		for (i = 0; i < (int)v[x].size(); ++i) {
			int id = v[x][i], to = e[id].y;
			 if (d[to] == 0 && e[id].flow < e[id].cap)
			 	d[to] = d[x]+1, q[++enq] = to;
		}
	}
	return d[f] != 0;
}

inline long long dfs(long long x, long long flow) {
	if (x == f) return flow;
	if (!flow) return 0;
	for (; pos[x] < v[x].size(); ++pos[x]) {
		int id = v[x][pos[x]], to = e[id].y;
		if(d[to] == d[x]+1) { 	
			long long pushed = dfs(to, min(flow, e[id].cap-e[id].flow));
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
	memset(pos, 0, sizeof(pos));
	memset(d, 0, sizeof(d));
	enq = stq = 0;
	while (bfs()) {
		while (true) {
			push = dfs(s, 1000000001);
			if(!push) break;
			ans += push;
		}
		memset(pos, 0, sizeof(pos));
		memset(d, 0, sizeof(d));
		enq = stq = 0;
	}
return ;}

int main() {
	freopen("tea.in", "r", stdin);
	freopen("tea.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	s = n+m+1, f = n+m+2;
	for(i = 1; i <= m; ++i) {
		scanf("%lld", &cap);
		x = i+n;
		y = f;
		add_edge();
	}
	for(i = 1; i <= n; ++i) {
		x = s;
		y = i;
		cap = 1;
		add_edge();
		long long j;
		scanf("%lld", &j);
		x = i;
		cap = 1000000001;
		while(j--) {
			scanf("%lld", &y);
			y += n;
			add_edge();
		}
	}
     long long l = 0, r = 50000001, mid;
	while(r-l > 1) {
		mid = (r+l)/2;
		for(i = 0; i < (int)v[s].size(); ++i) {
			e[v[s][i]].cap = mid;
		}
		dinitz();
		if(ans == n*mid) 
			l = mid;
		else
			r = mid;
		ans = 0;
		for(i = 0; i < sz; ++i) e[i].flow = 0;
	}
	printf("%lld", l);
return 0;}
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
const int N = 501, M = 1001;
long long n, m, x, y, cap, sz;
long long d[N], s, f, i;
vector<long long> v[N];
long long q[N], stq, enq;
long long push, pos[N], ans;
long long Min, required;
long long limit = 1<<30;
long long flow_in_edge[M];

struct edge {
	long long y, cap, flow;
}e[M];

inline void add_edge(long long x, long long y, long long cap) {
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
	for (; pos[x] < (int)v[x].size(); ++pos[x]) {
		int id = v[x][pos[x]], to = e[id].y;
		if(d[to] == d[x] + 1) { 	
			long long pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
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
			long long push = dfs(s, 1 << 30);
			if(!push) break;
			ans += push;
		}
		memset(pos, 0, sizeof(pos));
		memset(d, 0, sizeof(d));
		enq = stq = 0;
	}
}

int main() {
	freopen("cooling.in", "r", stdin);
	freopen("cooling.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	s = n + 1, f = n + 2;
	for(i = 1; i <= m; ++i) {
		scanf("%lld%lld%lld%lld", &x, &y, &Min, &cap);
		add_edge(x, y, cap-Min);
		add_edge(x, f, Min);
		add_edge(s, y, Min);
		required += Min;
	}
	dinitz();
	/*
	cerr<<required<<" "<<ans<<"\n";
	for(i = 0; i < v[s].size(); ++i) {
		int id = v[s][i];
		if(e[id].flow > 0) {
			cerr<<(id/6)+1<<" "<<e[id].flow<<" | ";
		}
	}
	*/
	if(required != ans) {
		printf("NO");
		return 0;
	}
	printf("YES\n");
	for(i = 0; i < sz; i += 2) {
		if(i%4 != 0) {
			flow_in_edge[(i/6)+1] += e[i].flow;
		}
	}
	for(i = 1; i <= m; ++i) {
		printf("%lld\n", flow_in_edge[i]);
	}
return 0;
}
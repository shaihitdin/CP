#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
const int N = 501*501, M = 10001*10;
long long n, m, x, y, cap, cost, sz;
long long d[N], s, f, i;
vector<long long> v[N];
long long q[N], stq, enq;
long long push, pos[N], ans, res;

struct edge {
	long long y, cap, flow;
}e[M];
long long limit = 1<<30;

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
			 if (d[to] == 0 && e[id].flow + limit <= e[id].cap)
			 	d[to] = d[x] + 1, q[++enq] = to;
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
			long long pushed = dfs(to, min(flow, e[id].cap-e[id].flow));
			if(pushed) {
				e[id].flow += pushed;
				e[id ^ 1].flow -= pushed;
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

long long min_flow = 1 << 30;
long long tmp[N], sz1;

inline bool get_ans(int x) {
	if(x == f) {
		return 1;
	}
	for(int i = 0 ; i < (int)v[x].size(); ++i) {
		int id = v[x][i], to = e[id].y;
		if(e[id].flow > 0) {
			tmp[++sz1] = id;
			if(get_ans(to)) {
				min_flow = min(min_flow, e[id].flow);
				return 1;
			}
			else 
				--sz1;
		}
	}
return 0;}
vector <int> ans_v[M];
int main() {
	freopen("decomposition.in", "r", stdin);
	freopen("decomposition.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for(i = 1; i <= m; ++i) {
		scanf("%lld %lld %lld", &x, &y, &cap);
		add_edge();
	}
	s = 1, f = n;
	for(limit = 1 << 30; limit > 0; limit >>= 1) {
		dinitz();
	}
	int k = 0; 
	while(get_ans(s)) {
		ans_v[k].push_back(min_flow);
		ans_v[k].push_back(sz1);
		for(i = 1; i <= sz1; ++i) {
			ans_v[k].push_back(tmp[i] / 2 + 1);
			e[tmp[i]].flow -= min_flow;
		}
		sz1 = 0;
		min_flow = 1 << 30;
		++k;
	}
	printf("%d\n", k);
	for(i = 0; i < k; ++i) {
		for(int j = 0; j < (int)ans_v[i].size(); ++j) {
			printf("%d ", ans_v[i][j]);
		}
		printf("\n");
	}
return 0;}
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
const int N = 200001*3;
long long n, m, x, y, cap, cost, sz;
long long d[N], s, f, i;
vector<long long> v[N];
long long q[N], stq, enq;
long long push, pos[N], ans;
long long res[N];
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
int tmp[N], sz1;
bool ban[N];

inline bool get_ans(int x) {
	if(x == f) {
		tmp[++sz1] = x;
		return 1;
	}
	for(int i = 0 ; i < (int)v[x].size(); ++i) {
		int id = v[x][i], to = e[id].y;
		if(!ban[id] && e[id].flow == 1) {
			tmp[++sz1] = x;
			ban[id] = 1;
			if(get_ans(to)) 
				return 1;
			else 
				--sz1;
		}
	}
return 0;
}

int main() {
	freopen("snails.in", "r", stdin);
	freopen("snails.out", "w", stdout);
	scanf("%lld %lld %lld %lld", &n, &m, &s, &f);
	cap = 1;
	for(i = 1; i <= m; ++i) {
		scanf("%lld %lld", &x, &y);
		add_edge();
	}
	dinitz();
     if (ans < 2) {
     	printf("NO\n");
     	return 0;
     }
	printf("YES\n");
	while(get_ans(s)) {
		for (i = 1; i <= sz1; ++i) {
			printf("%d ", tmp[i]);
		}
		printf("\n");
		sz1 = 0;
	}
	return 0;
}
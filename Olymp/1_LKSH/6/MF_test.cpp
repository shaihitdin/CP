#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
const int N=25001,M=100001;
struct edge{
	long long y,cap,flow;
} e[N];
int pos[N], d[N], s, f, q[N], enq, stq, n, m, j, sz, i;
vector<int> v[N];
long long cap, flow, x, y, ans;
char tmp;

inline void add_edge() {
	edge e1 = {y, cap, 0}, e2 = {x, 0, 0};                         
	v[x].push_back(sz);
	e[sz++] = e1;
	v[y].push_back(sz);
	e[sz++] = e2;
}
inline bool bfs(){
	d[s] = 1;
	q[++enq] = s;
	while(stq < enq) {
		x = q[++stq];
		for(i = 0; i < (int)v[x].size(); ++i) {
			int id = v[x][i], to = e[id].y;
			if(d[to]==0 && e[id].flow < e[id].cap) {
				d[to] = d[x]+1;
				q[++enq] = to;
			}
		}
	}
	return d[f] != 0;
}
inline long long dfs(int x, long long flow) {
	if(!flow) return 0;
	if(x == f) return flow;
	for(; pos[x] < (int)v[x].size(); ++pos[x]) {
		int id = v[x][pos[x]], to = e[id].y;
		if(d[to] == d[x]+1){
			long long pushed = dfs(to, min(flow, e[id].cap-e[id].flow));
			if(pushed) {
				e[id].flow+=pushed;
				e[id^1].flow-=pushed;
				return pushed;
			}
		}
	}
	return 0;
}
inline void dinic() {
	while(bfs()) {
		while(1) {
			long long push = dfs(s,1000000001);
			if(!push)	break;
			ans+=push;
		}
		memset(d,0,sizeof(d));
		memset(pos,0,sizeof(pos));
		stq = enq = 0;
	}
}
int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for(i = 1; i <= m; ++i) {
		scanf("%lld %lld %lld", &x, &y, &cap);
		add_edge();
	}
	s = 1, f = n;
	dinic();
	printf("%lld", ans);
return 0;}
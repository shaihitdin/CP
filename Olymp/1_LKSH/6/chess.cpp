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
long long push, pos[N], ans;
char a[101][101];
long long col[101][101];
struct edge {
	long long y, cap, flow;
}e[M];

inline void add_edge() {
	edge e1 = {y, 1, 0}, e2 = {x, 0, 0};
	v[x].push_back(sz);
	e[sz++] = e1;
	v[y].push_back(sz);
	e[sz++] = e2;
}

inline bool bfs() {
	q[++enq] = s;
	while (stq < enq) {
		x = q[++stq];
		for (i = 0; i < (int)v[x].size(); ++i) {
			int id = v[x][i], to = e[id].y;
			 if (to != s && d[to] == 0 && e[id].flow < e[id].cap)
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
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	cin >> n >> m;
	for(i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			cin >> a[i][j];
			if(a[i][j] == 'W')
				col[i][j] = 0;
			else
				col[i][j] = 1; 
		}
	}
	s = 201, f = 202;
	for(i = 1; i <= 100; ++i) {
		x=s;
		y=i;
		add_edge();
	}
	for(i = 101; i <= 200; ++i) {
		x=i;
		y=f;
		add_edge();
	}
	for(i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(col[i][j] != ((i&1)^(j&1))){
				x = j+(i-1);
				y = j-(i-1)+m;
				add_edge();
			}
		}
	}
	dinitz();
	long long case1 = ans;
	sz = 0;
	for(i = 1; i <= 100; ++i) {
		x=s;
		y=i;
		add_edge();
	}
	for(i = 101; i <= 200; ++i) {
		x=i;
		y=f;
		add_edge();
	}
	for(i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(col[i][j] == ((i&1)^(j&1))){
				x = j+(i-1);
				y = j+(i-1)+100;
				add_edge();
			}
		}
	}
	dinitz();
	long long case2 = ans;
	/*
	if(case1 < case2) {
		
	}
	else {
	
	}
	*/
	cout<<case1<<" "<<case2;
return 0;}
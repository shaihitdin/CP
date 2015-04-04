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
long long push, pos[N], ans, res, s1, f1;
bool u[51], ansu[51];
struct edge {
	long long y, cap, flow;
}e[M];
char a[51][51];
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
	memset(pos, 0, sizeof(pos));
	memset(d, 0, sizeof(d));
	enq = stq = 0;
return ;}

int main() {
	freopen("mincut.in", "r", stdin);
	freopen("mincut.out", "w", stdout);
	cin >> n;
	for(i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			if(a[i][j] == '1') {
				x = i;
				y = j;
				add_edge();
			}
		}
	}
	res = 501;
	for(s = 1; s <= n; ++s) {
		for(f = s+1; f <= n; ++f) {
			dinitz();
			long long cnt = 0;
			q[++enq] = s;
			memset(u, 0, sizeof(u));
			u[s] = 1;
			while(stq < enq) {
				x = q[++stq];
               	for(int j = 0; j < (int)v[x].size(); ++j) {
					int id = v[x][j], to = e[id].y;
					if(e[id].flow > 0 && !u[to]) {
						u[to] = 1;
						q[++enq] = e[to].y;
					}
				}
			}
			for(i = 1; i <= n; ++i) {
				if(!u[i]) {
					for(int j = 0; j < (int)v[i].size(); ++j) {
						int id = v[i][j], to = e[id].y;
						if(u[to] && e[id].flow == 0 && e[id].cap != 0) {
							++cnt;
						}
					}
				}
			}
			/*
			cerr<<s<<" "<<f<<" "<<cnt<<"\n";
			for(i = 1; i <= n; ++i) {
				cerr<<u[i]<<" ";
			}
			cerr<<"\n";
			*/
			if(cnt != 0 && cnt < res) {
				s1 = s;
				f1 = f;
				res = cnt;
				for(i = 1; i <= n; ++i) {
					ansu[i] = u[i];
				}
			}
		}
	}
	for(i = 1; i <= n; ++i)
		if(!ansu[i]) cout << i << " ";
	cout << "\n";
	for(i = 1; i <= n; ++i)
		if(ansu[i])  cout << i << " ";
return 0;}
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
const int N = 25001, M = 100001;
struct edge {
	long long y, cap, flow;
} e[N];
int sz, i;
int pos[N], d[N], s, f, q[N], enq, stq, n, m, j, cnt;
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
			long long push = dfs(s, 1000000001);
			if(!push) break;
			ans += push;
		}
		memset(pos, 0, sizeof(pos));
		memset(d, 0, sizeof(d));
		enq = stq = 0;
	}
}
int main() {
		freopen("molecule.in", "r", stdin);
		freopen("molecule.out", "w", stdout);
		cin >> n >> m;
		int cnt1 = 0;
		s = (n+2)*m+1, f = (n+2)*m+2;
		for(i = 1; i <= n; ++i) {
			for(j = 1; j <= m; ++j) {
				cin >> tmp;
				if (tmp == 'H') cap = 1;
				else if (tmp == 'O') cap = 2;
				else if (tmp == 'N') cap = 3;
				else if (tmp == 'C') cap = 4;
				else cap = 0, ++cnt1;
				if(((i&1) ^ (j&1)) == 0) {
					x = s;
					y = (i*m)+j;
					add_edge();
					cap = 1;
					x = (i*m)+j;
					if(i > 1) {
						y = (i-1)*m+j;
						add_edge();
					}
					if(i < n) {
						y = (i+1)*m+j;
						add_edge();
					}
					if(j > 1) {
						y = (i*m)+(j-1);
						add_edge();
					}
					if(j < m) {
						y = (i*m)+(j+1);
						add_edge();
					}
				} else {
					x = (i*m)+j;
					y = f;
					add_edge();
				}
			}
		}
		
		if(cnt1 == n*m) {
			cout << "Invalid";
			return 0;
		}
		
		dinitz();
		for(i = 0; i < (int)v[s].size(); ++i) {
			int id = v[s][i];
			if(e[id].flow != e[id].cap) {
				cout << "Invalid";
				return 0;
			}
		}
		for(i = 0; i < (int)v[f].size(); ++i) {
			int id = v[f][i];
			if(e[id^1].flow != e[id^1].cap) {
				cout << "Invalid";
				return 0;
			}		
		}
		cout << "Valid";
return 0;}
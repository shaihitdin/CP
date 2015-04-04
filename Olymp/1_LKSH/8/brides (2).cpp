#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<utility>
#include<algorithm>
using namespace std;
const int N = 201;
const long long inf = 1000000001;
struct edge {
	long long y, cap, flow, cost;
}e[2001 * 4];
long long phi[N], d[N], pe[N], p[N];
set < pair < long long, int > > st;
int x, y, cap, flow, cost;
int sz;
int i, n, s, f, k, m;
vector <int> v[N];
long long total_flow, total_cost;
bool ban[2001 * 4];

void add_edge() {
	edge e1 = {y, cap, flow, cost}, e2 = {x, 0, 0, -cost};
	v[x].push_back(sz);
	e[sz++] = e1;
	v[y].push_back(sz);
	e[sz++] = e2;
}

inline bool dijkstra() {
	for(i = 1; i <= n; ++i)
		d[i] = inf;
	d[s] = 0;
	st.insert(make_pair(d[s], s));
	while(!st.empty()) {
		x = st.begin()->second;
		st.erase(st.begin());
		for(i = 0; i < (int)v[x].size(); ++i) {
			int id = v[x][i], to = e[id].y, cost = e[id].cost;
			if(e[id].flow < e[id].cap && d[to] > d[x] + phi[x] - phi[to] + cost) {
				st.erase(make_pair(d[to], to));
				d[to] = d[x] + phi[x] - phi[to] + cost;
				pe[to] = id;
				p[to] = x;
				st.insert(make_pair(d[to], to));
			}
		}
	}
	for(i = 1; i <= n; ++i)
		phi[i] = min(inf, phi[i]+d[i]);
	return d[f] != inf;
}

inline void MinCostMaxFlow() {
	while(total_flow < k && dijkstra()) {
		long long flow = 1;
		for(int j = f; j != s; j = p[j]) 
			flow = min(flow, e[pe[j]].cap-e[pe[j]].flow);
		for(int j = f; j != s; j = p[j]) {
			e[pe[j]].flow += flow, e[pe[j] ^ 1].flow -= flow;
			total_cost += (e[pe[j]].cost*flow);
		}
		total_flow += flow;
	}

return;}

int tmp[2001*4], sz1;

inline bool get_ans(int x) {
	if(x == f) {
		return 1;
	}
	for(int i = 0 ; i < (int)v[x].size(); ++i) {
		int id = v[x][i], to = e[id].y;
		if(!ban[id] && e[id].flow == 1) {
			tmp[++sz1] = (id/4)+1;
			ban[id] = 1;
			if(get_ans(to)) 
				return 1;
			else 
				--sz1;
		}
	}
return 0;}

int main() {
	freopen("brides.in", "r", stdin);
	freopen("brides.out", "w", stdout);
	scanf("%d %d %d\n", &n, &m, &k);
	s = 1, f = n;
	for(i = 1; i <= m; ++i) {
		cap = 1;
		scanf("%d %d %d\n", &x, &y, &cost);
		add_edge();
		swap(x, y);
		add_edge();
	}
	MinCostMaxFlow();
	if(total_flow != k) {
		cout << "-1";
		return 0;
	}
	printf("%.5lf\n", double(total_cost)/double(k));
	while(k--) {
		sz1 = 0;
		get_ans(s);
		printf("%d ", sz1);
		for(i = 1; i <= sz1; ++i) {
			printf("%d ", tmp[i]);
		}
		printf("\n");
	}
return 0;}
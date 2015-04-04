#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<utility>
#include<algorithm>
using namespace std;
const int N = 201, M = 2001 * 4;
const long long inf = 1000000001;
struct edge {
	long long y, cap, flow, cost;
}e[M];
long long phi[N], Distance[N], pe[N], from[N];
int number_of_edges;
int n, s, f;
vector <int> list_of_edges[N];
long long beer_cost[N];
inline void add_edge (long long x, long long y, long long cap, long long cost) {
	edge e1 = {y, cap, 0, cost}, e2 = {x, 0, 0, - cost};
	list_of_edges[x].push_back(number_of_edges);
	e[number_of_edges++] = e1;
	list_of_edges[y].push_back(number_of_edges);
	e[number_of_edges++] = e2;
}

inline void dijkstra () {
	set <pair < long long, int > > st;
	for (int i = 1; i <= n; ++i)
		Distance[i] = inf;
	Distance[s] = 0;
	st.insert (make_pair(Distance[s], s));
	while (!st.empty()) {
		int x = st.begin()->second;
		st.erase(st.begin());
		for (int i = 0; i < (int)list_of_edges[x].size(); ++i) {
			int id = list_of_edges[x][i], to = e[id].y, cost = e[id].cost;
			if (e[id].flow < e[id].cap && 
			    Distance[to] > Distance[x] + phi[x] - phi[to] + cost) {
					st.erase (make_pair(Distance[to], to));
					Distance[to] = Distance[x] + phi[x] - phi[to] + cost;
					pe[to] = id;
					from[to] = x;
					st.insert (make_pair(Distance[to], to));
			}
		}
	}
	return;
}

inline long long MinCostMaxFlow () {
	long long total_cost = 0;
	while (true) {
		dijkstra ();
		long long max_cost = 0;
		for (int i = 2; i <= n; ++i) {
			if(max_cost < beer_cost[i] - Distance[i]) 
				max_cost = beer_cost[i] - Distance[i], f = i;
		}
		if (max_cost == 0) 
			break;
		long long flow = inf;
		for (int j = f; j != s; j = from[j]) 
			flow = min (flow, e[pe[j]].cap-e[pe[j]].flow);
		for (int j = f; j != s; j = from[j]) {
			e[pe[j]].flow += flow, e[pe[j] ^ 1].flow -= flow;
			total_cost -= (e[pe[j]].cost * flow);
		}
		total_cost += (beer_cost[f] * flow);
	}
return total_cost;
}

int main() {
	freopen("beer.in", "r", stdin);
	freopen("beer.out", "w", stdout);
	int m;
	scanf ("%d%d", &n, &m);
	s = 1;
	for (int i = 2; i <= n; ++i) {
		scanf ("%lld", &beer_cost[i]);
	}
	for (int i = 1; i <= m; ++i) {
		int x, y, cap, cost;
		scanf ("%d%d%d%d", &x, &y, &cap, &cost);
		add_edge (x, y, cap, cost);
		swap (x, y);
		add_edge (x, y, cap, cost);
	}
	long long ans = MinCostMaxFlow ();
	printf ("%lld", ans);
return 0;
}
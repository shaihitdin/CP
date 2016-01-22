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
};
edge e[2001 * 4];
long long phi[N], Distance[N], pe[N], from[N];
int number_of_edges;
vector <int> list_of_edges[N];
bool ban[2001 * 4];
inline void add_edge(int x, int y, int cap, int flow, int cost) {
	edge e1 = {y, cap, flow, cost}, e2 = {x, 0, 0, -cost};
	list_of_edges[x].push_back(number_of_edges);
	e[number_of_edges++] = e1;
	list_of_edges[y].push_back(number_of_edges);
	e[number_of_edges++] = e2;
}

inline bool dijkstra(int n, int s, int f) {
	set < pair < long long, int > > st;
	for(int i = 1; i <= n; ++i)
		Distance[i] = inf;
	Distance[s] = 0;
	st.insert(make_pair(Distance[s], s));
	while(!st.empty()) {
		int x = st.begin()->second;
		st.erase(st.begin());
		for(int i = 0; i < (int)list_of_edges[x].size(); ++i) {
			int id = list_of_edges[x][i], to = e[id].y, cost = e[id].cost;
			if(e[id].flow < e[id].cap && Distance[to] > Distance[x] + phi[x] - phi[to] + cost) {
				st.erase(make_pair(Distance[to], to));
				Distance[to] = Distance[x] + phi[x] - phi[to] + cost;
				pe[to] = id;
				from[to] = x;
				st.insert(make_pair(Distance[to], to));
			}
		}
	}
	for(int i = 1; i <= n; ++i)
		phi[i] = min(inf, phi[i] + Distance[i]);
	return Distance[f] != inf;
}

inline pair<long long,long long> MinCostMaxFlow(int n, int s, int f, int k) {
	long long total_flow = 0;
	long long total_cost = 0;
	while(total_flow < k && dijkstra(n, s, f)) {
		long long flow = 1;
		for(int j = f; j != s; j = from[j]) 
			flow = min(flow, e[pe[j]].cap-e[pe[j]].flow);
		for(int j = f; j != s; j = from[j]) {
			e[pe[j]].flow += flow, e[pe[j] ^ 1].flow -= flow;
			total_cost += (e[pe[j]].cost*flow);
		}
		total_flow += flow;
	}

	return make_pair(total_flow,total_cost);
}

int tmp[2001*4], sz1;

inline bool get_ans(int x) {
	if(x == f) {
		return 1;
	}
	for(int i = 0 ; i < (int)list_of_edges[x].size(); ++i) {
		int id = v[x][i], to = e[id].y;
		if(!ban[id] && e[id].flow == 1) {
			tmp[++sz1] = (id / 4) + 1;
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
	freopen("brides.in", "r", stdin);
	freopen("brides.out", "w", stdout);
	int n, s, f, k, m;
	scanf("%d %d %d\n", &n, &m, &k);
	s = 1, f = n;
	for(int i = 1; i <= m; ++i) {
		int cap = 1;
		scanf("%d %d %d\n", &x, &y, &cost);
		add_edge(x, y, cap, flow, cost);
		swap(x, y);
		add_edge(x, y, cap, flow, cost);
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
		for(int i = 1; i <= sz1; ++i) {
			printf("%d ", tmp[i]);
		}
		printf("\n");
	}
return 0;
}
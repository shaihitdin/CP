#include<iostream>
#include<stdio.h>
using namespace std;
const int N = 51*51;
const long long inf = 1000000001;
struct edge{
	int y,cap,flow,cost;
}e[N*51];
int phi[N];
set < pair < long long, int > > st;
void add_edge() {
	edge e1={y,cap,flow,cost}, e2={x,0,0,-cost} ;
}
bool dijkstra() {
	for(i = 1; i <= n; ++i)
		d[i] = inf;
	d[s] = 0;
	st.insert(make_pair(d[s], s));
	while(!st.empty()){
		x = st.begin()->second;
		st.erase(st.begin());
		for(i = 0; i <= v[x].size(); ++i) {
			int id = v[x][i], to = e[id].y, cost = e[id].cost;
			if(e[id].flow < e[id].cap && d[to] > d[v] + phi[v] - phi[to] + cost){
				st.erase(make_pair(d[to],to));
				d[to] = d[v] + phi[v] - phi[to] + cost;
				st.insert(make_pair(d[to],to));
			}
		}
	}
	for(i = 1; i <= n; ++i)
		phi[i] = min(inf,phi[i]+d[i]);
	return d[f]!=inf;
}
int main() {
	cin >> n >> m;
	s = n+m+1, f = n+m+2;
	for(i = 1; i <= m; ++i) {
		cin >> x;
		
	}
	for(i = 1; i <= n; ++i) {
		cin >> j;
		while(j--) {
			cin >> x;
		}
	}
return 0;}
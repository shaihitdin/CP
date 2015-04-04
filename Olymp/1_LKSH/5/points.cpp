#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 20001;
int n, m, x, y, i, res;
bool ans[N];
int tin[N], fup[N], timer;
vector<int> a[N];
void dfs(int v, int p=-1) {
	tin[v] = ++timer;
	fup[v] = timer;
	int child = 0;
	for(int i = 0; i < (int)a[v].size(); ++i) {
		int to = a[v][i];
	   if (to == p)
	    continue;
	   if (tin[to]) {	
	   	fup[v] = min(fup[v], tin[to]);
	   } else {
	     dfs(to, v);
	   	++child;
	     if (tin[v] <= fup[to])	ans[v] = 1;
	     fup[v] = min(fup[v], fup[to]);
	   }
	}
	if (child > 1 && p == -1)
	 ans[v] = 1;
	else if (p == -1)
	 ans[v] = 0;
}
int main() {
	freopen("points.in", "r", stdin);
	freopen("points.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(i = 1; i <= m; ++i) {
	 scanf("%d %d", &x, &y);
	 a[x].push_back(y);
	 a[y].push_back(x);
	}
	for(i = 1; i <= n; ++i) 
	 if (!tin[i]) dfs(i);
	for(i = 1; i <= n; ++i)
	 if (ans[i]) ++res;
	printf("%d\n", res);
	for(i = 1; i <= n; ++i)
	 if (ans[i]) printf("%d ", i);
return 0;}
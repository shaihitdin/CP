#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
#define mkp make_pair
#define S second
#define F first
const int N=20001;
int tin[N], fup[N], timer;
vector <pair<int, int> > a[N];
bool bridge[N*10];
bool u[N];
int n, m, i, x, y;

inline void dfs (int v, int pe=-1) {
    tin[v] = ++timer;
    fup[v] = timer;
    for (int i = 0; i < a[v].size(); ++i) {
    	if(a[v][i].S == pe)
    		continue;
    	int to = a[v][i].F;
    	if (tin[to]) {
    		fup[v] = min (tin[to], fup[v]);
    	} else {
    		dfs (to, a[v][i].S);
    		if (tin[v] < fup[to]) {
    			bridge[a[v][i].S] = 1;
    		}
    		fup[v] = min (fup[v], fup[to]);
    	}
    }
}

int clrsz;

int ans[N];

inline void color (int v, int c = 1) {
	u[v] = 1;
	ans[v] = c;
	for (int i = 0; i < a[v].size(); ++i) {
		if (!u[a[v][i].F]) {
			if (bridge[a[v][i].S])
				color (a[v][i].F, ++clrsz);
			else
				color (a[v][i].F, c);
		}	
	}
}

int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (i = 1; i <= m; ++i) {
		scanf ("%d%d", &x, &y);
		a[x].push_back (mkp (y, i));
		a[y].push_back (mkp (x, i));
	}
	for (i = 1; i <= n; ++i)
		if (!tin[i]) 
			dfs (i);
	for (i = 1; i <= n; ++i)
		if (!u[i])
			color (i, ++clrsz);
	printf ("%d\n", clrsz);
	for (i = 1; i <= n; ++i)
		printf ("%d ", ans[i]);
	return 0;
}
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
const int N = 201, M = 40001;
int p[N];
int mn[N], mx[N], mn_c[N], mx_c[N];
bool u[N];
int n, m, q[M], l[M], r[M], v[M];
vector <int> g[N];
bool pivot[N];
inline bool kuhn (int v) {
	if (pivot[v])
		return 0;
	u[v] = 1;
	for (auto x : g[v])
		if (!p[x] || (!u[p[x]] && kuhn(p[x]) ) ) {
			p[x] = v;
			return 1;
		}
	return 0;
}
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		mx[i] = n;
		mn[i] = 1;
	}
	for (int i = 1; i <= m; ++i) {
		scanf ("%d%d%d%d", &q[i], &l[i], &r[i], &v[i]);
		if (q[i] == 1)
			for (int j = l[i]; j <= r[i]; ++j) {
				mx[j] = min (mx[j], v[i]);
				++mx_c[i];
			}
		else
			for (int j = l[i]; j <= r[i]; ++j) {
				mn[j] = max (mn[j], v[i]);
				++mn_c[i];
			}
	}
	for (int i = 1; i <= n; ++i) {
		if (!p[i] && mx_c[i] == 1 && !pivot[mx[i]])
			p[i] = mx[i], pivot[mx[i]] = 1;	
		if (!p[i] && mn_c[i] == 1 && !pivot[mn[i]])
			p[i] = mn[i], pivot[mn[i]] = 1;		
	}
	for (int i = 1; i <= n; ++i)
		for (int j = mn[i]; j <= mx[i]; ++j)
			g[j].push_back(i);
	for (int i = 1; i <= n; ++i) {
		memset (u, 0, sizeof (u));
		kuhn(i);
    }
    for (int i = 1; i <= m; ++i) {
    	int temp;
    	if (q[i] == 1) {
    		temp = 0;
    		for (int j = l[i]; j <= r[i]; ++j)
    			temp = max (temp, p[j]);
    	}
    	else {
    		temp = n + 1;
    		for (int j = l[i]; j <= r[i]; ++j)
    			temp = min (temp, p[j]);
    	}
    	if (temp == v[i]) {
    		printf ("-1");
    		return 0;
    	}
    }
    for (int i = 1; i <= n; ++i)
    	printf ("%d ", p[i]);
	return 0;
}
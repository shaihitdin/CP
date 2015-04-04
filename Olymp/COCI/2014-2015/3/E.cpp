#include <iostream>
#include <assert.h>
#include <stdio.h>
using namespace std;
const int N = 300001;
int p[N][25], num[N], last[N], lvl[N], sum[N];
int n, x, y;
char c;
inline int lca (int a, int b) {
	if (lvl[a] < lvl[b])
		swap (a, b);
	for (int i = 20; i >= 0; --i)
		if (lvl[p[a][i]] >= lvl[b])
			a = p[a][i];
	//cerr << a << " " << b;
	for (int i = 20; i >= 0; --i) {
		if (p[a][i] != p[b][i])
			a = p[a][i], b = p[b][i];
	}
	a = p[a][0];
	assert (a == p[b][0]);
	return a;
}
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d\n", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%c %d", &c, &x);
		x = last[x];
		if (c == 'b') {
			printf ("%d\n", num[last[x]]);
			x = last[p[x][0]];
		}
		lvl[i] = lvl[x] + 1;
		p[i][0] = x;
		for (int j = 1; j <= 20; ++j)
			p[i][j] = p[p[i][j - 1]][j - 1];
		if (c == 'a') {
			last[i] = i;
			num[i] = i;
			sum[i] = sum[x] + 1;
		}
		else if (c == 'b') {
			last[i] = last[p[x][0]];
			sum[i] = sum[x];
		}
		else {
			last[i] = p[i][0];
			sum[i] = sum[x];
			scanf (" %d", &y);
			//cerr << lca (i, y) << "\n";
			printf ("%d\n", sum[lca (x, y)]);
		}
		scanf ("\n");
	}
	return 0;
}
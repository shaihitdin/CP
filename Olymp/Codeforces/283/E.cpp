#include <iostream>
#include <stdio.h>
using namespace std;
#define mkp make_pair
#define F first
#define S second
bool cmp1 (const pair <int,int> &l, const pair <int, int> &r) {
	if (x.F == y.F)
}
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d%d", &x[i].F, &x[i].S);
	}
	scanf ("%d", &m);
	for (int i = 1; i <= m; ++i) {
		scanf ("%d%d%d", &y[i].F, &y[i].S.F, y[i].S.S);	
	}
	sort (x + 1, x + n + 1, cmp1);
	sort (y + 1, y + m + 1, cmp2);

	return 0;
}
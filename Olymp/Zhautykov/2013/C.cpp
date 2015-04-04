#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int N = 300010, inf = 1e9;
bool u[N];
int a[N], b[N], n, m, s, c1[N], c2[N], le;
bool cmp1 (const int &lh, const int &rh) {
	return a[lh] > a[rh];
}
bool cmp2 (const int &lh, const int &rh) {
	return b[lh] > b[rh];
}
int main () {
	freopen ("school.in", "r", stdin);
	freopen ("school.out", "w", stdout);
	scanf ("%d%d%d", &n, &m, &s);
	for (int i = 1; i <= n; ++i)
		scanf ("%d%d", &a[i], &b[i]);
	a[n + 1] = -inf, b[n + 1] = -inf;
	++n;
	for (int i = 1; i <= n; ++i)
		c1[i] = i;
	for (int i = 1; i <= n; ++i)
		c2[i] = i;
    sort (c1 + 1, c1 + n + 1, cmp1);
    sort (c2 + 1, c2 + n + 1, cmp2);
    long long ans = 0;
    le = s;
    int l1 = 1, l2 = 1;
    for (; l1 <= m; ++l1) {
    	ans += a[c1[l1]];
    	u[c1[l1]] = 1;
    }
    for (;le != 0; ++l2) {
    	if (u[c2[l2]] && a[c1[l1]] - a[c2[l2]] + b[c2[l2]] >= 0) {
    		u[c2[l2]] = 0;
    		u[c1[l1]] = 1;
			ans -= a[c2[l2]];
			ans += a[c1[l1]];
    		while (u[c1[l1]]) {
    			++l1;
    		}
    	}
    	if (!u[c2[l2]]) {
    		ans += b[c2[l2]];
    		--le;
    		u[c2[l2]] = 1;
    	}
    }
    /*
    for (int i = 1; i <= n; ++i) {
    	if (u[i])
    		cerr << i << " ";
    } 
    */
    printf ("%I64d", ans);
    return 0;
}
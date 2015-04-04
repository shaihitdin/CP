#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int N = 1001;
int b[N * N], a[N][N], c[N][N], st[N], n, m, d[N], d2[N], d1[N], k, l, r, mid, enq;
int sz = 0;
int calc (const int &x) {
	int res = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
				c[i][j] = (a[i][j] >= x) ? 1 : 0;
	for (int i = 1; i <= m; ++i)
		d[i] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			if (c[i][j] == 0)
				d[j] = i;
		enq = 0;
		for (int j = 1; j <= m; ++j) {
			while (enq && d[st[enq]] <= d[j])	--enq;
			d1[j] = enq ? st[enq] : 0;
			st[++enq] = j;
		}
		enq = 0;		
		for (int j = m; j >= 1; --j) {
			while (enq && d[st[enq]] <= d[j])	--enq;
			d2[j] = enq ? st[enq] : m + 1;
			st[++enq] = j;
		}
		enq = 0;		
		for (int j = 1; j <= m; ++j) {
			res = max (res, (i - d[j]) * (d2[j] - d1[j] - 1));
		}
	}
	return res;			
}
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	scanf ("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			scanf ("%d", &a[i][j]);
			b[++sz] = a[i][j];
		}
	sort (b + 1, b + sz + 1);
	l = 1;
	r = sz + 1;
	while (r - l > 1) {
		mid = (r + l) >> 1;
		if (calc (b[mid]) >= k)
			l = mid;
		else
			r = mid;
	}
	printf ("%d %d", b[l], calc(b[l]));
	return 0;
}
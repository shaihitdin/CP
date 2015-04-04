#include <iostream>
#include <assert.h>
#include <stdio.h>
using namespace std;
const int inf = 1e9;
const int N = 100001, K = 101;
int d[N][K], st[N], l[N], r[N], a[N], t[N + (1 << 17)][K];
int n, k, stq;
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	scanf ("%d%d", &n, &k);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < K; ++j)
			d[i][j] = inf;
	for (int i = 0; i < N + (1 << 17); ++i)
		for (int j = 0; j < K; ++j)
			t[i][j] = inf;
	for (int i = 1;  i <= n; ++i)
		scanf ("%d", &a[i]);
	stq = 0;
	for (int i = 1; i <= n; ++i) {
		while (stq > 0 && a[st[stq]] <= a[i])	--stq;
		if (stq == 0)	l[i] = 1;
		else	l[i] = st[stq] + 1;
		st[++stq] = i;
	}
	stq = 0;
	for (int i = n; i >= 1; --i) {
		while (stq > 0 && a[st[stq]] <= a[i])	--stq;
		if (stq == 0)	r[i] = n;
		else	r[i] = st[stq] - 1;
		st[++stq] = i;	
	}
	d[0][0] = 0;
	for (int j = 1; j <= k; ++j) {
		for (int i = 1; i <= n; ++i) {
			for (int g = l[i] - 1; g < i; ++g) {
				for (int h = i; h <= r[i]; ++h) {
					d[h][j] = min (d[h][j], d[g][j - 1] + a[i]);
				}
			}
		}
	}
	assert (d[n][k] != inf);
	printf ("%d", d[n][k]);
	return 0;
}
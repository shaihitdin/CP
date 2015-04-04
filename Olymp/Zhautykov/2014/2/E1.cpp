#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2, K = 102, lvl = 17, inf = 1e9 + 7;

int d[2][N];
int logd[N];
int n, k, mn[N][lvl];
int a[N];
int st[N], enq, l[N], r[N];

inline int get (const int &j, const int &len) {
	return min (mn[j][logd[len]], mn[j + len - (1 << logd[len])][logd[len]]);
}

int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	scanf ("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);
	
	for (int i = 2; i < N; ++i)
		logd[i] = logd[i / 2] + 1;
	enq = 0;
	
	for (int i = n; i; --i) {
		while (enq && a[st[enq]] <= a[i])
			--enq;
		if (enq)
			r[i] = st[enq] - 1;
		else
			r[i] = n;
		st[++enq] = i;
	}
	
	enq = 0;
	
	for (int i = 1; i <= n; ++i) {
		while (enq && a[st[enq]] <= a[i])
			--enq;
		if (enq)
			l[i] = st[enq] + 1;
		else
			l[i] = 1;
		st[++enq] = i;
	}
	for (int i = 0; i <= n; ++i)
		d[0][i] = d[1][i] = inf;
	d[0][1] = 0;
	for (int step = 0; step < k; ++step) {
		for (int i = n; i; --i) {
			mn[i][0] = d[step & 1][i];
			for (int j = 1; i + (1 << j) - 1 <= n; ++j)
				mn[i][j] = min (mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
		}		
		for (int i = 0; i <= n + 1; ++i)
			d[(step + 1) & 1][i] = inf;
		for (int i = 1; i <= n; ++i)
			d[(step + 1) & 1][r[i] + 1] = min (d[(step + 1) & 1][r[i] + 1], get (l[i], i - l[i] + 1) + a[i]);
	}
	printf ("%d", d[k & 1][n + 1]);
	return 0;
}
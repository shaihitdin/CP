#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7, N = 1e5 + 100;

int p[N], s[N], c[N];

bool ok[N];

int n;
int a[N], b[N];

int st[N];

inline bool cmp (const int &cc, const int &ccc) {
	return p[cc] < p[ccc];
}

int main () {
	
	freopen ("trapped.in", "r", stdin);
	freopen ("trapped.out", "w", stdout);

	scanf ("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf ("%d%d", &s[i], &p[i]);

	for (int i = 1; i <= n; ++i)
		c[i] = i;
	
	sort (c + 1, c + n + 1, cmp);

	for (int i = 1; i < n; ++i) {
		a[i] = p[c[i + 1]] - p[c[i]];
		b[i] = s[c[i]];
	}
	
	int enq = 0;
	for (int i = 1; i < n; ++i) {
		st[++enq] = i;
		while (enq && b[st[enq]] < a[i]) {
			if (st[enq] != i)
				a[i] += a[st[enq]];
			--enq;
		}
		ok[i] |= (!enq);
	}
	
	for (int i = 1; i < n; ++i) {
		a[i] = p[c[i + 1]] - p[c[i]];
		b[i] = s[c[i + 1]];
	}
	
	enq = 0;
	for (int i = n - 1; i; --i) {
		st[++enq] = i;
		while (enq && b[st[enq]] < a[i]) {
			if (st[enq] != i)
				a[i] += a[st[enq]];
			--enq;
		}
		ok[i] |= (!enq);
	}
	
	int ansmax = -inf, ansmin = inf;

	for (int i = 1; i < n; ++i)
		if (!ok[i])
			ansmin = min (ansmin, p[c[i]]), ansmax = max (ansmax, p[c[i + 1]]);
	if (ansmin > ansmax)
		printf ("0");
	else
		printf ("%d", ansmax - ansmin);

	return 0;
}
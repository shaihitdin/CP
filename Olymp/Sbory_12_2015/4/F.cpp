#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 310, sz = 1 << 15;
const ll oo = 2e9 + 1;

ll d[20100][110];
int n, l, L, r, R;
int a[20100];
ll sum[20100];

int t[101][sz * 2 + 10];

inline void upd (int t[], int x, const int &delta) {
	t[x += sz] = delta;
	while (x >>= 1)
		t[x] = min (t[x + x], t[x + x + 1]);
}

inline int get (int t[], int l, int r) {
	int res = oo;
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l & 1)
			res = min (res, t[l++]);
		if (!(r & 1))
			res = min (res, t[r--]);
		if (l > r)
			break;
	}
	return res;
}

int main () {

	freopen ("stations.in", "r", stdin);
	freopen ("stations.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	scanf ("%d%d%d", &n, &l, &L);
	scanf ("%d%d", &r, &R);

	for (int i = 1; i <= L; ++i)
		scanf ("%d", &a[i]);
	
	for (int i = 0; i <= L; ++i)
		for (int j = 0; j <= n; ++j)
			d[i][j] = oo;
	
	for (int i = 1; i <= L; ++i)
		sum[i] = sum[i - 1] + a[i];
	
	d[0][0] = 0;
	
	for (int i = 0; i <= L; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (j > 0 && i - l >= 0 && i - l - r >= 0)
				d[i][j] = get (t[j - 1], max (0, i - l - R), i - l - r) + sum[i] - sum[i - l];
			d[i][j] = min (d[i][j], oo);
			upd (t[j], i, d[i][j]);
		}
	}

	ll ans = oo;

	for (int i = max (0, L - R); i <= L - r; ++i)
		ans = min (ans, d[i][n]);
	
	if (ans == oo)
		printf ("No solution.");
	else
		printf ("%d", int (ans));

	return 0;
}
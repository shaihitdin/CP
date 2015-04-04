#include <bits/stdc++.h>

using namespace std;

const int inf = (1 << 30);
typedef long long ll;

long long d[200004];
int c[1000004], a[200004];

int sz;

int get(int v, int l, int r, int x, int y) {
	if (y < l || r < x) return inf;
	if (l <= x && y <= r) {
		return c[v];
	}
	int mid = (x + y) >> 1;
	return min(get(v * 2, l, r, x, mid), get(v * 2 + 1, l, r, mid + 1, y));
}

int main() {
	freopen ("seq.in", "r", stdin);
	freopen ("seq.out", "w", stdout);

	int n, h;
	cin >> n >> h;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		d[i] = d[i-1] + (i - a[i]);
	}

	sz = 1;
	while (sz < n) sz *= 2;

	for (int i = 1; i <= n; ++i)
		c[i - 1 + sz] = i - a[i];
	for (int i = sz + n; i < sz * 2; ++i)	
		c[i] = inf;

	for (int i = sz - 1; i >= 1; --i)
		c[i] = min(c[i * 2], c[i * 2 + 1]);

	long long ans = (1ll << 60);
	for (int i = 1; i <= n; ++i) {
		if (i + h - 1 > n) continue;
		int x = get(1, i, i + h - 1, 1, sz);
		if (x - (i - 1) < 0) continue;
		long long ot = (ll)(i-1) * h;
		if ((d[i + h - 1] - d[i - 1]) - ot < ans) { 
			ans = (d[i + h - 1] - d[i - 1]) - ot; 
		}
	}
	
	if (ans == (1ll << 60)) printf ("-1");
	else cout << ans;

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 1;

int n, h[N], a[N];

inline ll calc (const int &x) {
    ll res = 0;
	for (int i = 1; i <= n; ++i)
		res = (res + abs (h[i] - x) * 1ll * (a[i]));
	return res;
}

int main () {
	freopen ("fly.in", "r", stdin);
	freopen ("fly.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf ("%d", &h[i]);
	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);
	int l = 0, r = 1e6 + 1;
	while (r - l > 4) {
		int mid1 = l + (r - l) / 3,
		mid2 = r - (r - l) / 3;
		if (calc (mid1) > calc (mid2))
			l = mid1;
		else
			r = mid2;
	}
	
	l -= 100;
	r += 100;
	int mx = -1000;
	for (; l <= r; ++l)
		if (calc (l) < calc (mx))
			mx = l;
	printf ("%d %I64d", mx, calc (mx));
	return 0;
}
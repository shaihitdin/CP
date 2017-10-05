#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 100, sz = (1 << 18);

int a[N], b[N], t[sz + sz + 100];

inline void upd (int x, int delta) {
	t[x += sz] = delta;
	while (x >>= 1)
		t[x] = max (t[x + x], t[x + x + 1]);
}

inline int get (int l, int r) {
	int res = 0;
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l & 1)	res = max (res, t[l++]);
		if (!(r & 1)) res = max (res, t[r--]);
		if (l > r)	break;
	}
	return res;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	int n, k, p;
	cin >> n >> k >> p;
	k = min (k, n);
	for (int i = n + 1; i <= n + n; ++i)
		cin >> a[i];

	for (int i = 1; i <= n; ++i)
		a[i] = a[n + i];
	
	for (int i = 1; i <= k; ++i)
		b[1] += a[i];

	for (int i = 2; i + k - 1 <= n + n; ++i)
		b[i] = b[i - 1] - a[i - 1] + a[i + k - 1];
	
	for (int i = 1; i <= n + n; ++i)
		upd (i, b[i]);
	
	int shift = 0;
	
	while (p--) {
		char q;
		cin >> q;		
		if (q == '!') {
			shift++;
			shift %= n;
		} else {
			cout << get (n + 1 - shift, n + n - k + 1 - shift) << "\n";
		}
	}	
	
	
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int sz = 1 << 18;

typedef long long ll;

#define int ll

int t[2][sz + sz + 100];  // 0 -> a, 1 -> b;
int a, b, n, k, q;

inline void upd (int x, int delta) {
	x += sz;
	t[0][x] += delta;
	t[1][x] += delta;
	t[0][x] = min (t[0][x], a);
	t[1][x] = min (t[1][x], b);
	while (x >>= 1) {
		t[0][x] = t[0][x + x] + t[0][x + x + 1];
		t[1][x] = t[1][x + x] + t[1][x + x + 1];
	}
}

inline int get (int l, int r, int type) {
	int res = 0;
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l & 1)
			res += t[type][l++];
		if (!(r & 1))
			res += t[type][r--];
		if (l > r)
			break;
	}
	return res;
}

main () {

	#ifdef UNBROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	
	cin >> n >> k >> a >> b >> q;

	for (int i = 1; i <= q; ++i) {
		int q_type;
		cin >> q_type;
		if (q_type == 1) {
			int x, y;
			cin >> x >> y;
			upd (x, y);
		} else {
			int x;
			cin >> x;
			cout << get (1, x - 1, 1) + get (x + k, sz - 1, 0) << "\n";
		}
	}

	return 0;
}
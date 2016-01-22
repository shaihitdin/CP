#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100, sz = 1 << 17, oo = 1e9 + 7;

int ans[N];
int t[sz + sz + 100];
int n, a[N];
map <int, int> cc;

inline void upd (int x, int delta) {
	t[x += sz] = delta;
	while (x >>= 1)
		t[x] = min (t[x + x], t[x + x + 1]);
}

inline int get (int l, int r) {
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

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		cc[a[i]] = 0;
	}

	reverse (a + 1, a + n + 1);
	
	int sds = 0;

	for (auto &it : cc) {
		it.second = ++sds;
	}
	
	for (int i = 1; i <= n; ++i)
		a[i] = cc[a[i]];
	
	for (int i = 1; i <= sds; ++i)
		upd (i, oo);
	
	for (int i = 1; i <= n; ++i) {
		int res = get (1, a[i] - 1);
		if (get (a[i], a[i]) > i)
			upd (a[i], i);
		if (res == oo) {
			ans[i] = -1;
			continue;
		}
		ans[i] = i - res - 1;
	}
		
	reverse (ans + 1, ans + n + 1);

	for (int i = 1; i <= n; ++i)
		cout << ans[i] << " ";
	
	return 0;
}
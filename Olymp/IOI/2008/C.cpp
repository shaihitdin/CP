#include <bits/stdc++.h>

using namespace std;

#define prev can

const int sz = 1 << 19;
int n, m, bm;
pair <int, int> a[sz];
int lst[sz], prev[sz];
int t[sz + sz];
int cnt[sz];
int ans;

inline void upd (int x, const int &delta) {
	x += sz;
	t[x] = delta;
	while (x >>= 1)
		t[x] = (t[x + x] * t[x + x + 1]) % bm;
}

inline int get (int l, int r) {
	int ans = 1;
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l & 1)
			ans = (ans * t[l++]) % bm;
		if (!(r & 1))
			ans = (ans * t[r--]) % bm;
		if (l > r)
			break;
	}
	return ans;
}

int cnt_k[sz];
bool u_k[sz];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	scanf ("%d%d%d", &n, &m, &bm);

	for (int i = 1; i <= n; ++i)
		scanf ("%d%d", &a[i].first, &a[i].second);
	
	sort (a + 1, a + n + 1);

	for (int i = 0; i < sz; ++i)
		upd (i, 1);
	
	for (int i = 1; i <= n; ++i) {
		prev[i] = lst[a[i].second];
		++cnt_k[a[i].second];
		cnt[i] = cnt[prev[i]] + 1;
		lst[a[i].second] = i;
	}
		
	for (int i = 1; i <= m; ++i)
		upd (i, cnt_k[i] + 1);

	int l_pos = n;
	
	for (int i = n; i >= 1; --i) {
		if (u_k[a[i].second])
			continue;
		//int pos = lower_bound (a + 1, a + n + 1, make_pair (a[i].first / 2 + 1, 0)) - a;
		for (; l_pos > 0 && a[l_pos].first > (a[i].first >> 1); --l_pos)
			if (!u_k[a[l_pos].second])
				upd (a[l_pos].second, cnt[l_pos]);
		int tmp = get (0, sz - 1);
		ans = (ans + tmp) % bm;
		upd (a[i].second, 1);
		u_k[a[i].second] = 1;
	}
	
	printf ("%d", ans);	
	
	return 0;
}
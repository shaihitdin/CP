#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 100, sz = 1 << 19;

int t[sz + sz + 100];
int n, p;
map <int, int> Map[N];
int cnt[N];
int degree[N];

inline void upd (int x, int delta) {
	t[x += sz] += delta;
	while (x >>= 1)
		t[x] = t[x + x] + t[x + x + 1];
}

inline int get (int l, int r) {
	int res = 0;
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l & 1)
			res += t[l++];
		if (!(r & 1))
			res += t[r--];
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
	cin.tie (0);
	
	cin >> n >> p;

	for (int i = 1; i <= n; ++i) {
		int x, y;
		cin >> x >> y;
		++Map[x][y], ++Map[y][x];
		++cnt[x], ++cnt[y];
	}

	for (int i = 1; i <= n; ++i)
		upd (cnt[i], 1);

	long long ans = 0;
	
	for (int i = 1; i <= n; ++i) {

		for (auto to : Map[i])
			upd (cnt[to.first], -1);
		
		upd (cnt[i], -1);

		int res = get (max (0, p - cnt[i]), n);
		
		for (auto to : Map[i])
			if (cnt[i] + cnt[to.first] - to.second >= p)
				++res;
		
		ans += res;
		
		
		upd (cnt[i], 1);

		for (auto to : Map[i])
			upd (cnt[to.first], 1);
	}
	
	cout << ans / 2;
	
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int ll
#define fe first
#define se second
#define mp make_pair

const int sz = 1 << 19;

int t[sz + sz + 100];
int c, n;
pair <int, int> a[sz + 10];
int dudu[sz + 10];

inline void upd (int x, int delta) {
	for (t[x += sz] += delta; x >>= 1;)
		t[x] = t[x + x] + t[x + x + 1];
}

inline int get (int l, int r) {
	int res = 0;
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l & 1)	res += t[l++];
		if (!(r & 1)) res += t[r--];
		if (l > r)	break;
	}
	return res;
}

inline int make_log (int v, int Tl, int Tr, int need) {
	if (Tl == Tr)
		return Tl;
	int mid = (Tl + Tr) / 2;
	if (t[v + v + 1] <= need)
		return make_log (v + v, Tl, mid, need - t[v + v + 1]);
	return make_log (v + v + 1, mid + 1, Tr, need);
}

inline bool ok () {
	for (int x = c; x > 0;) {
		int u = upper_bound (a + 1, a + n + c + 2, mp (x + 1, -1ll)) - a - 1;
		if (get (1, u) < x)
			return 0;
		int need = get (u + 1, sz - 1);
		int ps = (make_log (1, 0, sz - 1, need + x)) + 1;
		x -= get (ps, u);
	}
	return 1;
}


main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	cin >> c >> n;

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		a[i] = mp (x, 0);
	}
	
	for (int i = 0; i <= c; ++i)
		a[n + 1 + i] = mp (i, 1);
	
	sort (a + 1, a + n + c + 1);
	for (int i = 1; i <= n + c + 1; ++i) {
		if (a[i].se == 1) {
			dudu[a[i].fe] = i;
		} else {
			upd (i, a[i].fe);
		}
	} 
	
	for (int i = 0; i <= c; ++i) {
		upd (dudu[i], i);
		if (!ok ()) {
			cout << i << endl;
			return 0;
		}
		upd (dudu[i], -i);
	}
	
	cout << "Greed is good";
	
	return 0;
}
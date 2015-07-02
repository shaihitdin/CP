#include <bits/stdc++.h>

using namespace std;

vector <int> ans;

inline void upd (int x, const int &delta) {
	for (x += sz, t[x] = delta; x; x >>= 1)
		t[x] = max (t[x << 1], t[(x << 1) + 1]);
}

inline int get (int l, int r) {
	int res = 0;
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l & 1)
			res = max (t[l++], res);
		if (!(r & 1))
			res = max (t[r--], res);
		if (l > r)
			break;
	}
	return res;
}

inline void go_greedy () {
	int mx_pos = 0;
	for (int i = 1; i <= n; ++i) {
		if ()
	}
}

inline void out () {
	sort (ans.begin (), ans.end ());
	cout << ans.size () << "\n";
	for (auto it : ans)
		cout << it.first << " " << it.second.first << " " << it.second.second << "\n";
	exit (0);
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);

	cin >> n;

	ll sum, mx;
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum += a[i];
	}

	for (int i = 1; i <= n; ++i)
		upd (i, a[i]);
	
	int it1 = 1, it2 = 1;
	
	for (int it1 = 1; it1 <= n;) {
		if (!a[it1]) {
			++it1;
			continue;
		}
		for (it2 = max (it1 + 1, it2); it2 <= n; ++it2)
			if (a[it2])
				break;
		int ch = min (a[it1], a[it2]);
		if (sum / 2 <= get (1, n))
			go_greedy ();
		ans.push_back (make_pair (it1, make_pair (it2, ch)));
		sum -= 2 * ch;
		upd (it1, a[it1] - ch);
		upd (it2, a[it2] - ch);
		a[it1] -= ch;
		a[it2] -= ch;

	}
	
	return 0;
}
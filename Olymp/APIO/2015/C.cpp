#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100, inf = 1e9;

int k, n;
vector <pair <int, int> > d;

inline ll rec (const int &lvl, const ll &pos1, const ll &pos2) {
	if (lvl == k + 1) {
		ll res = 0;
		for (auto it : d)
			res += min (abs (it.first - pos1) + abs (it.second - pos1) + 1, abs (it.first - pos2) + abs (it.second - pos2) + 1);
		return res;
	}
	
	int l, r;

	if (lvl == 1)
		l = 0, r = 1e9 + 1;
	else
		l = 0, r = 1e9 + 1;
	while (r - l > 30) {
		int mid1 = (r + l) >> 1ll, mid2 = mid1 + 14;
		if (lvl == 1)
			if (rec (lvl + 1, mid1, pos2) > rec (lvl + 1, mid2, pos2))
				l = mid1;
			else
				r = mid2;
		else 
			if (rec (lvl + 1, pos1, mid1) > rec (lvl + 1, pos1, mid2))
				l = mid1;
			else
				r = mid2;
	}

	ll diff = 30 - (r - l);

	l -= diff / 2;
	r += diff / 2;
	
	ll best;
	if (lvl == 1)
		best = rec (lvl + 1, l, pos2);
	else
		best = rec (lvl + 1, pos1, l);
	for (; l <= r; ++l) {
		if (lvl == 1)
			best = min (best, rec (lvl + 1, l, pos2));
		else
			best = min (best, rec (lvl + 1, pos1, l));
	}
	return best;
}

int main () {
    /*
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	*/
	ios_base :: sync_with_stdio (0);

	cin >> k >> n;

	ll ans = 0;

	for (int i = 1; i <= n; ++i) {
		char q1, q2;
		int x, y;
		cin >> q1 >> x >> q2 >> y;
		//cerr << q1 << " " << q2 << "\n";
		if (q1 == q2)
			ans += abs (x - y);
		else
			d.push_back (make_pair (x, y));
	}

	//cerr << ans << " ";

	cout << ans + rec (1, -inf, -inf) << "\n";

	return 0;
}
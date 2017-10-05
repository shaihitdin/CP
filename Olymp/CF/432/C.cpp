#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1010;

int a[N];
vector <pair <int, int> > cc;

inline int rec (int l, int r) {
	int mx = 0;
	for (int i = l; i <= r; ++i)
		mx = max (mx, cc[i].second);
	if (mx == 0)
		return 0;
	bool u2[40];
	memset (u2, 0, sizeof (u2));
	set <int> u;
	for (int i = 1; i <= mx; ++i) {
		for (int j = l; j <= r; ++j) {
			if (cc[j].second >= i) {
				u2[j - l] = 1;
				cc[j].second -= i;
			}
		}
		u.insert (rec (l, r));
		for (int j = l; j <= r; ++j) {
			if (u2[j - l]) {
				cc[j].second += i;
				u2[j - l] = 0;
			}
		}
	}
	for (int c = 0;;++c) {
		if (!u.count (c))
			return c;
	}
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		for (int j = 2; j * j <= x; ++j) {
			if (x % j == 0) {
				int y = 0;
				while (x % j == 0) {
					++y;
					x /= j;
				}
				cc.emplace_back (make_pair (j, y));
			}
		}
		if (x > 1)
			cc.emplace_back (make_pair (x, 1));
	}
	
	sort (cc.begin (), cc.end ());
	cc.resize (unique (cc.begin (), cc.end ()) - cc.begin ());

	int ans = 0;
	for (int i = 0; i < cc.size ();) {
		int j = i;
		while (j < cc.size () && cc[i].first == cc[j].first)	++j;
		--j;
		ans ^= rec (i, j);
		i = j + 1;
	}
	
	if (!ans)
		cout << "Arpa";
	else
		cout << "Mojtaba";

	return 0;
}
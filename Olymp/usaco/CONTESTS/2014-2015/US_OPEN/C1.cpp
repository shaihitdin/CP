#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

typedef pair <int, int> pii;

int a[N], b[N], c[N], n;

inline bool cmp (const int &xx, const int &yy) {
	return a[xx] > a[yy];
}

set <pii> segment;
map <int, int> bale;

int main () {

	freopen ("trapped.in", "r", stdin);
	freopen ("trapped.out", "w", stdout);

	ios_base :: sync_with_stdio (0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i] >> b[i];

	for (int i = 1; i <= n; ++i)
		c[i] = i;
	

	sort (c + 1, c + n + 1, cmp);

	for (int i = 1; i <= n; ++i) {
		int hs = a[c[i]], hp = b[c[i]];
		auto it = bale.upper_bound (hp);
		if (it != bale.end ()) {
			if (abs (it -> first - hp) <= min (hs, it -> second))
				segment.insert (pii (min (it -> first, hp), max (it -> first, hp)));
		}
		if (it != bale.begin ()) {
			--it;
			if (abs (it -> first - hp) <= min (hs, it -> second))
				segment.insert (pii (min (it -> first, hp), max (it -> first, hp)));
		}
		
		bale[hp] = hs;
	}
	
	int right = 0, ans = 0;

	for (auto it : segment) {
		ans += max (0, it.second - max (right, it.first));
		right = max (right, it.second);
	}
	
	cout << ans;

	return 0;
}
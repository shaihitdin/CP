#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll l, n, r, s, t, ans;

inline bool can (const ll &turn, const ll &num, const ll &from, const ll &to) {
	return from <= turn * (l + l - 2) + num - 1 && turn * (l + l - 2) + num - 1 <= to;
}

inline bool func (const ll &turn) {
	return can (turn, r, s - 1, s + t - 1) || can (turn, l + (l - r), s - 1, s + t - 1);
}

int main () {
	freopen ("thereturn.in", "r", stdin);
	freopen ("thereturn.out", "w", stdout);
	ios_base :: sync_with_stdio (0);
	cin >> n >> l;
	if (l == 1) {
		cout << n;
		return 0;
	}
	for (ll i = 1; i <= n; ++i) {
		cin >> r >> s >> t;
		ll prev = s / (l + l - 2);
		if (func (prev - 1) || func (prev) || func (prev + 1)) {
			++ans;
			continue;
		}
	}
	cout << ans;
	return 0;
}
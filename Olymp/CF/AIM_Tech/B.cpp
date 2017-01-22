/**
	Oh, my dear
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 100;
const ll oo = 1e18;

ll a, b;
int n;
int v[N];

inline int gcd (int a, int b) {
	return b ? gcd (b, a % b) : a;
}

set <pair <int, ll> > pref_a[N], suff_a[N];

ll ans = oo;

int main () {
	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> a >> b;

	for (int i = 1; i <= n; ++i)
		cin >> v[i];
	
	pref_a[0].insert (make_pair (0, 0));

	for (int i = 1; i <= n; ++i) {
		for (auto it : pref_a[i - 1]) {
			if (gcd (v[i], it.first) > 1)
				pref_a[i].insert (make_pair (gcd (v[i], it.first), it.second));
			if (gcd (v[i] - 1, it.first) > 1)
				pref_a[i].insert (make_pair (gcd (v[i] - 1, it.first), it.second + b));
			if (gcd (v[i] + 1, it.first) > 1)
				pref_a[i].insert (make_pair (gcd (v[i] + 1, it.first), it.second + b));
		}
		for (auto it : pref_a[i]) {
			ans = min (ans, it.second + a * (n - i));
		}
	}
	suff_a[n + 1].insert (make_pair (0, 0));
	for (int i = n; i >= 1; --i) {
		for (auto it : suff_a[i + 1]) {
			if (gcd (v[i], it.first) > 1)
				suff_a[i].insert (make_pair (gcd (v[i], it.first), it.second));
			if (gcd (v[i] - 1, it.first) > 1)
				suff_a[i].insert (make_pair (gcd (v[i] - 1, it.first), it.second + b));
			if (gcd (v[i] + 1, it.first) > 1)
				suff_a[i].insert (make_pair (gcd (v[i] + 1, it.first), it.second + b));
		}
		for (auto it : suff_a[i]) {
			ans = min (ans, it.second + a * (i - 1));
		}
	}
	
	unordered_map <int, ll> cc;
	
	for (int i = 1; i <= n; ++i) {
		for (auto it : suff_a[i]) {
			if (cc.count (it.first)) {
				ans = min (ans, it.second + cc[it.first]);
			}
		}
		for (auto &it : cc) {
			it.second += a;
		}
		for (auto &it : pref_a[i]) {
			if (cc.count (it.first)) {
				cc[it.first] = min (cc[it.first], it.second);
			} else {
				cc[it.first] = it.second;
			}
		}
	}

	cout << ans;
	
	return 0;
}
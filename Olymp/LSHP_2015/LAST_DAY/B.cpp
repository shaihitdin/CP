#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


inline ld get_sum (const ll &n) {
	return ((ld) * n * (n + 1)) / 2;
}

map <ll, ll> Map;
vector <pair <ll, ll> > ans;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ll s;
	
	cin >> s;

	for (ll i = 1; s / i >= 100000; ++i) {
		ll f_p = s / i;
		ll l = f_p - i;
		ll r = f_p + i + 2;
		while (r - l > 1) {
			ll mid = (l + r) / 2;
			if (get_sum (mid + i - 1) - get_sum (mid - 1) <= s)
				l = mid;
			else
				r = mid;
		}
		if (get_sum (l + i - 1) - get_sum (l - 1) == s) {
			ans.push_back (make_pair (l, l + i - 1));
		}
		if (get_sum (r + i - 1) - get_sum (r - 1) == s) {
			ans.push_back (make_pair (r, r + i - 1));
		}
	}
	
	Map[0] = 0;

	for (ll i = 0; i <= 1500000; ++i) {
		Map[get_sum (i)] = i;
		if (Map.count (get_sum (i) - s)) {
			ans.push_back (make_pair (Map[get_sum (i) - s] + 1, i));
		}
	}

	sort (ans.begin (), ans.end ());
	
	int cnt = 0;

	for (int i = 0; i < ans.size () - 1; ++i)
		if (ans[i].first != ans[i + 1].first)
			++cnt;

	++cnt;
	
	cout << cnt << "\n";

	for (int i = 0; i < ans.size () - 1; ++i)
		if (ans[i].first != ans[i + 1].first)
			cout << ans[i].first << " " << ans[i].second << "\n";
	
	cout << ans.back ().first << " " << ans.back ().second << "\n";
	
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	int t;

	cin >> t;

	for (int _ = 1; _ <= t; ++_) {
		cout << "Case #" << _ << ": ";
		ll n, k;
		cin >> n >> k;
		map <ll, ll> dp;
		dp[n] = 1;
		while (1) {
			auto it = dp.end ();
			--it;
			ll x = (*it).first;
			ll cnt = (*it).second;
			k -= cnt;
			ll mid = (x + 1) / 2;
			ll left_side = mid - 1;
			ll right_side = x - mid;
			if (k <= 0) {
				cout << max (left_side, right_side) << " " << min (left_side, right_side) << "\n";
				break;
			}
			dp[left_side] += cnt;
			dp[right_side] += cnt;
			dp.erase (it);
		}
	}

	return 0;
}
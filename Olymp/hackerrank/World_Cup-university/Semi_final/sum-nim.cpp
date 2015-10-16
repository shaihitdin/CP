#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline bool bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;
}

map <int, int> dp[40];
int n, a[40];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	if (n <= 4) {
		int ans = 0;
		vector <int> b;
		for (int mask = 0; mask < (1 << (n - 1)); ++mask) {
			b.clear ();
			b.emplace_back (a[0]);
			for (int i = 1; i < n; ++i) {
				if (bit (mask, i - 1))
					b[b.size () - 1] += a[i];
				else
					b.emplace_back (a[i]);
			}
			int x_val = 0;
			for (auto it : b) {
				x_val ^= it;
			}
			if (x_val == 0) {
				++ans;
			}
		}
		cout << ans;
	} else {
		int half = n / 2;
		vector <int> b;
		ll ans = 0;
		for (int begin = half; begin < n; ++begin) {
			int len = n - 1 - (begin + 1) + 1;
			for (int mask = 0; mask < (1 << len); ++mask) {
				b.clear ();
				b.emplace_back (a[begin]);
				for (int i = begin + 1; i < n; ++i) {
					if (bit (mask, i - begin - 1)) {
						b[b.size () - 1] += a[i];
					} else {
						b.emplace_back (a[i]);
					}
				}
				int x_val = 0;
				for (auto it : b) {
					x_val ^= it;
				}
				++dp[begin][x_val];
			}
		}
		for (int mask = 0; mask < (1 << (half - 1)); ++mask) {
			b.clear ();
			b.emplace_back (a[0]);
			for (int i = 1; i < half; ++i) {
				if (bit (mask, i - 1))
					b[b.size () - 1] += a[i];
				else
					b.emplace_back (a[i]);
			}
			for (int begin = half; begin < n; ++begin) {
				int x_val = 0;
				for (auto it : b)
					x_val ^= it;
				ans += dp[begin][x_val];
				b[b.size () - 1] += a[begin];
			}
			/*
			int x_val = 0;
			for (auto it : b)
				x_val ^= it;
			if (x_val == 0)
				++ans;
			*/
		}
		cout << ans;
	}


	return 0;
}
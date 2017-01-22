/**
	Oh, my dear
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 110, bmo = 1e9;

vector <pair <int, int> > s;

inline bool bit (int mask, int pos) {
	return (mask >> pos) & 1;
}

int main () {
	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int n;
	
	cin >> n;
	
	if (n == 1) {
		cout << 0;
		return 0;
	}
	
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			if (__gcd (i, j) == 1)
				s.emplace_back (make_pair (i, j));
	int ans = 0;
	ll nn = (1ll << s.size ());

	for (ll mask = 1; mask < nn; ++mask) {
		bool flag2 = 1;
		for (int i = 2; i <= n; ++i) {
			bool flag = 0;
			for (int j = 0; j < (int)s.size (); ++j) {
				auto it = s[j];
				if (bit (mask, j) && it.first < i && it.second >= i) {
					flag = 1;
					break;
				}
			}
			if (!flag) {
				flag2 = 0;
				break;
			}
		}
		ans += flag2;
		if (ans >= bmo)
			ans -= bmo;
	}
	cout << ans;
	return 0;
}
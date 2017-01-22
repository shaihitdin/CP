/**
	I'm on someone's monitor!
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 100;

int n, k;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int n;

	cin >> n >> k;

	if (k * 2 > n)
		k = n - k;
	ll ans = 1, now = 1;
	int mod = 0;

	for (int i = 1; i <= n; ++i) {
		mod += k;
		
		if (mod > n) {
			ans += ++now;
			cout << ans << " ";
			now++;
		} else {
			ans += now;
			cout << ans << " ";
		}

		mod %= n;
	}
	
	return 0;
}
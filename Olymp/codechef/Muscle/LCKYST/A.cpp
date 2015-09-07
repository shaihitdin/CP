#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

ll n, x, y;

int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif


	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> y;
		ll x = y;
		int cnt = 0;
		while (x % 5 == 0) {
			++cnt;
			x /= 5;
		}
		while (x % 2 == 0) {
			--cnt;
			x /= 2;
		}
		while (cnt > 0) {
			y *= 4;
			cnt -= 2;
		}
		cout << y << "\n";
	}
	
	
	return 0;
}
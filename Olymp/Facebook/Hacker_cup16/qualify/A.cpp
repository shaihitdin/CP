#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2050;

inline int dist (int a, int b) {
	return a * a + b * b;
}

map <int, int> Map;
int x[N], y[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	
	int t;

	cin >> t;

	for (int test_num = 1; test_num <= t; ++test_num) {
		int n;
		cin >> n;
		ll ans = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> x[i] >> y[i];
		}
		for (int i = 1; i <= n; ++i) {
			Map.clear ();
			for (int j = 1; j <= n; ++j)
				++Map[dist (x[i] - x[j], y[i] - y[j])];
			for (auto it : Map)
				ans += (it.second * (it.second - 1)) / 2;
		}
		cout << "Case #" << test_num << ": " << ans << "\n";
	}

	return 0;
}
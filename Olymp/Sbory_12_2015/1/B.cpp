#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

int Map[N];

inline bool check (const int &pos1, const int &y, const int &di) {
	return pos1 - y > Map[di];
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int t;

	cin >> t;

	for (int test = 1; test <= t; ++test) {
		int x, y;
		cin >> x >> y;
		int ans = 0;
		for (int i = 1; i * i <= x; ++i) {
			if (x % i == 0) {
				ans += check (test, y, i);
				Map[i] = test;
				ans += check (test, y, x / i);
				Map[x / i] = test;
			}
		}
		cout << ans << "\n";
	}
	
	
	return 0;
}
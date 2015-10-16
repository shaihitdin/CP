#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int bpr = 1e9 + 7;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	
	int n;
	
	cin >> n;

	ll now = 1;

	for (int i = 1; i <= n; ++i) {
		now = (now * 27) % bpr;
	}
	
	ll now2 = 1;
	
	for (int i = 1; i <= n; ++i) {
		now2 = (now2 * 7) % bpr;
	}
	
	now -= now2;

	now += bpr;

	now %= bpr;

	cout << now;
	
	return 0;
}
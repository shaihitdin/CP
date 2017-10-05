#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int a, b;
	cin >> a >> b;
	a = min (a, b);

	ll ans = 1;
	for (int i = 1; i <= a; ++i) {
		ans = ans * 1ll * i;
	}

	cout << ans;
	return 0;
}
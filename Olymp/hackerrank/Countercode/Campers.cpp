#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 100;

bool u[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= k; ++i) {
		int x;
		cin >> x;
		u[x] = 1;
	}

	u[n + 2] = 1;
	int lst = -1, ans = 0;

	for (int i = 1; i <= n + 2; ++i) {
		if (u[i]) {
			ans += max (0, ((i - 2) - (lst + 2) + 1 + 1) / 2);
			lst = i;
		}
	}
	
	cout << ans + k;
	
	return 0;
}
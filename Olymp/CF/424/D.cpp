#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2050;

int a[N], b[N];
bool u[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n, k, p;

	cin >> n >> k >> p;
	
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= k; ++i)
		cin >> b[i];
	
	for (int i = 1; i <= n; ++i) {
		a[i] -= p;
	} 
	for (int i = 1; i <= k; ++i) {
		b[i] -= p;
	}	
	
	sort (a + 1, a + n + 1);
	sort (b + 1, b + k + 1);

	ll l = -1, r = 1e18;

	while (r - l > 1) {
		ll mid = ((ll)r + l) / 2;
		for (int i = 1; i <= k; ++i)
			u[i] = 0;
		for (int i = 1; i <= n; ++i) {
			bool flag = 1;
			for (int j = 1; j <= k; ++j) {
				if (!u[j] && abs (a[i] - b[j]) + abs (b[j]) <= mid) {
					u[j] = 1;
					flag = 0;
					break;
				}
			}
			if (flag) {
				l = mid;
				break;
			}
		}
		if (l != mid)
			r = mid;
	}

	cout << r;	
	return 0;
}
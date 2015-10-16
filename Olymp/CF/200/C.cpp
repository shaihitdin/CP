#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

typedef long long ll;

int n, m;
ll a[N], b[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif


	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= m; ++i)
		cin >> b[i];

	
	ll l = -1, r = 1e18;

	while (r - l > 1) {
		ll mid = (r + l) / 2;
		int j = 1;
		for (int i = 1; i <= n && j <= m; ++i) {
			int pos = lower_bound (b + 1, b + m + 1, a[i]) - b;
			pos = max (pos, j);
			if (b[j] < a[i] && a[i] - b[j] > mid) {
				l = mid;
				break;
			}
			if (pos == j) {
				while (pos <= m && abs (b[pos] - a[i]) <= mid)
					++pos;
			} else {
				while (pos <= m && min (abs (b[pos] - a[i]) + abs (b[pos] - b[j]), abs (a[i] - b[j]) + abs (b[pos] - b[j])) <= mid)
					++pos;
			}
			j = pos;
		}
		if (j > m && l != mid)
			r = mid;
		else
			l = mid;
	}
	
	cout << r;
	
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100;

int a[N];

map <int, int> cnt;
int no_r[N], sum[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif


	ios_base :: sync_with_stdio (0);

	int n;
	
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= n; ++i) {
		cnt.clear ();
		for (int j = 0; a[i]; ++j, a[i] >>= 1) {
			cnt[a[i]] = j;
			++no_r[a[i]];
			sum[a[i]] += j;
			for (int k = 1; (a[i] << k) < N; ++k) {
				int n_a = a[i] << k;
				if (cnt.count (n_a))
					break;
				cnt[n_a] = j + k;
				++no_r[n_a];
				sum[n_a] += j + k;
			}
		}
	}
	
	int ans = 1e9;
	
	for (int i = 1; i < N; ++i)
		if (no_r[i] == n)
			ans = min (ans, sum[i]);

	cout << ans;

	return 0;
}
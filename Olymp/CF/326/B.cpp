#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 100;

typedef long long ll;

const int bpr = 1e9 + 7;

int a[N], c[N], total_cnt[N], cnt[N];
int ans;

int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n;
	ll l;
	int k;
	
	cin >> n >> l >> k;

	--l;
	
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i < n; ++i)
		c[i] = a[i];

	sort (c, c + n);

	for (int i = 0; i < n; ++i)
		a[i] = lower_bound (c, c + n, a[i]) - c + 1;

	for (int i = 0; i < n; ++i)
		++total_cnt[a[i]];

	for (int i = 0; i <= l % n; ++i)
		++cnt[a[i]];
	
	for (int i = N - 2; i >= 0; --i)
		cnt[i] += cnt[i + 1];
	
	vector <vector <int> > d, sum;
	
	d.resize (k + 10);

	for (int i = 0; i < k + 10; ++i)
		d[i].resize (n + 10);
	
	sum = d;
	
	d[0][0] = 1;
	
	ll l_cnt = l / n;
	
	
	for (int i = 1; i <= k + 1 && i <= l_cnt + 1; ++i) {
		for (int j = 0; j <= n; ++j)
			sum[i - 1][j] = d[i - 1][j];

		for (int j = 1; j <= n; ++j)
			sum[i - 1][j] = (sum[i - 1][j] + sum[i - 1][j - 1]) % bpr;

		for (int j = 0; j <= n; ++j) {
			d[i][j] = (sum[i - 1][j] * 1ll * total_cnt[j]) % bpr;
			//cerr << d[i][j] << " ";
			if (i <= k && l_cnt - i + 1 > 0)
				ans = (ans + d[i][j] * 1ll * ((l_cnt - i + 1) % bpr)) % bpr;
			if (i + 1 <= k && i + 1 <= l_cnt + 1)
				ans = (ans + d[i][j] * 1ll * cnt[j]) % bpr;
			///cerr << d[i][j] << " ";
		}	
		//cerr << "\n";
	}
	
	ans = (ans + (l % n) + 1) % bpr;
	
	
	cout << ans;
	
	return 0;
}
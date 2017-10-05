#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2200;

int a[N], b[N], sum[N], c[N];
int n, k;


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> k >> n;

	for (int i = 1; i <= k; ++i)
		cin >> a[i];
	
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	sort (b + 1, b + n + 1);

	
	for (int i = 1; i <= k; ++i)
		sum[i] = sum[i - 1] + a[i];

	sort (sum + 1, sum + k + 1);
	k = unique (sum + 1, sum + k + 1) - sum - 1;


	for (int i = n; i; --i) {
		b[i] = b[i] - b[1];
	}
	
	int ans = 0;
	for (int i = 1; i <= k; ++i) {
		for (int j = 1; j <= k; ++j)
			c[j] = sum[j] - sum[i];

		sort (c + 1, c + k + 1);

		int flag = 0;

		for (int j = 1; j <= n; ++j)
			flag += (binary_search (c + 1, c + k + 1, b[j]));
		ans += (flag == n);
	}	
	
	cout << ans;	
	return 0;
}
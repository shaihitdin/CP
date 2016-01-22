#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 100, bpr = 1e9 + 7, oo = 1e9;

pair <int, int> a[N];
int n;
int del[N], sum[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	
	sort (a + 1, a + n + 1);
	
	for (int i = 1; i <= n; ++i) {
		int x = a[i].first - a[i].second;
		int pos = upper_bound (a + 1, a + n + 1, make_pair (x, -1)) - a;
		--pos;
		sum[i] = max (i - pos - 1, 0) + sum[pos];
	}
	
	int ans = oo;

	for (int i = 1; i <= n; ++i) {
		ans = min (ans, sum[i] + (n - i));
	}
	
	ans = min (ans, sum[n]);
	ans = min (ans, n);
	
	cout << ans;
	
	return 0;
}
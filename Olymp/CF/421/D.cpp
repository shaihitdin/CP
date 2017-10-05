#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10;

typedef long long ll;

ll p[N], sum_a[N], sum_add_a[N], sum_dec_a[N];
ll n;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> p[i];

	ll now = 0;
	ll sum_add = 0, sum_dec = 0;

	for (int i = 1; i <= n; ++i) {
		now += abs (p[i] - i);
		sum_a[i] += abs (n - p[i]) - abs (p[i] - 1);
		if (p[i] <= i) {
			sum_dec_a[1]++;
			sum_dec_a[abs (p[i] - i) + 1]--;
			sum_add_a[abs (p[i] - i) + 1]++;
			sum_add_a[i]--;
			sum_dec_a[i + 1]++;
			sum_dec_a[i + abs (n - p[i]) + 1]--;
			sum_add_a[i + abs (n - p[i]) + 1]++;
		} else {
			sum_add_a[1]++;
			sum_add_a[i]--;
			sum_dec_a[i + 1]++;
			sum_dec_a[i + abs (n - p[i]) + 1]--;
			sum_add_a[i + abs (n - p[i]) + 1]++;
		}
	}
	
	
	ll ans = 1e18, ansk = -1;

	for (int k = 0; k < n; ++k) {
		sum_add += sum_add_a[k];
		sum_dec += sum_dec_a[k];
		now += sum_a[k];
		now += sum_add;
		now -= sum_dec;
		if (ans > now)
			ans = now, ansk = k;
	}
	
	cout << ans << " " << (n - ansk) % n;
	
	return 0;
}
/**
	Oh, my dear
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3000;

int cnt[N], n;

int main () {
	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		++cnt[x];
	}	
	int ans = 0;
	
	for (int sum = 1; sum <= 2000; ++sum) {
		int res = 0;
		for (int i = 1; i <= sum; ++i) {
			res += min (cnt[i], cnt[sum - i]);
		}
		res /= 2;
		ans = max (ans, res);
	}
	
	cout << ans;
	
	return 0;
}
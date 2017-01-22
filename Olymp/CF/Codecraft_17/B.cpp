/**
	Mom, I'm on someone's monitor!
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

int cnt[N], n;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		++cnt[x];
	}
	int ans = 1;	
	for (int i = 2; i < N; ++i) {
		int res = 0;
		for (int j = i; j < N; j += i) {
			res += cnt[j];
		}
		ans = max (ans, res);
	}
	
	cout << ans;
	return 0;
}
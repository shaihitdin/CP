#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

int a[N];
int n;

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio (0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	sort (a + 1, a + n + 1);

	ll now = 0;
	int ans = 0;

	for (int i = 1; i <= n; ++i) {
		if (now > a[i]) {
			continue;
		}
		now += a[i];
		++ans;
	}

	cout << ans;
	
	return 0;
}
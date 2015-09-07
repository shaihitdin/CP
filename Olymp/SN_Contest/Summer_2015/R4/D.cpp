#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

int r, n;
pair <int, int> a[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> r;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first >> a[i].second;
	}

	++n;
	a[n].first = r;
	a[n].second = r;
	
	sort (a + 1, a + n + 1);
	
	int mxr = 0, ans = 0;
	
	
	for (int i = 1; i <= n; ++i) {
		ans = max (ans, a[i].first - mxr);
		mxr = max (mxr, a[i].second);
	}
	
	cout << ans;

	return 0;
}
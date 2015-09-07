#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5;

pair <int, int> a[N];

set <int> Set;
set <pair <int, int> > Set2;
map <pair <int, int>, int> Map;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= k; ++i) {
		int x, y;
		cin >> x >> y;
		p[i].first = x;
		p[i].second = y;
		a[i].second = x - y;
		a[i].first = x - (x - y);
	}
	
	sort (a + 1, a + k + 1);
	
	ll ans = 0;
	
	for (int i = 1; i <= k; ++i) {
		int x = a[i].second, y = 0;
		x += a[i].first;
		y += a[i].first;
		if (Set1.find (x, y) != Set1.end ()) {
			int diff = n - x + 1;
			ans += (diff * 1ll * (diff + 1)) / 2;
			ans += 2;
			Set.insert (a[i].second);
		}
		auto it = Set.upper_bound (a[i].second);
		if (Set.begin () == it)
			ans += 3;
	}
	
	cout << ans;
	
	return 0;
}
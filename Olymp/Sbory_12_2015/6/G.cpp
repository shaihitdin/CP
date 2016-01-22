#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

int col[N];
pair <int, int> a[N];
int n, h;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> h;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	
	sort (a + 1, a + n + 1);

	if (n == 2) {
		cout << 0 << "\n";
		cout << 1 << " " << 1;
		return 0;
	}
		
	int ans1 = 0, ans2 = 0;

	ans1 = a[n - 1].first + a[n].first - (a[1].first + a[2].first);
	ans2 = max (a[n].first + a[n - 1].first, a[n].first + a[1].first + h) - min (a[1].first + a[2].first + h, a[2].first + a[3].first);

	if (ans1 < ans2) {
		cout << ans1 << "\n";
		for (int i = 1; i <= n; ++i)
			cout << 1 << " ";
	} else {
		cout << ans2 << "\n";
		col[a[1].second] = 1;
		for (int i = 1; i <= n; ++i)
			cout << col[i] + 1 << " ";
	}
	
	return 0;
}
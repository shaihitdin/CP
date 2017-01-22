#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

ll a[N];

int main () {
	#ifdef Geodsso
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int t;

	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		int ans = 0;
		for (int i = 1, j = n; i < j;) {
			if (a[i] == a[j]) {
				++i, --j;
				continue;
			}
			if (a[i] > a[j]) {
				--j;
				a[j] += a[j + 1];
				++ans;
				continue;
			} else {
				++i;
				a[i] += a[i - 1];
				++ans;
				continue;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}
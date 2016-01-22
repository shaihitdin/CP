#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100, oo = 1e9;

ll x[N], y[N], z[N], pref[N][8], suff[N][8], ans;
int n;


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> x[i] >> y[i] >> z[i];
	
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			ans = max (ans, abs (x[i] - x[j]) + abs (y[i] - y[j]) + abs (z[i] - z[j]));
		}
	}	


	cout << ans << "\n\n\n";
	
	return 0;
}
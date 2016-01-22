#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

ll a[N], x[N], s;
int n;

int main () {

	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	cin >> s;
	
	for (ll i = 60; i >= 0; --i) {
		if ((s & (1ll << i)) == 0)
			continue;
		ll mn = 2e18;
		for (int j = 1; j <= n; ++j) {
			if ((x[j] | (1ll << i)) <= a[j] && mn > a[j]) {
				mn = a[j];
			}
		}
		if (mn == 2e18) {
			cout << "NO\n";
			return 0;
		}
		for (int j = 1; j <= n; ++j) {
			if ((x[j] | (1ll << i)) <= a[j] && mn == a[j]) {
				x[j] |= (1ll << i);
				break;
			}
		}		
	}
	
	cout << "YES\n";

	for (int i = 1; i <= n; ++i)
		cout << x[i] << " ";
	
	return 0;
}
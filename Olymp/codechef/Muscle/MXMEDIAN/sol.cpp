#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

int a[N], b[N], c[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int t;	
	cin >> t;

	while (t--) {
		int n;
		cin >> n;		
		for (int i = 1; i <= n + n; ++i) {
			cin >> a[i];
		}
		sort (a + 1, a + n + n + 1);
		for (int i = 1, j = 1; j <= n + n; ++i, j += 2)
			b[j] = a[i];
		for (int i = n + n, j = 2; j <= n + n; --i, j += 2)
			b[j] = a[i];
		for (int i = 1; i <= n; ++i)
			c[i] = max (b[i * 2 - 1], b[i * 2]);
		sort (c + 1, c + n + 1);
		cout << c[(n + 1) / 2] << "\n";
		for (int i = 1; i <= n + n; ++i)
			cout << b[i] << " ";
		cout << "\n";
	}	
	return 0;
}
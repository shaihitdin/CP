#include <bits/stdc++.h>

using namespace std;

const int N = 4000;

int a[N], s[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int t;

	cin >> t;
	
	for (int test = 1; test <= t; ++test) {
		cout << "Case #" << test << ": ";
		int n, k;
		cin >> n >> k;
		int nn = n - k + 1;
		memset (a, 0, sizeof (a));
		memset (s, 0, sizeof (s));
		for (int i = 1; i <= nn; ++i)
			cin >> s[i];
		for (int i = 1; i <= k; ++i)
			a[i] = s[1] / k;
		for (int i = 1; i <= s[1] % k; ++i)
			++a[i];
		for (int i = 1; i <= n; ++i)
			cerr << a[i] << " ";
		cerr << "\n";
		for (int i = 2; i <= nn; ++i) {
			a[i + k - 1] = s[i] - (s[i - 1] - a[i - 1]);
		}
		
		for (int i = 1; i <= n; ++i)
			cerr << a[i] << " ";
		
		cerr << "\n";
		
		int mx = a[1], mn = a[1];
		for (int i = 1; i <= n; ++i)
			mx = max (mx, a[i]), mn = min (mn, a[i]);
		cout << mx - mn << "\n";
	}

	return 0;
}
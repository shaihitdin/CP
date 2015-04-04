#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 1;

int n;
int w[N], h[N], pref_h[N], suff_h[N];
int sum;

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio (0);
	
	cin >> n;
	
	for (int i = 1; i <= n; ++i)
		cin >> w[i] >> h[i];

	pref_h[1] = h[1];
	suff_h[n] = h[n];
	
	for (int i = 2; i <= n; ++i)
		pref_h[i] = max (h[i], pref_h[i - 1]);
	for (int i = n - 1; i; --i)
		suff_h[i] = max (h[i], suff_h[i + 1]);
	
	for (int i = 1; i <= n; ++i)
		sum += w[i];
	
	for (int i = 1; i <= n; ++i) {
		long long ans = sum - w[i];
		if (i == 1)
			cout << ans * suff_h[i + 1];
		else if (i == n)
			cout << ans * pref_h[i - 1];
		else
			cout << ans * max (pref_h[i - 1], suff_h[i + 1]);
		cout << " ";
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 4e6 + 100, bpr = 1e9 + 7;

typedef long long ll;

ll f[N];

inline ll bin_pow (const int &x, const int &y) {
	if (!y)
		return 1;
	if (y & 1)
		return (bin_pow (x, y - 1) * x) % bpr;
	ll z = bin_pow (x, y / 2);
	return (z * z) % bpr;
}

inline ll cnk (const int &n, const int &k) {
	return (((f[n] * bin_pow (f[k], bpr - 2)) % bpr) * bin_pow (f[n - k], bpr - 2)) % bpr;
}

int main () {
    #ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	f[0] = 1;

	for (int i = 1; i < N; ++i)
		f[i] = (f[i - 1] * i) % bpr;

	ios_base :: sync_with_stdio (0);

	int t;

	cin >> t;

	
	while (t--) {
		int n, k;
		cin >> n >> k;
		cout << (n * cnk (k + n, n - 1)) % bpr << "\n";
	}
	
	return 0;
}
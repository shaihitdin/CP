#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100;

int n, k;

inline int grundy (const int &n) {
	if (n == 0)
		return 0;
	if (n & 1)
		return 0;
	bool u[3];
	memset (u, 0, sizeof (u));
	u[grundy (n - 1)] = 1;
	u[(k & 1) ? grundy (n / 2) : 0] = 1;
	for (int i = 0;; ++i) {
		if (!u[i])
			return i;
	}
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> k;
	
	int ans = 0;

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		cerr << grundy (x) << " ";
		ans ^= grundy (x);
	}
	
	if (ans)
		cout << "Kevin";
	else
		cout << "Nicky";

	return 0;
}
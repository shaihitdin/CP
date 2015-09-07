#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100;

int d[N];

inline int get (const int &l, const int &r) {
	return d[min (r, N - 1)] - d[l - 1];
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n, k;

	cin >> n >> k;

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		++d[x];
	}

	for (int i = 1; i < N; ++i)
		d[i] += d[i - 1];
	
	int ans = 1;

	for (int i = 2; i < N; ++i) {
		int res = 0;
		for (int j = i; j < N; j += i)
			res += get (j, j + min (i - 1, k));
		if (res == n)
			ans = i;
	}
	
	cout << ans;

	return 0;
}
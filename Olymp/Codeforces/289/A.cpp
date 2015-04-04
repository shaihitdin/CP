#include <bits/stdc++.h>

using namespace std;
const int N = 11;

long long n, ans, a[N][N];

inline long long get (const long long &i, const long long &j) {
	if (a[i][j])
		return a[i][j];
	if (i == 1 || j == 1)
		return a[i][j] = 1;
	return a[i][j] = get (i - 1, j) + get (i, j - 1);
}

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	cin >> n;
	for (long long i = 1; i <= n; ++i)
		for (long long j = 1; j <= n; ++j)
			ans = max (ans, get (i, j));
	cout << ans;
	return 0;
}
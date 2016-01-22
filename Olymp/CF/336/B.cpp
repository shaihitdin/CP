#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 510, bpr = 1e9 + 7, oo = 1e7;

int a[N], n;
int d[N][N];

inline int rec (int l, int r) {
	if (d[l][r] != oo)
		return d[l][r];
	if (l >= r)
		return 1;
	for (int i = l; i < r; ++i)
		d[l][r] = min (d[l][r], rec (l, i) + rec (i + 1, r));
	if (a[l] == a[r])
		d[l][r] = min (d[l][r], rec (l + 1, r - 1));
	return d[l][r];
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			d[i][j] = oo;
	
	cout << rec (1, n);
	
	return 0;
}
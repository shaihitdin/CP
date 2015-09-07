#include <bits/stdc++.h>

using namespace std;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> m;

	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> b[i][j];

	cin >> n;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> a[i][j];
	
	
	return 0;
}
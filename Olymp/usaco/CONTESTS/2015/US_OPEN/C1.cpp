#include <bits/stdc++.h>

using namespace std;

inline bool cmp (const int &xx, const int &yy) {
	return b[xx] >
}

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	ios_base :: sync_with_stdio (0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i] >> b[i];

	for (int i = 1; i <= n; ++i)
		c[i] = i;
	

	sort (c + 1, c + n + 1, cmp);

	return 0;
}
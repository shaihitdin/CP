#include <bits/stdc++.h>

using namespace std;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int t, n;

	scanf ("%d", &t);

	while (t--) {
		scanf ("%d", &n);
		puts ((n % 4 == 1) ? ("YES") : ("NO"));
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;
	
int cnt[2];

int main () {
    #ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int t;
	scanf ("%d", &t);
	while (t--) {
		cnt[0] = cnt[1] = 0;
		int n, xo = 0;
		scanf ("%d", &n);
		for (int i = 1; i <= n; ++i) {
			int x;
			scanf ("%d", &x);
			++cnt[x];
			xo ^= x;
		}
		printf ("%d\n", cnt[xo]);
	}
	return 0;
}
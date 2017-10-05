#include <bits/stdc++.h>

using namespace std;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif
	int c, v0, v1, a, l;
	cin >> c >> v0 >> v1 >> a >> l;
	for (int ans = 1, read = 0, now = v0; ans; ++ans) {
		if (ans > 1) {
			now += a;
		}
		now = min (now, v1);
		read += now;
		if (ans > 1) {
			read -= l;
		}
		if (read >= c) {
			cout << ans;
			return 0;
		}
	}


	return 0;
}
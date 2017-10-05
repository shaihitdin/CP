#include <bits/stdc++.h>

using namespace std;

pair <int, int> cnt[3];
char ans[1010];
int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int t;
	cin >> t;

	for (int test = 1; test <= t; ++test) {
		cout << "Case #" << test << ": ";
		int n, r, o, y, g, b, v;
		cin >> n >> r >> o >> y >> g >> b >> v;
		assert (o == 0);
		assert (g == 0);
		assert (v == 0);
		cnt[0] = make_pair (r, 'R');
		cnt[1] = make_pair (y, 'Y');
		cnt[2] = make_pair (b, 'B');
		sort (cnt, cnt + 3);
		for (int i = 0; i < n; ++i)
			ans[i] = 'W';

		bool ok = 0;
		
		for (int i = 0; cnt[2].first != 0 && i < n; i += 2) {
			--cnt[2].first;
			ans[i] = cnt[2].second;
		}
		
		for (int i = 1; i < n; ++i) {
			if (ans[i] != 'W')
				continue;
			sort (cnt, cnt + 3);
			for (int j = 2; j >= 0; --j) {
				if (ans[i - 1] == cnt[j].second || cnt[j].first == 0)
					continue;
				ans[i] = cnt[j].second;
				cnt[j].first--;
				break;
			}
			if (ans[i] == 'W')
				ok = 1;
		}
		if (ok == 1 || ans[n - 1] == ans[0]) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		for (int i = 0; i < n; ++i)
			cout << ans[i];
		cout << "\n";
	}


	return 0;
}
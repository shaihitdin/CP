#include <bits/stdc++.h>

using namespace std;

vector <int> best_ans;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	int n, m;
	string s, t;
	cin >> n >> m;

	cin >> s >> t;
	int ans = 1e9;
	for (int i = 0; i + s.size () - 1 < t.size (); ++i) {
		int cnt = 0;
		vector <int> tmp_ans;
		for (int j = 0; j < s.size (); ++j) {
			if (s[j] != t[i + j]) {
				++cnt;
				tmp_ans.emplace_back (j + 1);
			}
		}
		ans = min (ans, cnt);
		if (ans == cnt)
			best_ans = tmp_ans;
	}
	cout << ans << "\n";
	for (auto it : best_ans)
		cout << it << " ";
	return 0;
}
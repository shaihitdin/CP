#include <bits/stdc++.h>

using namespace std;

set <int> step[2];
vector <int> ans, ans2;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	string s;

	cin >> s;

	for (int i = 0; i < s.size (); ++i)
		step[s[i] == 'L'].insert (i);
	
	int res = -1, res2 = -1;
	int now = -1, lst = -1;	
	
	if (step[0].size () == step[1].size ()) {
		now = 0;
		while (step[0].size () + step[1].size ()) {
			lst = -1;
			for (; step[now].upper_bound (lst) != step[now].end (); now ^= 1) {
				int it = *step[now].upper_bound (lst);
				ans.emplace_back (it);
				step[now].erase (it);
				lst = it;
			}
			++res;
		}
		now = 1;

		for (int i = 0; i < s.size (); ++i)
			step[s[i] == 'L'].insert (i);

		while (step[0].size () + step[1].size ()) {
			lst = -1;
			for (; step[now].upper_bound (lst) != step[now].end (); now ^= 1) {
				int it = *step[now].upper_bound (lst);
				ans2.emplace_back (it);
				step[now].erase (it);
				lst = it;
			}
			++res2;
		}
		if (res2 < res) {
			res = res2;
			ans = ans2;
		}
	} else {
	
		if (step[0].size () > step[1].size ())
			now = 0;
		else
			now = 1;
	
		while (step[0].size () + step[1].size ()) {
			lst = -1;
			for (; step[now].upper_bound (lst) != step[now].end (); now ^= 1) {
				int it = *step[now].upper_bound (lst);
				ans.emplace_back (it);
				step[now].erase (it);
				lst = it;
			}
			++res;
		}

	}
	cout << res << "\n";
	
	for (auto it : ans)
		cout << it + 1 << " ";
	
	return 0;
}
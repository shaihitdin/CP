#include <bits/stdc++.h>

using namespace std;

multiset <int> s[3];
int n;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n;

	int ans = 0;

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		ans += x;
		s[x % 3].insert (x);
	}
	
	int t_ans = -1;
	int cc = ans % 3;
	
	if (cc == 0) {
		t_ans = ans;
	} else if (cc == 1) {
		if (s[1].size ()) {
			t_ans = max (t_ans, ans - *s[1].begin ());
		}
		if (s[2].size () > 1) {
			auto it = s[2].begin ();
			int temp = *it;
			++it;
			temp += *it;
			t_ans = max (t_ans, ans - temp);
		}
	} else {
		if (s[2].size ()) {
			t_ans = max (t_ans, ans - *s[2].begin ());
		} 
		if (s[1].size () > 1) {
			auto it = s[1].begin ();
			int temp = *it;
			++it;
			temp += *it;
			t_ans = max (t_ans, ans - temp);
		}
	}
	
	cout << t_ans;
	
	return 0;
}
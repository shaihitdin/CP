#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	string s, t;
	cin >> s >> t;
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < s.size (); ++i) {
		int ok = 0;
		for (int j = 0; j < t.size (); ++j) {
			if (s[i] == t[j])
				ok = max (ok, 1);
			if (s[i] == t[j] && i == j)
				ok = max (ok, 2);
		}	
		if (ok == 1) {
			++ans2;
		}
		if (ok == 2) {
			++ans1;
		}
	}
	
	cout << ans1 << " " << ans2;
	
	return 0;
}
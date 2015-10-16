#include <bits/stdc++.h>

using namespace std;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	string s, t;

	cin >> s >> t;

	int cnt[2];
	cnt[0] = cnt[1] = 0;
	
	for (auto it : s)
		++cnt[it - '0'];
	for (auto it : t)
		--cnt[it - '0'];
	
	if (cnt[0] != 0 || cnt[1] != 0) {
		cout << -1;
		return 0;
	}

	int ans = 0;
	for (int i = 0; i < s.size (); ++i)
		if (s[i] != t[i])
			++ans;
	cout << ans / 2;
	
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif
	int n;
	cin >> n;
	string ans;
	while (n--) {
		string s;
		cin >> s;
		char res = 127;
		for (auto it : s)
			res = min (res, it);
		ans += res;
	}
	sort (ans.begin (), ans.end ());
	cout << ans;
	return 0;
}
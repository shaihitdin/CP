#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100;
int ans = 0;
inline string rec (string s) {
	for (int i = 0; i + 1 < s.size (); ++i) {
		if (s[i] == 'a' && s[i + 1] == 'b') {
			++ans;
			return rec (s.substr (0, i) + "bba" + s.substr (i + 2));
		}
	}
	return s;
} 

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	string s;
	cin >> s;

	s = rec (s);
	int cnt[256];
	memset (cnt, 0, sizeof (cnt));
	for (int i = 0; i < s.size (); ++i) {
		++cnt[s[i]];
	}
	cout << ans << " " << cnt['b'] << " " << cnt['a'] << "\n";
	
	return 0;
}
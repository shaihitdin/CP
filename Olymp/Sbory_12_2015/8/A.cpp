#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 1000;

int nxt[N][27];
string s, t;


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	cin >> s >> t;

	int n = s.size (), m = t.size ();
	
	s = "#" + s;
	t = "#" + t;

	
	for (int i = 0; i < 26; ++i)
		nxt[n + 1][i] = n + 1;

	for (int i = n; i >= 1; --i) {
		for (int j = 0; j < 26; ++j)
			nxt[i][j] = nxt[i + 1][j];
		nxt[i][s[i] - 'a'] = i;
	}
	
	int now = 1, ans = 1;
	
	for (int i = 1; i <= m; ++i) {
		if (nxt[1][t[i] - 'a'] == n + 1) {
			cout << -1;
			return 0;
		}
	}
	
	for (int i = 1; i <= m; ++i) {
		int get = nxt[now][t[i] - 'a'];
		if (get == n + 1) {
			++ans;
			now = 1;
			get = nxt[now][t[i] - 'a'];
		}
		now = get + 1;
	}
	
	cout << ans;
	
	return 0;
}
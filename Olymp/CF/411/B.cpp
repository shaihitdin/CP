#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100, bpr = 1e9 + 7;
int pw[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	string s;
	cin >> s;

	int n = s.size ();

	int cnt = 0;
	int ans = 0;
	for (int i = pw[0] = 1; i < N; ++i) {
		pw[i] = (pw[i - 1] + pw[i - 1]) % bpr;
	}
	
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'a') {
			++cnt;
			continue;
		}
		ans = (ans + (pw[cnt] + bpr - 1) % bpr) % bpr;
		
	}
	
	cout << ans;
	
	return 0;
}
#include <bits/stdc++.h>

using namespace std;


int n, m;

char a[100][100];

int cnt[256];

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];

	int ans = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			memset (cnt, 0, sizeof (cnt));
			++cnt[a[i - 1][j - 1]];
			++cnt[a[i - 1][j]];
			++cnt[a[i][j - 1]];
			++cnt[a[i][j]];
			if (cnt['f'] == 1 && cnt['a'] == 1 && cnt['c'] == 1 && cnt['e'] == 1) {
				++ans;
			}
		}
	}
	
	cout << ans;
	return 0;
}
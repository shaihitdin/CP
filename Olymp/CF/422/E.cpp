#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

int dp[N][32][2];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int n, m;
	string s, t;
	int x;
	
	cin >> n;
	cin >> s;
	cin >> m;
	cin >> t;
	cin >> x;

	t.resize (m + 1);
	
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 31; ++j) {
			dp[i][j][1] = -1;
		}
	}
	
	dp[0][0][0] = 0;

	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= x; ++j) {
			/// Break
			dp[i][j][0] = max (dp[i][j][0], dp[i][j][1]);
			/// Continue as substr
			if (dp[i][j][1] != -1 && s[i] == t[dp[i][j][1]]) {
				dp[i + 1][j][1] = max (dp[i + 1][j][1], dp[i][j][1] + 1);
			}
			/// Start new substr
			if (s[i] == t[dp[i][j][0]]) {
				dp[i + 1][j + 1][1] = max (dp[i + 1][j + 1][1], dp[i][j][0] + 1);
			}
			/// Skip
			dp[i + 1][j][0] = max (dp[i + 1][j][0], dp[i][j][0]);
		}
	}
	
	for (int j = 0; j <= x; ++j) {
		dp[n][j][0] = max (dp[n][j][0], dp[n][j][1]);
		if (dp[n][j][0] == m) {
			cout << "YES";
			return 0;
		}
	}
	
	cout << "NO";
	
	return 0;
}
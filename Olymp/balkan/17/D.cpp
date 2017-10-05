#include <bits/stdc++.h>

using namespace std;


int dp[5050][10100];
int a[5050];

inline bool bad (int x, int y) {
	int a = x * 3 + y;
	return (a == 1 || a == 3);
	
}

int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	int t;

	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		int cnt[3];

		memset (cnt, 0, sizeof (cnt));
		
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			++cnt[a[i]];
		}
		if (cnt[2] == 0 && !(cnt[1] == n || cnt[0] == n)) {
			cout << -1 << "\n";
			continue;
		}
		if (cnt[1] == n - cnt[2] || cnt[0] == n - cnt[2]) {
			cout << 0 << "\n";
			continue;
		}
		int amount = 1;
		int blocked = 0;
		int ss = -1;
		vector <pair <int, int> > block;
		for (int i = 1; i <= n; ++i) {
			int j = i;
			int len = 0;
			while (j <= n && a[j] == 2)
				++j;
			i = j;
			
			int now = a[j];
			while (j <= n && (a[j] == a[i] || a[j] == 2)) {
				len += (a[j++] == a[i]);
			}
			if (j > n) {
				block.emplace_back (make_pair (len, 1));
				ss = len;
				break;
			}
			//cerr << i << " ";
			block.emplace_back (make_pair (len, a[j - 1] == 2));
			blocked += (a[j - 1] == 2);
			i = j - 1;
		}
		/*
		for (auto it : block) {
			cerr << it.first << " " << it.second << "\n";
		}
		*/
		
		int Free = cnt[2] - blocked;
		for (int i = 1; i <= block.size () + 1; ++i) {
			for (int j = 0; j < 10000; ++j)
				dp[i][j] = 1e9;
	    }
		dp[1][5000 + Free] = 0;
		for (int i = 1; i < block.size (); ++i) {
			for (int j = -4999; j <= 4999; ++j) {
				auto it = block[i - 1];
				if (it.second == 1) {
					dp[i + 1][5000 + j] = min (dp[i + 1][5000 + j], dp[i][5000 + j]);
					dp[i + 2][5000 + j + 1] = min (dp[i + 2][5000 + j + 1], dp[i][5000 + j] + it.first);
				}
				else {
					dp[i + 1][5000 + j - 1] = min (dp[i + 1][5000 + j - 1], dp[i][5000 + j] + 1);
					dp[i + 2][5000 + j] = min (dp[i + 2][5000 + j], dp[i][5000 + j] + it.first);
				}
			}
		}
		int ans = 1e9;
		for (int i = 0; i < 5000; ++i)
			ans = min (ans, min (dp[block.size ()][5000 + i], dp[block.size () + 1][5000 + i]));
		cout << ans << "\n";
	}

	return 0;
}
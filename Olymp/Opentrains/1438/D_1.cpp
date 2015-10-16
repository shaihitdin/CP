#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll limit = 1e16;

const int N = 300;

ll d[N][N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ll k;
	int n;

	string s;

	cin >> n >> k;
	
	cin >> s;
	
	//for (int len = n;; ++len) {
		//memset (d, 0, sizeof (d));
	d[0][0] = 1;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j < 100; ++j) {
			d[i][j + 1] = min (limit, d[i][j + 1] + d[i][j] * i);
			d[i + 1][j + 1] = min (limit, d[i + 1][j + 1] + d[i][j]);
		}
	}
	for (int len = n; len <= 100; ++len) {
		if (d[n][len] >= k) {
			int now_n = n, now_len = len;
			string ans;
			while (now_n && now_len) {
				vector <char> tmp;
				for (int i = 0; i < now_n; ++i) {
					tmp.emplace_back (s[i]);
				}
				sort (tmp.begin (), tmp.end ());
				bool flag = 0;
				int i = 0;
				if (d[now_n - 1][now_len - 1] >= k) {
					ans += s[now_n - 1];
					--now_len;
					--now_n;
					flag = 1;
					continue;
				}
				k -= d[now_n - 1][now_len - 1];

				for (; i < tmp.size () && tmp[i] != s[now_n - 1]; ++i) {
					if (d[now_n][now_len - 1] >= k) {
						ans += tmp[i];
						--now_len;
						flag = 1;
						break;
					} else {
						k -= d[now_n][now_len - 1];
					}
				}
				if (flag)
					continue;
				for (; i < tmp.size (); ++i) {
					if (d[now_n][now_len - 1] >= k) {
						ans += tmp[i];
						--now_len;
						flag = 1;
						break;
					} else {
						k -= d[now_n][now_len - 1];
					}
				}
				assert (flag);
			}
			reverse (ans.begin (), ans.end ());
			cout << ans;
			return 0;
		} else {
			k -= d[n][len];
		}
	}
}
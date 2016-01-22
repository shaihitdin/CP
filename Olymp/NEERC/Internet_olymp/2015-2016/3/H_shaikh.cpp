#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

vector <int> g[26];
string s;
int cnt[N][26];

int main () {

	freopen ("minimal.in", "r", stdin);
	freopen ("minimal.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> s;

	int n = s.size ();
	
	s = '#' + s;

	for (int i = 1; i <= n; ++i) {
		++cnt[i][s[i] - 'a'];
		for (int j = 0; j < 26; ++j)
			cnt[i][j] += cnt[i - 1][j];
	}
	
	for (int i = 1; i <= n; ++i)
		g[s[i] - 'a'].emplace_back (i);
	
	int q;
	
	cin >> q;

	while (q--) {
		int l, r;
		cin >> l >> r;
		int now = l;
		int ans = 0;
		for (int i = 0; i < 26; ++i) {
			int find_mn, find_mx;
			if (cnt[r][i] - cnt[l - 1][i] == 0)
				continue;
			find_mn = lower_bound (g[i].begin (), g[i].end (), l) - g[i].begin ();
			find_mn = g[i][find_mn];
			find_mx = upper_bound (g[i].begin (), g[i].end (), r) - g[i].begin () - 1;
			find_mx = g[i][find_mx];
			//ans += cnt[find_mx][i] - cnt[find_mn - 1][i];
			if (now <= find_mn) {
				ans += find_mx - now;
				now = find_mx;
			} else if (now <= find_mx) {
				int pos = lower_bound (g[i].begin (), g[i].end (), now) - g[i].begin () - 1;
				pos = g[i][pos];
				ans += r - now + 1 + pos - l;
				now = pos;
			} else {
				ans += r - now + 1 + find_mx - l;
				now = find_mx;
			}
		}
		cout << ans << "\n";
	}
	
	
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100;

#define begin can1
#define end can2

int s[N], m[N], mn[N], mx[N];
vector <int> begin[N], end[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int t;
	
	cin >> t;

	for (int test = 1; test <= t; ++test) {
		cout << "Case #" << test <<": ";
		int n, d, as, cs, rs, am, cm, rm;
		cin >> n >> d;
		cin >> s[0] >> as >> cs >> rs;
		cin >> m[0] >> am >> cm >> rm;
		
		for (int i = 1; i < n; ++i) {
			s[i] = (s[i - 1] * as + cs) % rs;
			m[i] = (m[i - 1] * am + cm) % rm;
		}
		
		for (int i = 1; i < n; ++i)
			m[i] %= i;
		m[0] = 0;

		for (int i = 0; i < n; ++i)
			mn[i] = s[i], mx[i] = s[i];
		
		for (int i = 0; i < N; ++i)
			begin[i].resize (0), end[i].resize (0);
		
		for (int i = 0; i < n; ++i) {
			mn[i] = min (mn[i], mn[m[i]]);
			mx[i] = max (mx[i], mx[m[i]]);
			begin[mn[i]].push_back (i);
			end[mx[i]].push_back (i);
		}
		
		int ans = 0, now = 0;
		
		for (int i = 0; i < d; ++i)
			for (auto it : end[i])
				++now;

		for (int i = d; i < N; ++i) {
			for (auto it : end[i])
				if (mx[it] - mn[it] <= d)
					++now;
			if (i - d <= s[0] && s[0] <= i)
				ans = max (ans, now);
			for (auto it : begin[i - d])
				if (mx[it] - mn[it] <= d)
					--now;
		}
		cout << ans << "\n";

	}

	return 0;
}
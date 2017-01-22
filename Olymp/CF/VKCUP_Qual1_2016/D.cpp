#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100;

vector <int> g[N];
int n, m, s, d;
int a[N], p[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> m >> s >> d;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	sort (a + 1, a + n + 1);
	a[0] = -1;

	set <int> Set;  
	
	g[0].emplace_back (-1);
	
	Set.insert (-1);

	for (int i = 1; i <= n; ++i)
		p[i] = -2;
	
	for (int i = 0; i <= n; ++i) {
		if (Set.size ()) {
			p[i] = *Set.begin ();
			if (i != n && a[i + 1] - 1 - (a[i] + 1) >= s) {
				int pos = upper_bound (a, a + n + 1, a[i + 1] - 1 + d - 1) - a - 1;
				g[pos].emplace_back (i);
				Set.insert (i);
			}
		}
		for (auto it : g[i])
			Set.erase (it);
	}
	
	if (p[n] == -2) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	
	vector <int> ans;
	
	if (a[n] != m - 1)
		ans.emplace_back (m - (a[n] + 1));
	ans.emplace_back (- (a[n] + 1 - (a[p[n] + 1] - 1)));
	
	int x = p[n];

	while (x != -1) {
		ans.emplace_back (a[x + 1] - 1 - (a[x] + 1));
		if (x != 0)
			ans.emplace_back (- (a[x] + 1 - (a[p[x] + 1] - 1)));
		x = p[x];
	}
	
	reverse (ans.begin (), ans.end ());
	
	for (auto it : ans) {
		assert (it != 0);
		if (it < 0) {
			cout << "JUMP " << -it << "\n";
		} else {
			cout << "RUN " << it << "\n";
		}
	}
	
	return 0;
}
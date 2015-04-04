#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

int a[N], b[N], ans[N], i, j;
int n, m;

map <int, int> Map;

int main () {
	freopen ("ant.in", "r", stdin);
	freopen ("ant.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= m; ++i)
		cin >> b[i];
	i = n, j = m;
	memset (ans, 255, sizeof (ans));
	set <int> Set;
	for (int i = 1; i <= m; ++i) {
		Set.insert (b[i]);
		Map[b[i]] = i;
	}
	for (int i = n; i; --i) {
		auto it = Set.lower_bound (a[i]);
		if (it == Set.end())
			continue;
		else
			ans[i] = Map[*it];
		Set.erase (it);
	}

	for (int i = 1; i <= n; ++i)
		cout << ans[i] << "\n";
		
	return 0;
}
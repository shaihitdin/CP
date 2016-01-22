#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

set <int> g[N];
int luckynum;
vector <pair <int, int> > ans;
int a[N], b[N];
int n;

inline void do_swap (int i, int j) {
	if (a[i] == a[j])
		return;
	ans.push_back (make_pair (i, j));
	g[a[j]].erase (j);
	g[a[i]].erase (i);
	swap (a[i], a[j]);
	g[a[j]].insert (j);
	g[a[i]].insert (i);
}

inline bool isLucky (int x) {
	while (x) {
		int z = x % 10;
		if (z != 4 && z != 7)
			return 0;
		x /= 10;
	}
	return 1;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);

	cin >> n;

	int dss = 0;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		dss |= isLucky (a[i]);
	}

	if (!dss) {
		if (is_sorted (a + 1, a + n + 1)) {
			cout << 0;
		} else {
			cout << -1;
		}
		return 0;
	}

	for (int i = 1; i <= n; ++i) {
		if (isLucky (a[i]))
			luckynum = a[i];
	}

	map <int, int> cc;
	int ccs = 0;

	for (int i = 1; i <= n; ++i) {
		cc[a[i]] = 0;
	}

	for (auto &it : cc)
		it.second = ++ccs;

	for (int i = 1; i <= n; ++i)
		a[i] = cc[a[i]];

	luckynum = cc[luckynum];

	for (int i = 1; i <= n; ++i)
		b[i] = a[i];

	sort (b + 1, b + n + 1);

	for (int i = 1; i <= n; ++i)
		g[a[i]].insert (i);

	for (int i = 1; i <= n; ++i) {
		int x = b[i];
		if (x == luckynum)
			continue;
		do_swap (*g[luckynum].begin (), i);
		do_swap (i, *g[x].begin ());
		g[x].erase (i);
	}
	
	assert (is_sorted (a + 1, a + n + 1));
	
	cout << ans.size () << "\n";

	for (auto it : ans)
		cout << it.first << " " << it.second << "\n";

	return 0;
}

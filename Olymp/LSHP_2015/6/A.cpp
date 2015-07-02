#include <bits/stdc++.h>

using namespace std;

const int N = 20001, M = 500001;

int x[M], y[M];

bitset <N> a[N];

double ans;
int n, m;
int cnt[N];

vector <int> g[N];

int un[6000][6000];

int to_cnt[N], sz_to;

int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	
	cin >> n >> m;

	for (int i = 1; i <= m; ++i) {
		cin >> x[i] >> y[i];
		g[x[i]].push_back (y[i]);
		g[y[i]].push_back (x[i]);
		a[x[i]][y[i]] = 1;
		a[y[i]][x[i]] = 1;
	}

	int block = 1000;
	
	for (int i = 1; i <= n; ++i)
		if (g[i].size () >= block)
			to_cnt[i] = ++sz_to;
	
	for (int i = 1; i <= sz_to; ++i)
		for (int j = 1; j <= sz_to; ++j)
			un[i][j] = (a[i] & a[j]).count ();
	
	for (int i = 1; i <= m; ++i) {
		if (g[x[i]].size () < block || g[y[i]].size () < block) {
			if (g[x[i]].size () > g[y[i]].size ())
				swap (x[i], y[i]);
			for (auto to : g[x[i]])
				if (a[y[i]][to])
					ans += 1;
			continue;
		} else {
			ans += un[to_cnt[x[i]]][to_cnt[y[i]]];
		}
	}

	ans /= 3;

	ans *= 2;

	ans /= 8;
	
	cout << fixed;
	cout.precision (8);

	cout << ans;
	
	return 0;
}
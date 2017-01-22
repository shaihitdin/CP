#include <bits/stdc++.h>

using namespace std;

const int sz = 1 << 17, oo = 1e9, N = 2e5 + 100;

#define eb emplace_back

int t[sz + sz + 100];
int add[N];
int n, m, a[N];
vector <int> g[N];

inline int calc (int l, int r) {		
	int mx = 0, cnt = 0;
	for (int j = l + 1; j < r;) {
		++cnt;
		for (int i = 0; i + 1 < g[a[j]].size (); ++i)
			mx = max (mx, calc (g[a[j]][i], g[a[j]][i + 1]));
		mx = max (mx, 1);
		j = g[a[j]].back () + 1;
	}
	//cerr << l << " " << r << " " << mx + cnt - (l == 0) << "\n";
	return mx + cnt - (l == 0);
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= n; ++i)
		g[a[i]].eb (i);

   	int cnt = 0;

   	for (int i = 1; i <= m; ++i)
   		if (g[i].size () == 0)
   			++cnt;

    cout << calc (0, n + 1) + cnt;

	return 0;
}
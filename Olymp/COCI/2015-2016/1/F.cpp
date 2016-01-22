#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline int RAND () {
	return (rand () * 1ll * rand ()) % ((int)1e9);
}

const int N = 11000;

ll pref[N];
int rea[N];

inline void dfs (const int &v, const int &p, const int &lvl, int mx, const ll &sum) {
	
	mx = max (mx, a[v]);
	
	
	if ()
	
	for (auto to : g[v]) {
	
	}
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	srand (time (0));
	
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= 100; ++i)
		rea[i] = (RAND () + rand ()) % ((int)1e9);

	for (int i = 1; i <= 100; ++i)
		pref[i] = rea[i] + pref[i - 1];
		
	for (int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].emplace_back (y);
		g[y].emplace_back (x);
	}

	dfs (1, 0, 1);
	
	return 0;
}
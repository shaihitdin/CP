#include <bits/stdc++.h>

using namespace std;


inline bool dfs (int v) {
	if (u[v])
		return 0;
	u[v] = 1;
	for (int i = 1; i <= n; ++i) {
		if ((a[i] + 1) % 6 != a[v] && (a[v] + 1) % 6 != a[i])
			continue;
		if (!p2[i] || dfs (p2[i])){
			p1[v] = i;
			p2[i] = v;
			return 1;
		}
	}
	return 0;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif


	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int t;
	cin >> t;

	for (int _ = 1; _ <= t; ++_) {
		cout << "Case #" << _ << ": ";
		cin >> n >> r >> o >> y >> g >> b >> v;
		for (int i = 1; i <= n; ++i)
			p1[i] = p2[i] = 0;
		for (int i = 1; i <= r; ++i)
			a[i] = 0;
		for (int i = 1; i <= o; ++i)
			a[i + r] = 1;
		for (int i = 1; i <= y; ++i)
			a[i + r + o] = 2;
		for (int i = 1; i <= g; ++i)
			a[i + r + o + y] = 3;
		for (int i = 1; i <= b; ++i)
			a[i + r + o + y + g] = 4;
		for (int i = 1; i <= v; ++i)
			a[i + r + o + y + g + b] = 5;
		for (int run = 1; run; ) {
			run = 0;
			for (int i = 1; i <= n; ++i)
				if (!u[i])
					if (dfs (i))
						run = 1;
		}
		int cnt = 0;
		for (int i = 1; i <= n; ++i)
			cnt += (p1[i] > 0);
		if (cnt != n) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		int x = 1;
		for (int cnt = 1; 
	}	
	return 0;
}
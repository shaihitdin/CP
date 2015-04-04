#include <bits/stdc++.h>

using namespace std;

set <pair <long long, int> > s;

int main () {
	
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf ("%d%d%d", &a, &b, &c);
		g[a].push_back (mkp (b, c));
		g[b].push_back (mkp (a, c));
	}
	for (int i = 2; i <= n; ++i)
		
	return 0;
}
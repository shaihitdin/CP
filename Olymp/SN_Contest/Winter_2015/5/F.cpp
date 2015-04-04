#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

set <int> g[N];
int n, d, a, b, c;

int main () {
	
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int t;
	scanf ("%d", &t);

	while (t--) {
		scanf ("%d%d", &n, &d);
		int ans = 0;
		for (int i = 0; i < n; ++i)
			g[i].clear();
		for (int i = 1; i < n; ++i) {
			scanf ("%d%d%d", &a, &b, &c);
			g[a].insert (b);
			g[b].insert (a);
			ans += c;
		}
		int cnt = 0;
		for (int i = 0; i < n; ++i)
			if (g[i].size() == 1)
				++cnt;
		ans += (((cnt / 2 + (cnt & 1)) * d));
		printf ("%d\n", ans);
	}
	return 0;
}
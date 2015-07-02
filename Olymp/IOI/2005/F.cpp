#include <bits/stdc++.h>

using namespace std;

inline void calc_ans (const int &v, const int &k) {

}

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	scanf ("%d%d", &n, &k);

	for (int i = 1; i <= n; ++i) {
		scanf ("%d%d%d", &cnt[i], &to, &dist[i]);
		g[to].push_back (i);
	}

	return 0;
}
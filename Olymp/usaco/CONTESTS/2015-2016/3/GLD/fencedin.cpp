/**
	Oh, my dear
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 100;

int a[N], n;

struct edge {

}

inline ll sqr (ll x) {
	return x * x;
}

inline bool inside (int x, int y) {
	return 1 <= x && 1 <= n && 1 <= y && y <= m;
}

int main () {
	
	freopen ("fenced.in", "r", stdin);
	freopen ("fenced.out", "w", stdout);
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> A >> B >> n >> m;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= m; ++i)
		cin >> b[i];
	
	sort (a + 1, a + n + 1);
	sort (b + 1, b + m + 1);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (inside (i - 1, j)) {
				g[i][j].emplace_back (make_pair ());
			}
			if (inside (i, j - 1)) {
			
			}
			if (inside (i + 1, j)) {
			
			}
			if (inside (i, j + 1)) {
			
			}
		}
	}
	
	return 0;
}
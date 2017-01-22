#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

bool u[N];
int n, a[N][N], c[N], cnt[N];

inline void dfs (int v) {
	if (u[v])	return;
	u[v] = 1;
	for (int i = 1; i <= n; ++i) {
		if (a[v][i]) {
			dfs (i);
			if (c[i])
				c[v] = c[i];
		}
	}	
	++cnt[c[v]];
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= k; ++i) {
		int x;
		cin >> x;
		c[x] = x;
	}

	while (m--) {
		int x, y;
		cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}
	
	for (int i = 1; i <= n; ++i) {
		dfs (i);
	}	

	int ans = 0;	
	int top = 1;
	
	for (int i = 1; i <= n; ++i) {
		if (cnt[i] > cnt[top])
			top = i;
	}
	
	for (int i = 1; i <= n; ++i) {
		if (!c[i])
			c[i] = top;
		for (int j = 1; j <= n; ++j) {
			if (i == j)
				continue;
			if (c[i] == c[j] && !a[i][j])
				++ans, a[i][j] = a[j][i] = 1;
		}
	}	
	
	cout << ans;
	
	return 0;
}
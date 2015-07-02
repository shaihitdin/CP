#include <bits/stdc++.h>

using namespace std;

const int N = 501;

vector <int> g[N];

bool u[N];
int p[N];
int n;
int sx[N], sy[N], fx[N], fy[N], t[N];

inline bool dfs (const int &v) {
	if (u[v])
		return 0;
	u[v] = 1;
	for (auto to : g[v]) {
		if (!p[to] || dfs (p[to])) {
			p[to] = v;
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

	scanf ("%d", &n);
	
	for (int i = 1; i <= n; ++i) {
		int h, m;
		scanf ("%d:%d%d%d%d%d", &h, &m, &sx[i], &sy[i], &fx[i], &fy[i]);
		t[i] = h * 60 + m;
	}
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (t[i] + abs (sy[i] - fy[i]) + abs (sx[i] - fx[i]) + abs (fx[i] - sx[j]) + abs (fy[i] - sy[j]) < t[j])
				g[i].push_back (j);
	
	for (int i = 1; i <= n; ++i) {
		memset (u, 0, sizeof (u));
		dfs (i);
	}
	
	int ans = 0;
	
	for (int i = 1; i <= n; ++i)
		if (!p[i])
			++ans;
	
	printf ("%d", ans);
	
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

vector <int> g[N];
bool u[N];
int n, m;
int p[N], p1[N];
int ans[N];

inline bool dfs (const int &v) {
	if (u[v])
		return 0;
	u[v] = 1;
	for (auto it : g[v]) {
		if (!p[it] || dfs (p[it])) {
			p[it] = v;
			p1[v] = it;
			return 1;
		}
	}
	return 0;
}


int main () {
    /*
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	*/

	scanf ("%d%d", &n, &m);

	for (int i = 1; i <= m; ++i) {
		int x, y;
		scanf ("%d%d", &x, &y);
		g[i].push_back (x);
		g[i].push_back (y);
	}

	for (int run = 1; run;) {
		run = 0;
		memset (u, 0, sizeof (u[0]) * (m + 2));
		for (int i = 1; i <= m; ++i)
			if (!p1[i] && dfs (i))
				run = 1;
	}

	for (int i = 1; i <= n; ++i) {
		if (!p[i]) {
			printf ("NO\n");
			return 0;
		}
	}

	printf ("YES\n");

	for (int i = 1; i <= n; ++i)
		printf ("%d\n", p[i]);
	
	return 0;
}
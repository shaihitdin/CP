#include <bits/stdc++.h>

using namespace std;

inline bool dfs (const int &v) {
	if (u[v])
		return 0;
	u[v] = 1;
	for (auto to : g[v]) {
		if (p[to] == -1 || dfs (p[to]))
			return 1;
	}
	return 0;
}

int main () {

	scanf ("%d%d", &n, &m);

	for (int i = 1; i <= m; ++i) {
		scanf ("%d%d", &x, &y);
		g[x].push_back (y);
	}

	for (int run = 1; run;) {
		run = 0;
		for (int j = 1; j <= n; ++j)
			u[j] = 0;
		for (int j = 1; j <= n; ++j) {
			if (p[j] == -1 && dfs (j) == 1)
				run = 1;
		}
	}
	
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;

int lvl[N][19];
int n, m, t, q, sz[N], pos[N];
int element[N];

int main () {	
	freopen ("queue.in", "r", stdin);
	freopen ("queue.out", "w", stdout);

	scanf ("%d", &n);
	sz[0] = 0;
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &q);
		if (q == 1) {
			scanf ("%d%d", &t, &m);
			sz[i] = sz[t] + 1;
			pos[i] = i;
			element[i] = m;
			lvl[i][0] = t;
			for (int j = 1; j < 19; ++j)
				lvl[i][j] = lvl[lvl[i][j - 1]][j - 1];
		} else {
			scanf ("%d", &t);
			int go = sz[t] - 1;
			sz[i] = sz[t] - 1;
			t = pos[t];
			int now = t;
			for (int j = 18; j >= 0; --j)
				if ((go & (1 << j)))
					now = lvl[now][j];
			printf ("%d\n", element[now]);
			pos[i] = t;
		}
	}

	return 0;
}
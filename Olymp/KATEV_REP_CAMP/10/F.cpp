#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 1;

map <int, int> p[N];

set <int> cnt[N];

int n, m, k;

int ans[N];

inline int get_p (const int &x, const int &type) {
	if (p[x][type] == 0)
		p[x][type] = x;
	return (x == p[x][type]) ? x : p[x][type] = get_p (p[x][type], type);
}

inline void Merge (int x, int y, const int &type) {
	x = get_p (x, type);
	y = get_p (y, type);
	if (rand() & 1)
		p[x][type] = y;
	else
		p[y][type] = x;
}

int x[N], y[N], q[N];

int main () {
	freopen ("metro.in", "r", stdin);
	freopen ("metro.out", "w", stdout);

	srand (time (0));

	scanf ("%d%d%d", &n, &m, &k);

	for (int i = 1; i <= m; ++i) {
		scanf ("%d%d%d", &x[i], &y[i], &q[i]);
		Merge (x[i], y[i], q[i]);
	}

	for (int i = 1; i <= m; ++i)
		cnt[q[i]].insert (get_p (x[i], q[i]));
	
	for (int i = 1; i <= k; ++i)
		printf ("%d\n", cnt[i].size());
	
	return 0;
}
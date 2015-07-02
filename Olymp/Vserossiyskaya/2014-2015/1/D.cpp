#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100, inf = 1e9 + 7;

inline int gp (const int &x) {
	return x == p[x] ? x : p[x] = gp (p[x]);
}

inline void Merge (int x, int y) {
	a = gp (a);
	b = gp (b);
	if (rand & 1)
		swap (a, b);
	p[a] = b;
}

struct segment {
	int now, was, pos;
}

inline bool operator < (const segment &lhs, const segment &rhs) {
	return lhs.now < rhs.now;
}

set <segment> Set;

inline int calc (int x) {
	x = gp (x);
	int res = inf;
	if (l[x] - 1 > 1) {
		int lx
		res = min (res, )
	}
	if (
}

inline void calc () {
	for (int i = 2; i < m; ++i)
		Set.insert ({b[i], 0, i});
	int cnt = m;

}

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	srand (time (0));

	ios_base :: sync_with_stdio (0);

	scanf ("%d", &test);

	for (; test; --test) {

		scanf ("%d%d\n", &n, &k);

		a[0] = 3;
		
		for (int i = 1; i <= n; ++i)
			a[i] = getchar () - '0';
		
		for (int i = 1; i <= n; ++i)
			go[i] = (a[i] == a[i - 1]) ? go[i - 1] : i;

		go[n + 1] = n + 1;
		
		for (int i = 2; i <= n + 1; ++i)
			if (go[i] == i)
				b[++m] = i - go[i - 1], color[m] = a[i - 1];
		
		int tc1 = a[1], tc2 = a[n];

		for (int i = 1; i <= m; ++i)
			p[i] = i, l[i] = i, r[i] = i;
		
		
	}
	
	return 0;
}
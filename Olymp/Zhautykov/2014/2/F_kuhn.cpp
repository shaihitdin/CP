#include <bits/stdc++.h>

using namespace std;

short n, m;
int k, ans;

const int N1 = 2001, N2 = 30001;

short p1[N2], p2[N2], temp;
vector <short> g[N2], gr[N2];
short sz = 1;
int u[N2];

inline bool kuhn (const short &v) {
	if (u[v] == sz)
		return 0;
	u[v] = sz;
	for (short to : g[v]) {
		if (!p2[to] || kuhn (p2[to])) {
			p2[to] = v;
			p1[v] = to;
			return 1;
		}
	}
	return 0;
}

inline void try_kuhn (const short &v) {
	++sz;
	temp += kuhn (v);
}

int l = 1, r = 1;

inline bool kuhn2 (const short &v) {
	if (u[v] == sz)
		return 0;
	u[v] = sz;
	for (short to : gr[v]) {
		if ((l <= to && to <= r) && (!p1[to] || kuhn2 (p1[to]))) {
			p1[to] = v;
			p2[v] = to;
			return 1;
		}
	}
	return 0;
}

inline void try_kuhn2 (const short &v) {
	++sz;
	temp += kuhn2 (v);
}

int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	srand (76765456);	
	scanf ("%hd%hd%d", &n, &m, &k);	
	short x, y;
	for (int i = 1; i <= k; ++i) {
		scanf ("%hd%hd", &x, &y);
		g[x].push_back (y);
		gr[y].push_back (x);
	}
	for (int i = 1; i <= n; ++i)
		random_shuffle (g[i].begin(), g[i].end());
	for (int i = 1; i <= m; ++i)
		random_shuffle (gr[i].begin(), gr[i].end());
	short no_pair;
	for (; r <= n; ++r) {
		try_kuhn (r);
		while (temp == m) {
			ans += n - r + 1;
			no_pair = p1[l];
			++l;
			if (no_pair != 0) {
				p2[no_pair] = 0;
				p1[l - 1] = 0;
				--temp;
				try_kuhn2 (no_pair);
			}
		}
	}
	printf ("%d", ans);
	return 0;
}
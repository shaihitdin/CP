#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

#define mkp make_pair
#define F first
#define S second

const short N = 6001, sz = (1 << 13);

short n, r[N];
vector <short> g[N];
vector <short> mx[N];
short ans;
short t[(sz << 1) + 1];

inline short maxx (const short &x, const short &y) {
	return (x > y) ? x : y;
}

inline void upd (short x, const short &el) {
	x += sz;
	t[x] = el;
	x >>= 1;
	while (x >= 1) {
		t[x] = maxx (t[x << 1], t[(x << 1) + 1]);
		x >>= 1;
	}

}

inline short get (short l, short r) {
	short res = 0;
	l += sz;
	r += sz;
	while (l < r) {
		if (l & 1) {
			res = maxx (res, t[l]);
			++l;
		}
		if (!(r & 1)) {
			res = maxx (res, t[r]);
			--r;
		}
		if (l >= r)
			break;
		l >>= 1;
		r >>= 1;
	}
	res = maxx (res, t[l]);
	return res;
}

inline void add_element (const short &v, const short &delta) {
	if(mx[r[v]].size() == 0 || mx[r[v]][mx[r[v]].size() - 1] < delta) {
		mx[r[v]].push_back (delta);
		upd (r[v], delta);
	}
}

inline void del_element (const short &v, const short &va) {
	if (mx[r[v]][mx[r[v]].size() - 1] == va) {
		mx[r[v]].pop_back();
		upd (r[v], mx[r[v]][mx[r[v]].size() - 1]);
	}
}

bool u[N];

inline void dfs (const short &v) {
	u[v] = 1;
	short local = get (0, r[v] - 1) + 1;
	ans = maxx (ans, local);
	add_element (v, local);
	for (short to = 0; to < g[v].size(); ++to)
		if(!u[g[v][to]])
			dfs (g[v][to]);
	del_element (v, local);
}

pair <int, int> b[N];

short cnt;

int a[N];

int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	scanf ("%d", &n);
	
	for (short i = 1; i <= n; ++i)
		scanf ("%d", a + i);
	
	for (short i = 1; i <= n; ++i) {
		b[i].F = a[i];
		b[i].S = i;
	}
	
	sort (b + 1, b + n + 1);
	
	for (short i = 1; i <= n; ++i) {
		if (b[i].F == b[i-1].F)
			r[b[i].S] = cnt;
		else {
			r[b[i].S] = ++cnt;
			mx[cnt].push_back (0);
		}
	}
	
	for (short i = 1; i < n; ++i) {
		short x, y;
		scanf ("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	for (short i = 1; i <= n; ++i) {
		if(g[i].size() == 1) {
			memset (u, 0, sizeof(u));
			dfs (i);
		}
	}
	
	printf ("%d", ans);
	
	return 0;
}

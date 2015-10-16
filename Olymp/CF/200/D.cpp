#include <bits/stdc++.h>

using namespace std;

const int sz = 1 << 21, N = 5e5 + 100;

vector <int> g[N];
int n, m;

struct node {
	bool to_fill, x;
	node *l, *r;
	node () {
		to_fill = 0;
		x = 0;
		l = r = 0;
	}
	node (node *Tl, node *Tr) {
		to_fill = 0;
		x = 0;
		l = Tl;
		r = Tr;
	}
};

int tin[N], tout[N], timer;

inline void dfs (const int &v, const int &p) {
	tin[v] = ++timer;
	for (auto to : g[v]) {
		if (to == p)
			continue;
		dfs (to, v);
	}
	tout[v] = timer;
}

inline node * Build (const int &Tl, const int &Tr) {
	if (Tl == Tr)
		return new node ();
	int mid = (Tl + Tr) / 2;
	return new node (Build (Tl, mid), Build (mid + 1, Tr));
}

inline void push (node *t) {
	if (t -> to_fill) {
		t -> x = 1;
		if (t -> l)
			t -> l -> to_fill = 1;
		if (t -> r)
			t -> r -> to_fill = 1;
		t -> to_fill = 0;
	}
}

inline bool get (node *t, const int &Tl, const int &Tr, const int &l, const int &r) {
	push (t);
	if (Tl > r || Tr < l)
		return 1;
	if (l <= Tl && Tr <= r)
		return t -> x;
	int mid = (Tl + Tr) / 2;
	return get (t -> l, Tl, mid, l, r) & get (t -> r, mid + 1, Tr, l, r);
}

inline void upd (node *t, const int &Tl, const int &Tr, const int &l, const int &r, const int &val) {
	push (t);
	if (Tl > r || Tr < l)
		return;
	if (l <= Tl && Tr <= r) {
		if (val == 0)
			t -> x = 0;
		else
			t -> to_fill = 1;
		push (t);
		return;
	}
	int mid = (Tr + Tl) / 2;
	upd (t -> l, Tl, mid, l, r, val); upd (t -> r, mid + 1, Tr, l, r, val);
	t -> x = t -> l -> x & t -> r -> x;
} 

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	scanf ("%d", &n);

	for (int i = 1; i < n; ++i) {
		int x, y;
		scanf ("%d%d", &x, &y);
		g[x].emplace_back (y);
		g[y].emplace_back (x);
	}
	
	dfs (1, 0);
	
	scanf ("%d", &m);

	node *root = Build (1, sz);
	
	while (m--) {
		int c, v;
		scanf ("%d%d", &c, &v);
		if (c == 1) {
			upd (root, 1, sz, tin[v], tout[v], 1);
		} else if (c == 2) {
			upd (root, 1, sz, tin[v], tin[v], 0);
		} else {
			printf ("%d\n", get (root, 1, sz, tin[v], tout[v]));
		}
	}
	
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1, inf = 1e9;

struct node {
	int x, y, cnt, mn;
	node (const int &element) {
		x = element;
		y = rand();
		cnt = 1;
		mn = x;
	}
}

inline int mn (node *it) {
	return it ? it -> mn : inf;
}

inline int cnt (node *it) {
	return it ? it -> cnt : 0;
}

inline void upd (node *it) {
	if (it) {
		it -> cnt = 1 + cnt (it -> l) + cnt (it -> r);
		it -> mn = min (it -> x, min (mn (it -> l), mn (it -> r)));
	}
}

inline void Split (node *t, node *&l, node *&r, const int &key) {
	if (!t) {
		l = r = 0;
	}	
	else if (cnt (t -> l) + 1 < key)
		Split (t -> r, t -> r, r, key - (cnt (t -> l) + 1)), r = t;
	else
		Split (t -> l, l, t -> l, key), l = t;
	upd (l);
	upd (r);
}

inline void Merge (node *&t, node *l, node *r) {
	if (!l || !r)
		t = l ? l : r;
	else if (l -> y > r -> y)
		Merge (l -> r, l -> r, r), t = l;
	else
		Merge (r -> l, l, r -> l), t = r;
	upd (l);
	upd (r);
}

int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	scanf ("%d", &n);

	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &k[i], &h[i]);
	}


	return 0;
}
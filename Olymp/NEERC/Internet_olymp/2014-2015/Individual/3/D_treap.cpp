#include <bits/stdc++.h>

using namespace std;

struct node {
	double x, to_upd;
	int y, id;
	node *l, *r;

	node (const double &element, const int &number) {
		l = r = 0;
		x = element;
		y = rand();
		to_upd = 0;
		id = number;
	}
};

inline void push (node *t) {
	if (t) {
		t -> x -= t -> to_upd;
		if (t -> l)
			t -> l -> to_upd += t -> to_upd;
		if (t -> r)
			t -> r -> to_upd += t -> to_upd;
		t -> to_upd = 0;
	}
}

inline void Split (node *t, node *&l, node *&r, const double &key) {
	push (t);
	if (!t)
		l = r = 0;
	else if (t -> x < key)
		Split (t -> r, t -> r, r, key), l = t; 
	else
		Split (t -> l, l, t -> l, key), r = t;
	push (t);
}

inline void Merge (node *&t, node *l, node *r) {
	push (l), push (r);
	if (!l || !r)
		t = l ? l : r;
	else if (l -> y > r -> y)
		Merge (l -> r, l -> r, r), t = l;
	else
		Merge (r -> l, l, r -> l), t = r;
	push (t);	
}

int main () {
	
	freopen ("downloading.in", "r", stdin);
	freopen ("downloading.out", "w", stdout);

	scanf ("%d%d", &n, &v);

	for (int i = 1; i <= n; ++i) {
		scanf ("%d%d", &s, &w);
	}

	return 0;
}
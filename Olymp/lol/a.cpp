#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

struct node {
	int x, cnt;
	unsigned short y;
	node *l, *r;
	node () {
		x = cnt = 0;
		y = 0;
		l = r = 0;
	}
	node (const int &element) {
		x = element;
		cnt = 1;
		y = rand();
		l = r = 0;
	}
};

node init[N];



inline int cnt (node *t) {
	return t ? t -> cnt : 0;
}

inline void upd (node *t) {
	if (t)
		t -> cnt = 1 + cnt (t -> l) + cnt (t -> r);
}

inline void Merge (node *&t, node *l, node *r) {
	if (!l || !r)
		t = l ? l : r;
	else if (l -> y > r -> y)
		Merge (l -> r, l -> r, r), t = l;
	else
		Merge (r -> l, l, r -> l), t = r;
	upd (t);
}

inline void Split (node *t, node *&l, node *&r, const int &key) {
	if (!t)
		l = r = 0;
	else if (cnt (t -> l) + 1 <= key)
		Split (t -> r, t -> r, r, key - cnt (t -> l) - 1), l = t;
	else
		Split (t -> l, l, t -> l, key), r = t;	
	upd (t);
}

inline void out (node *t) {
	if (!t)
		return;
	out (t -> l);
	printf ("%d ", t -> x);
	out (t -> r);
}

node *root, *L, *R, *mid, *R1, *tmp;

int n, m, l, r;
int main () {
	freopen ("movetofront.in", "r", stdin);
	freopen ("movetofront.out", "w", stdout);
	ios_base :: sync_with_stdio (0);
	srand (228);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		tmp = &init[i];
		*tmp = node (i);
		Merge (root, root, tmp);
	}
	for (int i = 1; i <= m; ++i) {
		scanf ("%d%d", &l, &r);
		Split (root, L, R, l - 1);
		Split (R, mid, R1, r - l + 1);
		Merge (L, mid, L);
		Merge (root, L, R1);
	}
	out (root);
	return 0;
}
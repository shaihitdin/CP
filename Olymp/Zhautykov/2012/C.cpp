#include <iostream>
#include <stdio.h>
using namespace std;
const int inf = 1e9;
const int N = 3e5;
struct bohr {
	bohr *l, *r;
	int change, mn;
	bohr () {
		l = r = NULL;
		mn = inf;
		change = 0;
	}
};
bohr *root;
int n, x, a[N], ans, ans1;
inline bool bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;
}
inline void push (bohr *it, const int &lvl) {
	if (it -> change) {
		if (bit (it -> change, lvl))
			swap (it -> l, it -> r);
		if (it -> l)
			it -> l -> change ^= it -> change;
		if (it -> r)
			it -> r -> change ^= it -> change;
		it -> change = 0;
	}
}
inline int mn (bohr *it) {
	return it ? it -> mn : inf;
}
inline void upd (bohr *it) {
	if (it)
		it -> mn = min (it -> mn, min (mn (it -> l), mn (it -> r)));
}
inline void add_node (bohr *t, const int &lvl, const int &st, const int &num) {
	if (lvl == -1) {
		if (!t)
			t = new bohr();
		t -> mn = min (st, t -> mn);
		return;
	}
	push (t, lvl);
	if (bit (num, lvl)) {
		if (!t -> r)
			t -> r = new bohr();
		add_node (t -> r, lvl - 1, st, num);
	}
	else {
		if (!t -> l)
			t -> l = new bohr();
		add_node (t -> l, lvl - 1, st, num);	
	}
	upd (t);
}
inline int get_ans (bohr *t, const int &lvl, const int &num) {
	if (!t)
		return inf;
	push (t, lvl);
	if (lvl == -1)
		return t -> mn;
	if (bit (num, lvl))
		return get_ans (t -> r, lvl - 1, num);
	else
		return min (get_ans (t -> l, lvl - 1, num), mn (t -> r));
}
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	scanf ("%d%d", &n, &x);
	root = new bohr();
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		root -> change ^= a[i];
		add_node (root, 30, i, a[i]);
		int temp = get_ans (root, 30, x);
		if (ans < i - temp + 1) {
			ans = i - temp + 1;
			ans1 = temp;
		}
	}
	printf ("%d %d", ans1, ans);
	return 0;
}
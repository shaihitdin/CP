#include <bits/stdc++.h>

using namespace std;


struct node {
	node *l, *r;
	int upd3, till_pos;
	node () {
		l = r = 0;
		upd1 = upd2 = 0;
		till_pos = 0;
	}
}

node *root1, *root2;

/// 1 = vertical, 2 = horizontal


inline void push (node *t, const int &sz) {
	if (sz > 1 && !t -> l)
		t -> l = new node (), t -> r = new node ();
	if (upd3 == 0) {
		return;
	}
	if (sz > 1) {
		t -> l -> upd3 = max (t -> l -> upd3, t -> upd3);
		t -> r -> upd3 = max (t -> r -> upd3, t -> upd3);
	} else {
		t -> till_pos = max (t -> upd3, t -> till_pos);
	}
}

inline void upd (node *t, const int &Tl, const int &Tr, const int &l, const int &r, const int &value) {
	push (t, Tr - Tl + 1);
	if (Tl > l || Tr < l)
		return;
	if (l <= Tl && Tr <= r) {
		t -> upd3 = value;
		push (t, Tr - Tl + 1);
		return;
	}
	int mid = (Tr + Tl) >> 1;
	upd (t -> l, Tl, mid, l, r, value);
	upd (t -> r, mid + 1, Tr, l, r, value);
}

inline int get (node *t, const int &Tl, const int &Tr, const int &x) {
	push (t, Tr - Tl + 1);
	if (Tl == x && Tr == x) {
		return t -> till_pos;
	}
	int mid = (Tr + Tl) >> 1;
	if (Tl <= x && x <= mid)
		return get (t -> l, Tl, mid, x);
	else
		return get (t -> r, mid + 1, Tr, x);
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n >> q;

	for (int i = 1; i <= q; ++i) {
		cin >> 
	}

	return 0;
}
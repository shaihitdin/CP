#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7;

struct node {
	int upd1, upd2, upd3, mx;
	node *l, *r;
	node () {
		upd1 = upd2 = upd3 = mx = -inf;
		l = r = 0;
	}
	node (node *Tl, node *Tr) {
		mx = max (Tl -> mx, Tr -> mx);
		upd1 = upd2 = upd3 = -inf;
		l = Tl;
		r = Tr;
	}
};

inline void push (node *t, const int &sz) {
	if (t -> upd1 == t -> upd2  && t -> upd2 == t -> upd3 && t -> upd2 == -inf)
		return;
	else {
		if (t -> upd1 != -inf && t -> upd3 != -inf) {
			t -> mx = max (t -> upd1 + t -> upd2 + t -> upd3, t -> upd1 + t -> upd2 * (sz) + t -> upd3);
		}
		if (!t -> l)
			return;
		t -> l -> upd1 = t -> upd1;
		t -> l -> upd2 = t -> upd2;
		t -> l -> upd3 = t -> upd3;
		t -> r -> upd1 = t -> upd1 + sz / 2 * t -> upd2;
		t -> r -> upd2 = t -> upd2;
		t -> r -> upd3 = t -> upd3;
		t -> upd1 = t -> upd2 = t -> upd3 = -inf;
	}
}

inline int upd (node *t, const int &Tl, const int &Tr, const int &l, const int &r, const int &a, const int &b, const int &c) {
	if (Tl > r || Tr < l)
		return 0;
	if (!t -> l)
		t -> l = new node (), t -> r = new node ();
	if (l <= Tl && Tr <= r) {
		push (t, Tr - Tl + 1);
		t -> upd1 = a;
		t -> upd2 = b;
		t -> upd3 = c;
		push (t, Tr - Tl + 1);
		return Tr - Tl + 1;
	}
	int mid = (Tl + Tr) >> 1;
	int haha = upd (t -> l, Tl, mid, l, r, a, b, c);
	haha += upd (t -> r, mid + 1, Tr, l, r, a + b * haha, b, c);
	return haha;
}

inline int get (node *t, const int &Tl, const int &Tr, const int &l, const int &r) {
	if (Tl > r || Tr < l)
		return -inf;
	if (!t -> l)
		t -> l = new node (), t -> r = new node ();
	push (t, Tr - Tl + 1);
	if (l <= Tl && r <= Tr)
		return t -> mx;
	int mid = (Tr + Tl) >> 1;
	return max (get (t -> l, Tl, mid, l, r), get (t -> r, mid + 1, Tr, l, r));
}

node *root;

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	int n;
	scanf ("%d\n", &n);

	root = new node ();
	
	while (1) {
		char q_type;
		scanf ("%c", &q_type);
		if (q_type == 'I') {
			int a, b, diff;
			scanf ("%d%d%d", &a, &b, &diff);
			upd (root, 1, n, a, b, get (root, 1, n, a - 1, a - 1), diff);
			upd (root, 1, n, b + 1, n, get (root, 1, n,) );
		} else if (q_type == 'Q') {
			int h;
			scanf ("%d", &h);
			int l = 0, r = n + 1;
			while (r - l > 1) {
				int mid = (l + r) >> 1;
				if (get (root, 1, n, 1, mid) > h)
					r = mid;
				else
					l = mid;
			}
			printf ("%d\n", l);
		} else {
			return 0;
		}
		scanf ("\n");
	}

}
#include <bits/stdc++.h>


using namespace std;

const int inf = 1e9 + 7;

struct node {
	int type1, type2, lst_val, mx;
	node *l, *r;
	node () {
		type1 = -inf;
		type2 = mx = lst_val = 0;
		l = r = 0;
	}
};

inline void push (node *t, const int &sz, const int &lst_val) {
	if (!t)
		return;
	if (t -> type1 == -inf && t -> type2 == 0)
		return;
	if (t -> type1 == -inf) {
		t -> mx += t -> type2;
		if (t -> l)
			t -> l -> type2 += t -> type2, t -> r -> type2 += t -> type2;
	} else {
		t -> mx = max (t -> type1 + t -> lst_val, t -> type1 * sz + t -> lst_val);
		if (t -> l) {
			t -> l -> type2 += t -> type2, t -> r -> type2 += (sz / 2) * t -> type1 + t -> type2;
			t -> l -> type1 = t -> r -> type1 = t -> type1;
		}
	}
	t -> type1 = -inf;
	t -> type2 = 0;
}

inline int upd (node *t, const int &Tl, const int &Tr, const int &l, const int &r, const int &upd1, const int &upd2, const int &lst_val) {
	if (Tl > r || Tr < l)
		return;
	if (Tl != Tr && !t -> l)
		t -> l = new node (), t -> r = new node ();
	int mid = (Tr + Tl) >> 1;
	if (l <= Tl && Tr <= r) {
		push (t, Tr - Tl + 1);
		t -> type1 = upd1;
		if (upd1 != -inf)
			t -> type2 += upd2 + upd1 * (Tl - l);
		else
			t -> type2 += upd2;
		push (t, Tr - Tl + 1);
		push (t -> l, mid - Tl + 1);
		push (t -> r, Tr - (mid + 1) + 1);		
		return;
	}
	int temp = upd (t -> l, Tl, mid, l, r, upd1, upd2, lst_val);
	upd (t -> r, mid + 1, Tr, l, r, upd1, upd2, temp);
	t -> mx = max (t -> l -> mx, t -> r -> mx);
}

inline int get (node *t, const int &Tl, const int &Tr, const int &l, const int &r) {
	if (Tl > r || Tr < l)
		return 0;
	if (Tl != Tr && !t -> l)
		t -> l = new node (), t -> r = new node ();
	push (t, Tr - Tl + 1);
	if (l <= Tl && Tr <= r)
		return t -> mx;
	int mid = (Tr + Tl) >> 1;
	return max (get (t -> l, Tl, mid, l, r), get (t -> r, mid + 1, Tr, l, r));
}


node *root;

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	cin.tie (0);
	ios_base :: sync_with_stdio (0);
	
	int n;
	cin >> n;

	root = new node ();

	for (int q_num = 1; 1; ++q_num) {
		char q_type;
		cin >> q_type;
		if (q_type == 'I') {
			int l, r, ch;
			cin >> l >> r >> ch;
			int check1 = get (root, 1, n, r, r);
			upd (root, 1, n, l, r, ch);
			int check2 = get (root, 1, n, r, r);
			if (r < n)
				upd (root, 1, n, r + 1, n, -inf, check2 - check1);
		} else if (q_type == 'Q') {
			int h;
			cin >> h;
			int l = 0, r = n + 1;
			while (r - l > 1) {
				int mid = (r + l) >> 1;
				if (get (root, 1, n, 1, mid) > h)
					r = mid;
				else
					l = mid;
			}
			cout << l << "\n";
		} else {
			return 0;
		}
	}

}
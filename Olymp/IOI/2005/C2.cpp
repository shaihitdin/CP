#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7, sz = 1 << 30;

struct node {
	int sum, mx, upd;
	node *l, *r;
	node () {
		sum = mx = 0;
		l = r = 0;
		upd = inf;
	}
};

inline void push (node *t, const int &sz) {
	if (sz > 1 && !t -> l)
		t -> l = new node (), t -> r = new node ();
	if (t -> upd == inf)
		return;
	t -> sum = sz * t -> upd;
	t -> mx = max (0, t -> sum);
	if (sz > 1)
		t -> l -> upd = t -> r -> upd = t -> upd;
	t -> upd = inf;
}

inline void upd (node *t, const int &Tl, const int &Tr, const int &l, const int &r, const int &upd_val) {

	push (t, Tr - Tl + 1);

	if (Tl > r || Tr < l)
		return;


	int mid = (Tl + Tr) >> 1;

	if (l <= Tl && Tr <= r) {
		t -> upd = upd_val;
		push (t, Tr - Tl + 1);		
		return;
	}

	upd (t -> l, Tl, mid, l, r, upd_val);
	upd (t -> r, mid + 1, Tr, l, r, upd_val);
	
	t -> sum = t -> l -> sum + t -> r -> sum;
	t -> mx = max (t -> l -> mx, t -> l -> sum + t -> r -> mx);
}

inline int get_ans (node *t, const int &Tl, const int &Tr, const int &need_h) {
	if (Tl == Tr)
		return Tl;

	push (t, Tr - Tl + 1);
	
	int mid = (Tr + Tl) >> 1;
	
	push (t -> l, mid - Tl + 1);
	push (t -> r, Tr - (mid + 1) + 1);

	if (t -> l -> mx > need_h)
		return get_ans (t -> l, Tl, mid, need_h);
	else
		return get_ans (t -> r, mid + 1, Tr, need_h - t -> l -> sum);
}

node *root;

int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int n;

	cin >> n;

	root = new node ();
	
	while (1) {
		char q_type;
		cin >> q_type;
		if (q_type == 'Q') {
			int h;
			cin >> h;
			cout << get_ans (root, 1, n + 1, h) - 1 << "\n";
		} else if (q_type == 'I') {
			int l, r, h;
			cin >> l >> r >> h;
			upd (root, 1, n + 1, l, r, h);
		} else {
			return 0;
		}
	}

}
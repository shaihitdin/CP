#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll sz = 1 << 17;

const ll bpr = 1e9 + 7;

struct node {
	ll sum1, sum2, total_sum, c1, c2;
	node *l, *r;
	node () {
		sum1 = sum2 = total_sum = 0;
		c1 = c2 = 0;
		l = r = 0;
	}
};

inline void add (int &x, const int &y) {
	x += y;
	if (x >= bpr)
		x -= bpr;
}

inline void add (ll &x, const ll &y) {
	x += y;
	if (x >= bpr)
		x -= bpr;
}

inline void push (node *t, const ll &sz, bool flag = 0) {
	t -> total_sum = (t -> total_sum + ((t -> sum1 * t -> c2) % bpr) + ((t -> sum2 * t -> c1) % bpr) + ((t -> c1 * 1ll * t -> c2) % bpr) * 1ll * sz) % bpr;
	t -> sum1 += t -> c1 * 1ll * sz;
	t -> sum2 += t -> c2 * 1ll * sz;
	t -> sum1 %= bpr; t -> sum2 %= bpr;
	
	if (sz > 1 && !t -> l)
		t -> l = new node (), t -> r = new node ();

	if (sz > 1) {
		add (t -> l -> c1, t -> c1);
		add (t -> l -> c2, t -> c2);
		add (t -> r -> c1, t -> c1);
		add (t -> r -> c2, t -> c2);
		if (!flag) {
			push (t -> l, sz / 2, 1);
			push (t -> r, sz / 2, 1);
		}
	}
	t -> c1 = t -> c2 = 0;
}

inline void upd (node *t, const ll &Tl, const ll &Tr, const ll &l, const ll &r, const ll &val1, const ll &val2) {
	if (Tr < l || Tl > r)
		return;
	
	if (!t -> l && Tr != Tl)
		t -> l = new node (), t -> r = new node ();
	
	if (l <= Tl && Tr <= r) {
		add (t -> c1, val1);
		add (t -> c2, val2);
		push (t, Tr - Tl + 1);
		return;
	}
	
	push (t, Tr - Tl + 1);
	
	ll mid = (Tl + ll(Tr)) / 2;
	upd (t -> l, Tl, mid, l, r, val1, val2);
	upd (t -> r, mid + 1, Tr, l, r, val1, val2);
	t -> sum1 = t -> l -> sum1;
	add (t -> sum1, t -> r -> sum1);
	t -> sum2 = t -> l -> sum2;
	add (t -> sum2, t -> r -> sum2);
	t -> total_sum = t -> l -> total_sum;
	add (t -> total_sum, t -> r -> total_sum);
}

inline ll get (node *t, const ll &Tl, const ll &Tr, const ll &l, const ll &r) {
	if (Tr < l || Tl > r)
		return 0;
		
	if (!t -> l && Tr != Tl)
		t -> r = new node (), t -> l = new node ();
	
	push (t, Tr - Tl + 1);
	
	if (l <= Tl && Tr <= r)
		return t -> total_sum;

	ll mid = (Tl + ll(Tr)) / 2;
	ll res = get (t -> l, Tl, mid, l, r) + get (t -> r, mid + 1, Tr, l, r);
	add (res, 0);
	return res;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n, m;
	
	cin >> n >> m;

	node *root = new node ();
	
	while (m--) {
		char q_type;
		cin >> q_type;
		if (q_type == '*') {
			int l, r, c;
			cin >> l >> r >> c;
			upd (root, 1, sz, l, r, 0, c);
		} else if (q_type == '.') {
			int l, r, c;
			cin >> l >> r >> c;
			upd (root, 1, sz, l, r, c, 0);
		} else {
			int l, r;
			cin >> l >> r;
			cout << get (root, 1, sz, l, r) << "\n";
		}
	}

	return 0;
}
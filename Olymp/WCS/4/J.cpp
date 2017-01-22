#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int sz = 1 << 30, oo = 1e9, N = 1e5 + 100;

struct node {
	int x, add;
	node *l, *r;
	node () {
		x = add = 0;
		l = r = 0;
	}
	node (node *s1, node *s2) {
		x = max (s1 -> x + s1 -> add, s2 -> x + s2 -> add);
		add = 0;
		l = s1, r = s2;
	}
};

node *root;
int sx[N + 100], sy[N + 100], fx[N + 100], fy[N + 100], add_val[N + 100], q;
vector <pair <int, pair <int, int> > > add[N + 100], del[N + 100];

inline void push (node *t) {
	if (t -> add) {
		t -> x += t -> add;
		if (t -> l) {
			t -> l -> add += t -> add;
			t -> r -> add += t -> add;
		}
		t -> add = 0;
	}
}

inline void upd (node *t, int Tl, int Tr, int l, int r, int delta) {
	if (!t -> l && Tl != Tr)
		t -> l = new node (), t -> r = new node ();
	if (Tl > r || Tr < l)
		return;
	push (t);
	if (l <= Tl && Tr <= r) {
		t -> add += delta;
		push (t);
		return;
	}
	int mid = (Tl + Tr) >> 1;
	upd (t -> l, Tl, mid, l, r, delta);
	upd (t -> r, mid + 1, Tr, l, r, delta);
	*t = node (t -> l, t -> r);
}

inline int get (node *t, int Tl, int Tr, int l, int r) {
	if (!t -> l && Tl != Tr)
		t -> l = new node (), t -> r = new node ();
	if (Tl > r || Tr < l)
		return -oo;
	push (t);
	if (l <= Tl && Tr <= r)
		return t -> x;
	int mid = (Tl + Tr) >> 1;
	return max (get (t -> l, Tl, mid, l, r), get (t -> r, mid + 1, Tr, l, r));
}

int main () {

	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> q;

	map <int, int> cc;
	
	for (int i = 1; i <= q; ++i) {
		cin >> sx[i] >> sy[i] >> fx[i] >> fy[i] >> add_val[i];
	}
	
	for (int i = 1; i <= q; ++i) {
		add[sy[i]].emplace_back (make_pair (add_val[i], make_pair (sx[i], fx[i])));
		del[fy[i] + 1].emplace_back (make_pair (add_val[i], make_pair (sx[i], fx[i])));
	}		
	
	int ans = -oo;
	
	int n, m;


	cin >> n >> m;
	
	root = new node ();
	
	for (int i = 1; i <= m; ++i) {
		for (auto it : add[i]) {
			upd (root, 1, sz, it.second.first, it.second.second, it.first);
		}
		for (auto it : del[i]) {
			upd (root, 1, sz, it.second.first, it.second.second, -it.first);
		}
		ans = max (ans, get (root, 1, sz, 1, n));
	}
	
	cout << ans;
	
	return 0;
}
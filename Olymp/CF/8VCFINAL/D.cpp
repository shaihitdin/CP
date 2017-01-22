#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int sz = 1 << 30, oo = 1e9;

struct node {
	int x;
	node *l, *r;
	node () {
		l = r = 0;
		x = oo;
	}
	node (int sds) {
		l = r = 0;
		x = sds;
	}
	node (node *Tl, node *Tr) {
		l = Tl, r = Tr;
		x = min (Tl -> x, Tr -> x);
	}
} *root;

inline void upd (node *t, int Tl, int Tr, int pos, int x) {
	if (!t -> l)
		t -> l = new node (), t -> r = new node ();
	if (pos > Tr || pos < Tl)
		return;
	if (Tl == pos && Tr == pos) {
		t -> x = x;
		return;
	}
	int mid = (Tl + Tr) >> 1;
	upd (t -> l, Tl, mid, pos, x);
	upd (t -> r, mid + 1, Tr, pos, x);
	t -> x = min (t -> l -> x, t -> r -> x);
}

inline int get (node *t, int Tl, int Tr, int l, int r) {
	if (Tl > r || Tr < l)
		return oo;
	if (!t -> l)
		t -> l = new node (), t -> r = new node ();
	if (l <= Tl && Tr <= r)
		return t -> x;
	int mid = (Tl + Tr) >> 1;
	return min (get (t -> l, Tl, mid, l, r), get (t -> r, mid + 1, Tr, l, r));
}

int d, n, m;

int main () {

	#ifdef UNBROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> d >> n >> m;

	root = new node ();
	
	for (int i = 1; i <= m; ++i) {
		int x, p;
		cin >> x >> p;
		upd (root, 1, sz, x, p);
	}

	int now = 0;

	ll ans = 0;
	
	while (now + n < d) {
		if (get (root, 1, sz, now + 1, now + n) == oo) {
			cout << -1;
			return 0;
		}
		int val = get (root, 1, sz, now + 1, now + n);
		int l = now + 1, r = now + n + 1;
		while (r - l > 1) {
			int mid = (r + l) >> 1;
			if (get (root, 1, sz, now + 1, mid) == val)
				l = mid;
			else
				r = mid;
		}
		int ded = (d - l);
		if (ded <= n) {
			int total_need = l - now + d - l;
			int have = (n - (l - now));
			ans += (total_need - have) * 1ll * val;
		} else {
			ans += (l - now) * 1ll * val;
		}
		now = l;
		cerr << now << " " << 
	}
	
	cout << ans;
	
	return 0;
}
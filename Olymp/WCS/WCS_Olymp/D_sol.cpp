#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int oo = 1e9, sz = 1 << 30;

struct node {
	int x;
	node *l, *r;
	node () {
		x = 0;
		l = r = 0;
	}
	node (int xx) {
		x = xx;
		l = r = 0;
	}
};

inline void add (node *t, int Tl, int Tr, int pos, int x) {
	if (!t -> l && Tl != Tr)
		t -> l = new node (), t -> r = new node ();
	if (pos > Tr || pos < Tl)
		return;
	if (Tl == pos && Tr == pos) {
		t -> x += x;
		return;
	}
	int mid = (Tl + Tr) >> 1;
	add (t -> l, Tl, mid, pos, x);
	add (t -> r, mid + 1, Tr, pos, x);
	t -> x = t -> l -> x + t -> r -> x;
}

inline int get (node *t, int Tl, int Tr, int l, int r) {
	if (!t -> l && Tl != Tr)
		t -> l = new node (), t -> r = new node ();
	if (Tl > r || Tr < l)
		return 0;
	if (l <= Tl && Tr <= r)
		return t -> x;
	int mid = (Tl + Tr) >> 1;
	return get (t -> l, Tl, mid, l, r) + get (t -> r, mid + 1, Tr, l, r);
}


node *ts[6], *root;
set <int> Set;

inline int recalc (int pos, int k) {
	if (get (root, 0, sz - 1, 0, pos) < k)
		return oo + 1;
	int l = 0, r = pos + 1;
	while (r - l > 1) {
		int mid = (r + l) >> 1;
		if (get (root, 0, sz - 1, mid, pos) >= k)
			l = mid;
		else
			r = mid;
	}
	return pos - l;
}

int main () {

	#ifdef BROKEN
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int q;
	
	cin >> q;

	ts[1] = new node (), ts[2] = new node (), ts[3] = new node (), ts[4] = new node (), ts[5] = new node (), root = new node ();
	
	while (q--) {
		char q_type;
		cin >> q_type;
		if (q_type == '+') {
			int x;
			cin >> x;
			//cerr << x << "\n";
			Set.insert (x);
			add (root, 0, sz - 1, x, 1);
			auto it = Set.upper_bound (x);
			for (int i = 2; i <= 5 && it != Set.end (); ++i, ++it) {
				for (int j = i; j <= 5; ++j) {
					int z = recalc (*it, j);
					int z2 = recalc (*it, j + 1);
					add (ts[j], 0, sz - 1, z2, -1);
					add (ts[j], 0, sz - 1, z, 1);
				}
			}
			for (int i = 1; i <= 5; ++i) {
				int z = recalc (x, i);
				add (ts[i], 0, sz - 1, z, 1);
			}
		} else if (q_type == '-') {
			int x;
			cin >> x;
			auto it = Set.upper_bound (x);
			for (int i = 2; i <= 5 && it != Set.end (); ++i, ++it) {
				for (int j = i; j <= 5; ++j) {
					int z = recalc (*it, j);
					int z2 = recalc (*it, j + 1);
					add (ts[j], 0, sz - 1, z, -1);
					add (ts[j], 0, sz - 1, z2, 1);
				}
			}
			for (int i = 1; i <= 5; ++i) {
				int z = recalc (x, i);
				add (ts[i], 0, sz - 1, z, -1);
			}
			Set.erase (x);
			add (root, 0, sz - 1, x, -1);
		} else {
			int k, d;
			cin >> k >> d;
			cout << get (ts[k], 0, sz - 1, 0, d) << "\n";
		}
		if (q % 1000 == 0) {
			cerr << q << "\n";
		}

	}
	
	return 0;
}
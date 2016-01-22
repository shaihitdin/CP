#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct segment {
	ll beg_x, len, end_x;
};

const int sz = 1 << 17, sz2 = (1 << 5);
const ll oo = 1e16;

inline segment Merge (const segment &lhs, const segment &rhs) {
	if (lhs.end_x + 1 == rhs.beg_x)
		return {lhs.beg_x, lhs.len + rhs.len, rhs.end_x};
	return {-oo, -oo, -oo};
}

inline bool operator < (const segment &lhs, const segment &rhs) {
	return lhs.len < rhs.len;
}

inline bool operator > (const segment &lhs, const segment &rhs) {
	return lhs.len > rhs.len;
}

struct node {
	segment suff, mx, now, pref;
	ll add;
};

node t[sz + sz + 100];

inline void push (const int &v) {
	if (!t[v].add)
		return;
	t[v].pref.beg_x += t[v].add;
	t[v].pref.end_x += t[v].add;
	t[v].suff.beg_x += t[v].add;
	t[v].suff.end_x += t[v].add;
	t[v].mx.beg_x += t[v].add;
	t[v].mx.end_x += t[v].add;
	if (t[v].now.len > 0) {
		t[v].now.beg_x += t[v].add;
		t[v].now.end_x += t[v].add;
	}
	if (v < sz) {
		t[v + v].add += t[v].add;
		t[v + v + 1].add += t[v].add;
	}
	t[v].add = 0;
}

inline void upd (const int &v, const int &Tl, const int &Tr, const int &l, const int &r, const int &x) {
	push (v);
	if (Tl > r || Tr < l)
		return;
	if (l <= Tl && Tr <= r) {
		t[v].add += x;
		push (v);
		return;
	}
	int mid = (Tl + Tr) >> 1;
	upd (v + v, Tl, mid, l, r, x);
	upd (v + v + 1, mid + 1, Tr, l, r, x);
	t[v].pref = max (Merge (t[v + v].now, t[v + v + 1].pref), t[v + v].pref);
	t[v].suff = max (Merge (t[v + v].suff, t[v + v + 1].now), t[v + v + 1].suff);
	t[v].now = Merge (t[v + v].now, t[v + v + 1].now);
	t[v].mx = max (t[v + v].mx, t[v + v + 1].mx);
	t[v].mx = max (t[v].mx, Merge (t[v + v].suff, t[v + v + 1].pref));
}

vector <node> ss;

inline void get (const int &v, const int &Tl, const int &Tr, const int &l, const int &r) {
	push (v);
	if (Tl > r || Tr < l)
		return;
	if (l <= Tl && Tr <= r) {
		ss.emplace_back (t[v]);
		return;
	}
	int mid = (Tl + Tr) >> 1;
	get (v + v, Tl, mid, l, r);
	get (v + v + 1, mid + 1, Tr, l, r);
}

int main () {

	freopen ("atoms.in", "r", stdin);
	freopen ("atoms.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n, m;
	cin >> n;

	for (int i = 0; i < sz; ++i) {
		t[sz + i].pref = {-oo, -oo, -oo};
		t[sz + i].suff = {-oo, -oo, -oo};
		t[sz + i].now = {-oo, -oo, -oo};
		t[sz + i].mx = {-oo, -oo, -oo};
	}

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		t[sz + i].pref = {x, 1, x};
		t[sz + i].suff = {x, 1, x};
		t[sz + i].now = {x, 1, x};
		t[sz + i].mx = {x, 1, x};		
	}
	
	for (int v = sz - 1; v; --v) {
		t[v].pref = max (Merge (t[v + v].now, t[v + v + 1].pref), t[v + v].pref);
		t[v].suff = max (Merge (t[v + v].suff, t[v + v + 1].now), t[v + v + 1].suff);
		t[v].now = Merge (t[v + v].now, t[v + v + 1].now);
		t[v].mx = max (t[v + v].mx, t[v + v + 1].mx);
		t[v].mx = max (t[v].mx, Merge (t[v + v].suff, t[v + v + 1].pref));
	}
	
	cin >> m;

	vector <node> get_l;
	get_l.resize (sz2 + sz2 + 10);
	
	while (m--) {
		char q_type;
		cin >> q_type;
		if (q_type == '+') {
			int l, r, d;
			cin >> l >> r >> d;
			upd (1, 0, sz - 1, l, r, d);
		} else {
			int l, r;
			cin >> l >> r;
			ss.resize (0);
			get (1, 0, sz - 1, l, r);
			
			for (int i = 0; i < sz2; ++i) {
				get_l[sz2 + i].pref = {-oo, -oo, -oo};
				get_l[sz2 + i].suff = {-oo, -oo, -oo};
				get_l[sz2 + i].now = {-oo, -oo, -oo};
				get_l[sz2 + i].mx = {-oo, -oo, -oo};
			}

			for (int i = 0; i < ss.size (); ++i) {
				get_l[sz2 + i] = ss[i];
			}
		
			for (int v = sz2 - 1; v; --v) {
				get_l[v].pref = max (Merge (get_l[v + v].now, get_l[v + v + 1].pref), get_l[v + v].pref);
				get_l[v].suff = max (Merge (get_l[v + v].suff, get_l[v + v + 1].now), get_l[v + v + 1].suff);
				get_l[v].now = Merge (get_l[v + v].now, get_l[v + v + 1].now);
				get_l[v].mx = max (get_l[v + v].mx, get_l[v + v + 1].mx);
				get_l[v].mx = max (get_l[v].mx, Merge (get_l[v + v].suff, get_l[v + v + 1].pref));
			}
			cout << get_l[1].mx.len << "\n";
		}
	}
	
	
	return 0;
}
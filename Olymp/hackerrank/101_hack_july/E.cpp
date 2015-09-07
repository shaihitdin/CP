#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int sz = 1 << 17;

struct node {
	ll mx, sum_mn, sum_pl, pref_sum_pl, pref_sum_mn, suff_sum_pl, suff_sum_mn, sz;
	node () {
		mx = sum_mn = sum_pl = pref_sum_pl = pref_sum_mn = suff_sum_pl = suff_sum_mn = sz = 0;
	}
};

node t[sz + sz];

/*
sum_pl first is plus, sum_mn - first is minus,
pref_sum_pl begins with plus, pref_sum_mn begins with minus, 
suff_sum_pl end with plus, suff_sum_mn end with minus
*/

inline node Merge (const node &Tl, const node &Tr) {
	node v = node ();
	if (Tl.sz == 0)
		return Tr;
	if (Tr.sz == 0)
		return Tl;
	v.mx = max (Tl.mx, Tr.mx);
	v.mx = max (v.mx, Tl.suff_sum_pl + Tr.pref_sum_mn);
	v.mx = max (v.mx, Tl.suff_sum_mn + Tr.pref_sum_pl);
	if (Tl.sz == 1) {
		v.pref_sum_pl = max (Tl.pref_sum_pl, Tl.sum_pl + Tr.pref_sum_mn);
		v.pref_sum_mn = max (Tl.pref_sum_mn, Tl.sum_mn + Tr.pref_sum_pl);
	} else {
		v.pref_sum_pl = max (Tl.pref_sum_pl, Tl.sum_pl + Tr.pref_sum_pl);
		v.pref_sum_mn = max (Tl.pref_sum_mn, Tl.sum_mn + Tr.pref_sum_mn);
	}
	if (Tr.sz == 1) {
		v.suff_sum_pl = max (Tr.suff_sum_pl, Tr.sum_pl + Tl.suff_sum_mn);
		v.suff_sum_mn = max (Tr.suff_sum_mn, Tr.sum_mn + Tl.suff_sum_pl);
	} else {
		v.suff_sum_pl = max (Tr.suff_sum_pl, Tr.sum_mn + Tl.suff_sum_pl);
		v.suff_sum_mn = max (Tr.suff_sum_mn, Tr.sum_pl + Tl.suff_sum_mn);
	}
	if (Tl.sz == 1) {
		v.sum_mn = Tl.sum_mn + Tr.sum_pl;
		v.sum_pl = Tl.sum_pl + Tr.sum_mn;
	} else {
		v.sum_mn = Tl.sum_mn + Tr.sum_mn;
		v.sum_pl = Tl.sum_pl + Tr.sum_pl;
	}
	v.sz = Tl.sz + Tr.sz;
	return v;
}

inline void upd (int x, const ll &y) {
	x += sz;
	t[x].mx = y;
	t[x].sum_mn = -y;
	t[x].sum_pl = y;
	t[x].pref_sum_pl = y;
	t[x].pref_sum_mn = -y;
	t[x].suff_sum_pl = y;
	t[x].suff_sum_mn = -y;
	t[x].sz = 1;
    while (x >>= 1)
		t[x] = Merge (t[x + x], t[x + x + 1]);
}

inline ll get (int l, int r) {
	node tmp_l = node (), tmp_r = node ();
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l & 1) {
			if (tmp_l.sz == 0)
				tmp_l = t[l++];
			else
				tmp_l = Merge (tmp_l, t[l++]);
		}
		if (!(r & 1)) {
			if (tmp_r.sz == 0)
				tmp_r = t[r--];
			else
				tmp_r = Merge (t[r--], tmp_r);
		}
		if (l > r)
			break;
	}
	if (!tmp_r.sz) {
		return tmp_l.mx;
	}
	if (!tmp_l.sz) {
		return tmp_r.mx;
	}
	tmp_l = Merge (tmp_l, tmp_r);
	cerr << tmp_l.sz << " " << tmp_r.sz << " " << tmp_l.mx << "\n";
	return tmp_l.mx;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		ll x;
		cin >> x;
		upd (i, x);
	}
	
	int q;
	cin >> q;

	while (q--) {
		char q_type;
		cin >> q_type;
		if (q_type == 'U') {
			ll x, y;
			cin >> x >> y;
			upd (x, y);
		} else {
			ll l, r;
			cin >> l >> r;
			cout << get (l, r) << "\n";
		}
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node {
	ll mx, p_val;
	node *l, *r;
	node () {
		mx = 0, p_val = 0;
		l = r = 0;
	}
}

inline void add (node *t, const ll &Tl, const ll &Tr, const ll &l, const ll &r, const ll &add_val) {
	if ()
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);

	cin >> h >> q;

	sz = 1 << (h - 1);

	ll t_l = 1 << (h - 1), t_r = (1 << h) - 1;

	root = new node ();
	
	while (q--) {
		ll lol, l, r, type;
		cin >> lol >> l >> r >> type;
		while (l < sz) {
			l *= 2;
			r *= 2;
		}
		l -= sz;
		++l;
		r -= sz;
		++r;
		if (type == 0)
			add (root, 1, sz, l, r, -oo);
		else
			add (root, 1, sz, l - sz + 1, r - sz + 1, 1);
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct node {
	ll x, y, cnt;
	node *l, *r;
	node() {
		x = 0;
		cnt = 1;
		y = rand ();
		l = r = 0;
	}
	node(const ll &key) {
		x = key;
		cnt = 1;
		y = rand ();
		l = r = 0;
	}
};

inline int cnt(node *it) {
	return it ? it -> cnt : 0;
}

inline void upd(node *it) {
	if (it)
		it -> cnt = cnt(it -> l) + cnt(it -> r) + 1;
}

inline void Merge(node *&t, node *l, node *r) {
	if (!l || !r)
		t = l ? l : r;
	else if (l -> y > r -> y)
		Merge(l -> r, l -> r, r), t = l;
	else
		Merge(r -> l, l, r -> l), t = r;
	upd(t);
}

inline void Split_cnt(node *t, node *&l, node *&r, const ll &x) {
	if (!t) {
		l = r = 0;
		return;
	}
	if (cnt(t -> l) + 1 > x)
		Split_cnt(t -> l, l, t -> l, x), r = t;
	else
		Split_cnt(t -> r, t -> r, r, x - cnt(t -> l) - 1), l = t;
	upd(l);
	upd(r);
}

inline void Split_key(node *t, node *&l, node *&r, const ll &x) {
	if (!t) {
		l = r = 0;
		return;
	}
	if (t -> x > x)
		Split_key(t -> l, l, t -> l, x), r = t;
	else
		Split_key(t -> r, t -> r, r, x), l = t;
	upd(l);
	upd(r);
}

int n;
ll l;
ll ans;

node *root, *L, *R;

int main () {
	
	#ifdef UNBROKEN
	freopen ("in", "r", stdin);
	#endif
	
	srand (time (0));
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> l;
	
	for (int i = 1; i <= n; ++i) {
		ll x;
		cin >> x;
		ll consumed_time = x * l + i;
		//cerr << cnt (root) << " ";
		Split_key (root, L, R, consumed_time);
		//cerr << cnt (L) << " " << cnt (R) << "\n";
		ans += cnt (R);
		Merge (L, L, new node (consumed_time));
		Merge (root, L, R);
	}

	cout << ans;
	
	return 0;
}
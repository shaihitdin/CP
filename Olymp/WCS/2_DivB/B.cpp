#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
/*
struct node {
	int x, y, cnt;
	node *l, *r;
	node() {
		x = 0;
		cnt = 1;
		y = rand ();
		l = r = 0;
	}
	node(const int &key) {
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

inline void Split_cnt(node *t, node *&l, node *&r, const int &x) {
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

inline void Split_key(node *t, node *&l, node *&r, const int &x) {
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
*/

int n;
ll l;
ll ans;

const int sz = 1 << 20;
int t[sz + sz];
int a[sz];

inline void add (int x) {
	++t[x += sz];
	while (x >>= 1)
		t[x] = t[x + x] + t[x + x + 1];
}

inline int get (int l, int r) {
	int res = 0;
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l & 1)
			res += t[l++];
		if (!(r & 1))
			res += t[r--];
		if (l > r)
			break;
	}
	return res;
}

int main () {
	
	#ifdef UNBROKEN
	freopen ("in", "r", stdin);
	#endif
	
	srand (time (0));
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> l;
	
	vector <ll> cc;
	
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		ll consumed_time = x * l + i;
		a[i] = consumed_time;
		cc.emplace_back (a[i]);
	}

	sort (cc.begin (), cc.end ());
	cc.resize (unique (cc.begin (), cc.end ()) - cc.begin ());
	
	for (int i = 1; i <= n; ++i)
		a[i] = lower_bound (cc.begin (), cc.end (), a[i]) - cc.begin () + 1;
	
	for (int i = 1; i <= n; ++i) {
		ans += get (a[i] + 1, sz - 1);
		add (a[i]);
	}
	
	cout << ans;
	
	return 0;
}
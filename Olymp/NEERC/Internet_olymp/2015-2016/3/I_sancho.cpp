#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (ll i = ll(x); i <= ll(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "lcm."
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef pair <int, int> PII;
typedef double ld;

const int N = 2e5;

inline int RAND() {
	return (rand() * 1ll * rand()) % (1 << 30);
}

const int oo = 1e9 + 7;

struct node {
	int x, y, id, add, cnt, sz;
	node *l, *r;
	node() {
		x = add = id = 0;
		cnt = 1;
		y = RAND();
		l = r = 0;
	}
	node(const int &key, int _id) {
		x = key;
		id = _id;
		cnt = 1;
		add = 0;
		y = RAND();
		l = r = 0;
	}
};

inline void push(node *t) {
	if (t && t -> add) {
		t -> x += t -> add;
		if (t -> l)
			t -> l -> add += t -> add;
		if (t -> r)
			t -> r -> add += t -> add;
		t -> add = 0;
	}
}

inline int cnt(node *it) {
	return it ? it -> cnt : 0;
}

inline void upd(node *it) {
	if (it)
		it -> cnt = cnt(it -> l) + cnt(it -> r) + 1;
}

inline void Merge(node *&t, node *l, node *r) {
	push(l);
	push(r);
	if (!l || !r)
		t = l ? l : r;
	else if (l -> y > r -> y)
		Merge(l -> r, l -> r, r), t = l;
	else
		Merge(r -> l, l, r -> l), t = r;
	upd(t);
}

inline void Split_cnt(node *t, node *&l, node *&r, const int &x) {
	push(t);
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
	push(t);
	if (!t) {
		l = r = 0;
		return;
	}
	if (t -> x >= x)
		Split_key(t -> l, l, t -> l, x), r = t;
	else
		Split_key(t -> r, t -> r, r, x), l = t;
	upd(l);
	upd(r);
}           +

inline int get_min(node *it) {
	if (!it)
		return oo;
	push(it);
	return min(get_min(it -> l), it -> x);
}

node *root, *L[5], *R[5];

int n, m, k;
int t[N], h[N];

int main () {
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);

	ios_base :: sync_with_stdio(0);
	cin.tie(0);

	set <PII> all;

	cin >> n >> m >> k;
	forn(i, 1, n) {
		cin >> t[i] >> h[i];
		all.insert(PII(t[i], i));
	}

	while (all.size()) {
		int i = all.begin() -> S;
		all.erase(all.begin());
		while (cnt(root) && get_min(root) <= t[i]) {
			root
		}
		assert(cnt(root) <= m);
		if (cnt(root) == m) {
		    a[i] += k;
			all.insert(PII(a[i], i));
		}	
		else {
			
		}
	}	

	return 0;             
}       

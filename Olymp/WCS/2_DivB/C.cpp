#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 100;

struct node {
	int x, y, cnt;
	node *l, *r;
	bool flag;
	node() {
		x = 0;
		cnt = 1;
		y = rand ();
		l = r = 0;
		flag = 0;
	}
	node(const int &key) {
		x = key;
		cnt = 1;
		y = rand ();
		l = r = 0;
		flag = 0;
	}
};

inline void push(node *t) {
	if (t && t -> flag) {
		swap (t -> l, t -> r);
		t -> flag = 0;
		if (t -> l)
			t -> l -> flag ^= 1;
		if (t -> r)
			t -> r -> flag ^= 1;
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
	push (l);
	push (r);
	if (!l || !r)
		t = l ? l : r;
	else if (l -> y > r -> y)
		Merge(l -> r, l -> r, r), t = l;
	else
		Merge(r -> l, l, r -> l), t = r;
	upd(t);
}

inline void Split_cnt(node *t, node *&l, node *&r, const int &x) {
	push (t);
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
	push (t);
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
ll ans;

node *root, *L[5], *R[5];

int l[N], r[N], k[N];

inline void go_through (node *t) {
	if (!t)
		return;
	push (t);
	go_through (t -> l);
	cout << char (t -> x);
	go_through (t -> r);
}

int main () {
	
	#ifdef UNBROKEN
	freopen ("in", "r", stdin);
	#endif
	
	srand (time (0));
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	string s;
	cin >> s;
	
	for (int i = 0; i < s.size (); ++i)
		Merge (root, root, new node (s[i]));
	
	int q;

	cin >> q;

	for (int i = 1; i <= q; ++i)
		cin >> l[i] >> r[i] >> k[i];
	
	for (int i = q; i >= 1; --i) {
		Split_cnt (root, L[0], R[0], r[i]);
		Split_cnt (L[0], L[1], R[1], l[i] - 1);
		Split_cnt (R[1], L[2], R[2], k[i]);
		/*
		if (L[2])
			L[2] -> flag ^= 1;
		*/
		Merge (R[1], R[2], L[2]);
		Merge (L[0], L[1], R[1]);
		Merge (root, L[0], R[0]);
	}
	
	go_through (root);
	
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

inline int RAND() {
	return (rand() * 1ll * rand()) % (1 << 30);
}

typedef long long ll;

const int oo = 1e9 + 7;

struct node {
	int x, y, z;
	ll min_pref_sum, sum;
	node *l, *r;
	node() {
		x = 0;
		y = RAND();
		l = r = 0;
		z = 0;
		min_pref_sum = 0;
		sum = 0;
	}
	node(const int &key, const int &key2) {
		x = key;
		y = RAND();
		l = r = 0;
		z = key2;
		min_pref_sum = key2;
		sum = key2;
	}
};

inline ll sum (node *it) {
	return it ? it -> sum : 0;
}

inline ll min_pref_sum (node *it) {
	return it ? it -> min_pref_sum : 0;
}

inline void upd(node *it) {
	if (it) {
		it -> sum = sum(it -> l) + sum(it -> r) + it -> z;
		it -> min_pref_sum = min (min_pref_sum(it -> l), sum(it -> l) + it -> z + min_pref_sum (it -> r));
	}
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

inline void Split_key(node *t, node *&l, node *&r, const int &x) {
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
}


node *root, *L[5], *R[5], *tmp;

const int N = 2e5;


int main() {

	#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	#endif

	int n;

	scanf ("%d", &n);

	while (n--) {
		int c, d, M, h, m;
		scanf ("%d %02d.%02d %02d:%02d", &c, &d, &M, &h, &m);
		tmp = new node (m + h * 60 + d * 60 * 24 + M * 60 * 24 * 31, c);
		Split_key(root, L[0], R[0], tmp -> x);
		Merge (L[0], L[0], tmp);
		Merge (root, L[0], R[0]);
		printf ("%I64d\n", /*max (0ll, */root -> min_pref_sum)/*)*/;
	}
	
	return 0;
}
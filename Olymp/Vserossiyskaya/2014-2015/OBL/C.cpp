#include <bits/stdc++.h>

using namespace std;
const int N = 5e5 + 1;
typedef long long ll;
int sz = 1;
int n, m, x, q;

struct node {
	int x, y, cnt;
	ll sum;
	node *l, *r;
	node (const int &el) {
		sum = x = el;
		y = rand();
		cnt = 1;
		l = r = NULL;
	}
};

inline int cnt (node *&it) {
	return it ? it -> cnt : 0;
}

inline ll sum (node *&it) {
	return it ? it -> sum : 0;
}

inline void upd (node *it) {
	if (it) {
		it -> cnt = 1 + cnt (it -> l) + cnt (it -> r);
		it -> sum = ((it -> x) * 1LL * (it -> x)) + sum (it -> l) + sum (it -> r);
	}
}

inline void Split (node *t, node *&l, node *&r, const int &key) {
	if (!t)
		l = r = 0;
	else if (cnt (t -> l) + 1 <= key)
		Split (t -> r, t -> r, r, key - cnt (t -> l) - 1), l = t;
	else
		Split (t -> l, l, t -> l, key), r = t;
	upd (t);
}

inline void Merge (node *&t, node *l, node *r) {
	if (!l || !r)
		t = l ? l : r;
	else if (l -> y > r -> y)
		Merge (l -> r, l -> r, r), t = l;
	else
		Merge (r -> l, l, r -> l), t = r;
	upd (t);
}

node *root, *L, *R, *R1, *mid, *tmp, *L1, *R2;
int main () {
	freopen ("river.in", "r", stdin);
	freopen ("river.out", "w", stdout);
	srand (time (0));
	scanf ("%d%*d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &x);
		tmp = new node (x);
		Merge (root, root, tmp);
	}
	scanf ("%d", &m);
	for (int i = 1; i <= m; ++i) {
		scanf ("%d%d", &q, &x);
		printf ("%I64d\n", sum (root));
		Split (root, L, R, x - 1);
		Split (R, mid, R1, 1);
		if (q == 1) {
			Split (L, L, L1, cnt (L) - 1);
			Split (R1, R2, R1, 1);
			if (!L1 && !R2)
				assert (0);
			if (!L1)
				R2 -> x += mid -> x;
			else if (!R2)
				L1 -> x += mid -> x;
			else {
				L1 -> x += ((mid -> x) >> 1);
				R2 -> x += ((mid -> x) >> 1);
				if ((mid -> x) & 1)
					++(R2 -> x);
			}
			Merge (L, L, L1);
			Merge (R1, R2, R1);
			Merge (root, L, R1);
		}
		else {
			tmp = new node (((mid -> x) >> 1));
			Merge (L, L, tmp);
			tmp = new node ((((mid -> x) >> 1) + ((mid -> x) & 1)));
			Merge (L, L, tmp);
			Merge (root, L, R1);
		}
	}
	printf ("%I64d\n", sum (root));
	return 0;
}
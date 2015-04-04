#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
const int N = (1e5) + 1, inf = (1e9) + 1;
struct node {
	int x, y, mx, sum, own_val, cnt, mn;
	node *l, *r;
	node () {
		x = y = mx = sum = own_val = cnt = 0;
		mn = inf;
		l = r = NULL;
	}
};
inline int mx (const node *it) {
	return it ? it -> mx : 0;
}

inline int sum (const node *it) {
	return it ? it -> sum : 0;
}

inline int cnt (const node *it) {
	return it ? it -> cnt : 0;
}

inline int mn (const node *it) {
	return it ? it -> mn : inf;
}

inline void upd (node *it) {
	if (it) {
		it -> mx = max (it -> own_val, max (mx (it -> l), mx (it -> r)));
		it -> sum = it -> own_val - it -> x + 1 + sum (it -> l) + sum (it -> r);
		it -> cnt = 1 + cnt (it -> l) + cnt (it -> r);
		it -> mn = min (it -> x, min (mn (it -> l), mn (it -> r)));
	}
}

inline void Merge (node *&t, node *l, node *r) {
	upd(l); upd(r); upd(t);	
	if (!l || !r) {
		t = l ? l : r;
		return;
	}
	if (l -> y > r -> y)
		Merge (l -> r, l -> r, r), t = l;
	else
		Merge (r -> l, l, r -> l), t = r;
	upd(l); upd(r); upd(t);
}

inline void Split (node *t, node *&l, node *&r, const int &Split_key) {
	upd(t); upd(l); upd(r);
	if (!t) {
		l = r = 0;
		return;
	}
	if (t -> x >= Split_key)
		Split (t -> l, l, t -> l, Split_key), r = t;
	else
		Split (t -> r, t -> r, r, Split_key), l = t;
	upd(l); upd(r); upd(t);
}
node *root, *L, *R, *mid, *R1, *tmp;
int m, rndm[N], q, l, r;
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	srand (7777777);
	scanf ("%d", &m);
	for (int i = 1; i < N; ++i)
		rndm[i] = i;
	random_shuffle (rndm + 1, rndm + N);
	int last = 0;
	for (int i = 1; i <= m; ++i) {
		scanf ("%d%d%d", &q, &l, &r);
		l += last;
		r += last;
		if (q == 1) {
			int l_b = 0, r_b = l + 1;
			while (r_b - l_b > 1) {
				int mide = (r_b + l_b) >> 1;
				Split (root, L, R, mide);
				Split (R, mid, R1, l + 1);
				if (mx (mid) >= l)	l_b = mide;
				else	r_b = mide;
				Merge (R, mid, R1);
				Merge (root, L, R);
			}						
			if (l_b == 0)
				Split (root, L, R, l);
			else
				Split (root, L, R, l_b);				
			Split (R, mid, R1, r + 1);
			int res = sum (mid);
			if (mx (mid) > r) {
				res -= (mx (mid) - r);
			}
			if (mn (mid) < l) {
				res -= (l - mn (mid));
			}
			printf ("%d\n", res);
			last = res;
			Merge (R, mid, R1);
			Merge (root, L, R);
		}
		else {
			int l_b = 0, r_b = l + 1;
			while (r_b - l_b > 1) {
				int mide = (r_b + l_b) >> 1;
				Split (root, L, R, mide);
				Split (R, mid, R1, l);
				if (mx (mid) >= l)	l_b = mide;
				else	r_b = mide;
				Merge (R, mid, R1);
				Merge (root, L, R);
			}			
			tmp = new node();
			if (l_b == 0)
				Split (root, L, R, l), tmp -> x = l;
			else
				Split (root, L, R, l_b), tmp -> x = l_b;				
			Split (R, mid, R1, r + 1);
			tmp -> y = rndm[i];
			tmp -> own_val = max (r, mx (mid));
			Merge (R, tmp, R1);
			Merge (root, L, R);
		}
	}
	return 0;
}
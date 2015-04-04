#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct node {
	int cnt, y, x;
	long long sum, Union, suff[3], pref[3];
	node *l, *r;
	node () {
		cnt = y = 0;
		sum = 0;
		memset (suff, 0, sizeof(suff));
		memset (pref, 0, sizeof(pref));
		l = r = null;
	}
}

inline int cnt (const node *it) {
	return it? it -> cnt : 0;
}

inline int sum (const node *it) {
	return it? it -> sum : 0;
}

inline 

inline void upd (const node *&it) {
	if (it) {
		it -> cnt = 1 + cnt (it -> l) + cnt (it -> r);
		/**/
		
		/**/
		it -> sum = it -> Union + sum (it -> l) + sum (it -> r);
	}
}


inline void Merge (node *&t, node *l, node *r) {
	if (!l || !r) {
		t = l? l : r;
		return;
	}
	if (l -> y > r -> y)
		Merge (l -> r, l -> r, r), t = l;
	else
		Merge (r -> l, l, r -> l), t = r;
	upd (t);
}

inline void Split (node *t, node *&l, node *&r, const int &Split_key) {
	if (!t) {
		l = r = null;
		return;
	}
	if (cnt (t -> l) + 1 > Split_key)
		Split (t -> l, l, t -> l, Split_key), r = t;
	else
		Split (t -> r, t -> r, r, Split_key - cnt (t -> l) - 1), l = t;
	upd (t);
}

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d%d", &n, &m);	
	return 0;
}
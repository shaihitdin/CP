#include <bits/stdc++.h>

using namespace std;

#define y1 works


const int sz = 1024;

typedef long long ll;

/**

1|2
---
3|4

**/

struct node {
	ll x;
	int add;
	node *son1, *son2, *son3, *son4;
	node () {
		x = 0;
		add = 0;
		son1 = son2 = son3 = son4 = 0;
	}
	node (const int &element) {
		x = element;
		add = 0;
		son1 = son2 = son3 = son4 = 0;
	}
	node (node *nn1, node *nn2, node *nn3, node *nn4) {
		son1 = nn1;
		son2 = nn2;
		son3 = nn3;
		son4 = nn4;
		x = nn1 -> x + nn2 -> x + nn3 -> x + nn4 -> x;
		add = 0;
	}    
};

node init[sz * sz * 4];

/*
inline node * Build (const short &Tx1, const short &Ty1, 
				const short &Tx2, const short &Ty2) {
	if (Tx1 == Tx2 && Ty1 == Ty2)
		return new node (0);
	short midx = (Tx1 + Tx2) >> 1;
	short midy = (Ty1 + Ty2) >> 1;
	return new node (
		Build (Tx1, Ty1, midx, midy),
		Build (midx + 1, Ty1, Tx2, midy),
		Build (Tx1, midy + 1, midx, Ty2),
		Build (midx + 1, midy + 1, Tx2, Ty2)
	);
}
*/

int mx;

inline node * Build (const short &Tx1, const short &Ty1, 
				const short &Tx2, const short &Ty2, const int &v) {
	node *n_n;
	n_n = &init[v];	
	mx = max (v, mx);
	if (Tx1 == Tx2 && Ty1 == Ty2) {
		*n_n = node ();
		return n_n;
	}
	short midx = (Tx1 + Tx2) >> 1;
	short midy = (Ty1 + Ty2) >> 1;
	*n_n = node (
		Build (Tx1, Ty1, midx, midy, v * 4),
		Build (midx + 1, Ty1, Tx2, midy, v * 4 + 1),
		Build (Tx1, midy + 1, midx, Ty2, v * 4 + 2),
		Build (midx + 1, midy + 1, Tx2, Ty2, v * 4 + 3)
	);
	return n_n;
}

inline void push (node *&t, int &&szz) {
	if (!t -> add)
		return;
	t -> x += t -> add * 1ll * szz;
	if (szz != 1) {
		t -> son1 -> add += t -> add;
		t -> son2 -> add += t -> add;
		t -> son3 -> add += t -> add;
		t -> son4 -> add += t -> add;
	}
	t -> add = 0;
}


inline ll get (node *t, const short &Tx1, const short &Ty1, 
				const short &Tx2, const short &Ty2, 
				const short &x1, const short &y1, 
				const short &x2, const short &y2) {
	push (t, (Tx2 - Tx1 + 1) * (Ty2 - Ty1 + 1));
	if (Tx1 > x2 || Tx2 < x1 || Ty1 > y2 || Ty2 < y1)
		return 0;
	if (x1 <= Tx1 && y1 <= Ty1 && Tx2 <= x2 && Ty2 <= y2) {
		return t -> x;
	}
	short midx = (Tx1 + Tx2) >> 1;
	short midy = (Ty1 + Ty2) >> 1;
	return
		get (t -> son1, Tx1, Ty1, midx, midy, x1, y1, x2, y2) +
		get (t -> son3, Tx1, midy + 1, midx, Ty2, x1, y1, x2, y2) +
		get (t -> son2, midx + 1, Ty1, Tx2, midy, x1, y1, x2, y2) +
		get (t -> son4, midx + 1, midy + 1, Tx2, Ty2, x1, y1, x2, y2);
}

inline void upd (node *t, const short &Tx1, const short &Ty1, 
				const short &Tx2, const short &Ty2, 
				const short &x1, const short &y1, 
				const short &x2, const short &y2, const short &penalty) {
	push (t, (Tx2 - Tx1 + 1) * (Ty2 - Ty1 + 1));
	if (Tx1 > x2 || Tx2 < x1 || Ty1 > y2 || Ty2 < y1)
		return;
	if (x1 <= Tx1 && y1 <= Ty1 && Tx2 <= x2 && Ty2 <= y2) {
		t -> add += penalty;
		push (t, (Tx2 - Tx1 + 1) * (Ty2 - Ty1 + 1));
		return;
	}
	short midx = (Tx1 + Tx2) >> 1;
	short midy = (Ty1 + Ty2) >> 1;
	upd (t -> son1, Tx1, Ty1, midx, midy, x1, y1, x2, y2, penalty);
	upd (t -> son3, Tx1, midy + 1, midx, Ty2, x1, y1, x2, y2, penalty);
	upd (t -> son2, midx + 1, Ty1, Tx2, midy, x1, y1, x2, y2, penalty);
	upd (t -> son4, midx + 1, midy + 1, Tx2, Ty2, x1, y1, x2, y2, penalty);
	t -> x = t -> son1 -> x + t -> son2 -> x + t -> son3 -> x + t -> son4 -> x;
}

node *root;

int main () {
	freopen ("segtree2d.in", "r", stdin);
	freopen ("segtree2d.out", "w", stdout);
	int m;
	scanf ("%*d%*d%d", &m);
	short a, x1, y1, x2, y2, ch;
	root = Build (0, 0, sz - 1, sz - 1, 1);
	for (int q = 1; q <= m; ++q) {
		scanf ("%hd", &a);
		if (a == 1) {
			scanf ("%hd%hd%hd%hd%hd", &x1, &y1, &x2, &y2, &ch);
			--x1, --y1, --x2, --y2;
			upd (root, 0, 0, sz - 1, sz - 1, x1, y1, x2, y2, ch);
		} else {
			scanf ("%hd%hd%hd%hd", &x1, &y1, &x2, &y2);
			--x1, --y1, --x2, --y2;
			printf ("%lld\n", get (root, 0, 0, sz - 1, sz - 1, x1, y1, x2, y2));
		}
	}	
	//fprintf (stderr, "%d %d", clock() * 1000 / CLOCKS_PER_SEC, mx);
	return 0;
}
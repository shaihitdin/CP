#include <bits/stdc++.h>

using namespace std;

const int M = 64001, N = 30000;

#define y1 works


const int sz = 1 << 16;

typedef unsigned short us;

/**

1|2
---
3|4

**/


struct node {
	short x;
	node *son1, *son2, *son3, *son4;
	node () {
		x = 0;
		son1 = son2 = son3 = son4 = 0;
	}
	node (const int &element) {
		x = element;
		son1 = son2 = son3 = son4 = 0;
	}
	node (node *nn1, node *nn2, node *nn3, node *nn4) {
		son1 = nn1;
		son2 = nn2;
		son3 = nn3;
		son4 = nn4;
		x = nn1 -> x + nn2 -> x + nn3 -> x + nn4 -> x;
	}    
};

inline ll get (node *t, const us &Tx1, const us &Ty1, 
				const us &Tx2, const us &Ty2, 
				const us &x1, const us &y1, 
				const us &x2, const us &y2) {
	if (Tx1 > x2 || Tx2 < x1 || Ty1 > y2 || Ty2 < y1)
		return 0;
	if (x1 <= Tx1 && y1 <= Ty1 && Tx2 <= x2 && Ty2 <= y2) {
		return t -> x;
	}
	us midx = (int (Tx1) + Tx2) >> 1;
	us midy = (int (Ty1) + Ty2) >> 1;

	if (!t -> son1)
		t = new node (new node (), new node (), new node (), new node());

	return
		get (t -> son1, Tx1, Ty1, midx, midy, x1, y1, x2, y2) +
		get (t -> son3, Tx1, midy + 1, midx, Ty2, x1, y1, x2, y2) +
		get (t -> son2, midx + 1, Ty1, Tx2, midy, x1, y1, x2, y2) +
		get (t -> son4, midx + 1, midy + 1, Tx2, Ty2, x1, y1, x2, y2);
}

inline void upd (node *t, const us &Tx1, const us &Ty1, 
				const us &Tx2, const us &Ty2, 
				const us &x1, const us &y1) {
	if (Tx1 > x2 || Tx2 < x1 || Ty1 > y2 || Ty2 < y1)
		return;
	if (x1 == Tx1 && y1 == Ty1 && Tx2 == x1 && Ty2 == y1) {
		++ t -> x;
		return;
	}
	
	if (!t -> son1)
		t = new node (new node (), new node (), new node (), new node());
	
	us midx = (int (Tx1) + Tx2) >> 1;
	us midy = (int (Ty1) + Ty2) >> 1;

	upd (t -> son1, Tx1, Ty1, midx, midy, x1, y1, penalty);
	upd (t -> son3, Tx1, midy + 1, midx, Ty2, x1, y1, penalty);
	upd (t -> son2, midx + 1, Ty1, Tx2, midy, x1, y1, penalty);
	upd (t -> son4, midx + 1, midy + 1, Tx2, Ty2, x1, y1, penalty);
	t -> x = t -> son1 -> x + t -> son2 -> x + t -> son3 -> x + t -> son4 -> x;
}

node *root;

inline bool calc (const int &x, const int &y, const int &len) {
	int l = 0, r = x + 1;
	while (r - l > 1) {
	
	}
	return 
}

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	scanf ("%d%d", &n, &cnt);

	for (int i = 1; i <= n; ++i) {
		scanf ("%d%d", &x[i], &y[i]);
		upd (root, 0, 0, sz - 1, sz - 1, x[i], y[i], 1);
	}

	for (int i = 1; i <= n; ++i) {
		int l = 0, r = x[i] + 1;
		while (r - l > 1) {
			int mid = (r + l) >> 1;
			if (calc (x[i], y[i], mid) >= cnt)
				l = mid;
			else
				r = mid;
		}
	}
	return 0;
}
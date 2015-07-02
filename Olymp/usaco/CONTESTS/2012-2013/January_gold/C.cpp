#include <bits/stdc++.h>

using namespace std;

struct node {
	int pref, suff, mx;
	int flag;
	///flag = 0 -> fill with 0, flag = 1 -> fill with 1, flag = 2 -> normas
	node *l, *r;
	node (const int &teg) {
		pref = suff = mx = teg;
		l = r = 0;
		flag = 2;
	}
	node (node *Tl, node *Tr, const int &sz) {
		if (Tl -> pref == (sz >> 1))
			pref = Tl -> pref + Tr -> pref;
		else
			pref = Tl -> pref;
		if (Tr -> suff == (sz >> 1))
			suff = Tr -> suff + Tl -> suff;
		else
			suff = Tr -> suff;
		mx = max (max (Tl -> mx, Tr -> mx), Tl -> suff + Tr -> pref);
		mx = max (max (pref, suff), mx);
		l = Tl, r = Tr;
		flag = 2;
	}
};

int n, m;

inline node * build (const int &Tl, const int &Tr) {
	if (Tl == Tr)
		return new node ((Tl <= n) ? 1 : 0);
	int mid = (Tl + Tr) >> 1;
	return new node (build (Tl, mid), build (mid + 1, Tr), Tr - Tl + 1);
}

inline void push (node *t, const int &sz) {
	if (t -> flag == 2)
		return;

	if (t -> flag)
		t -> pref = t -> suff = t -> mx = 0;
	else
		t -> pref = t -> suff = t -> mx = sz;
	
	if (sz > 1)
		t -> l -> flag = t -> r -> flag = t -> flag;
	
	t -> flag = 2;
}

const int sz = 1 << 19;
node * root;

inline bool find_place (node *t, const int &Tl, const int &Tr, const int &cnt, const bool &flag = 0) {

    assert (t);
    
    push (t, Tr - Tl + 1);

	if (cnt <= 0)
		return 1;
			
	if (t -> mx == (Tr - Tl + 1) && (Tr - Tl + 1) == cnt) {
		t -> flag = 1;
		push (t, Tr - Tl + 1);
		return 1;
	}

	if (t -> mx == (Tr - Tl + 1) && (Tr - Tl + 1) < cnt)
		assert (0);

	assert (Tr - Tl + 1 > 1);
	
	int mid = (Tl + Tr) >> 1;

	push (t -> l, (Tr - Tl + 1) >> 1);
	push (t -> r, (Tr - Tl + 1) >> 1);

	if (flag) {
		if (t -> r -> suff == ((Tr - Tl + 1) >> 1))
			find_place (t -> l, Tl, mid, cnt - t -> r -> suff, 1), find_place (t -> r, mid + 1, Tr, t -> r -> suff, 1);
		else
			find_place (t -> r, mid + 1, Tr, cnt, 1);
		return 1;
	}
	
	if (t -> l -> mx >= cnt)
		find_place (t -> l, Tl, mid, cnt);
	else if (t -> l -> suff + t -> r -> pref >= cnt)
		find_place (t -> r, mid + 1, Tr, cnt - t -> l -> suff), find_place (t -> l, Tl, mid, t -> l -> suff, 1);
	else if (t -> r -> mx >= cnt)
		find_place (t -> r, mid + 1, Tr, cnt);
	else
		return 0;
	*t = node (t -> l, t -> r, Tr - Tl + 1);
	return 1;
}

inline void clear_place (node *t, const int &l, const int &r, const int &Tl, const int &Tr) {
	push (t, Tr - Tl + 1);
	
	if (Tl > r || Tr < l)
		return;
	
	if (l <= Tl && Tr <= r) {
		t -> flag = 0;
		push (t, Tr - Tl + 1);
		return;
	}
	
	int mid = (Tr + Tl) >> 1;
	clear_place (t -> l, l, r, Tl, mid), clear_place (t -> r, l, r, mid + 1, Tr);
	*t = node (t -> l, t -> r, Tr - Tl + 1);
}

int main () {

	freopen ("seating.in", "r", stdin);
	freopen ("seating.out", "w", stdout);

	scanf ("%d%d\n", &n, &m);

	root = build (1, sz);

	int ans (0);

	for (int i = 1; i <= m; ++i) {
		char q;
		int x, y;
		scanf ("%c", &q);
		cerr << i << " ";
		if (q == 'A') {
			scanf ("%d\n", &x);
			ans += (find_place (root, 1, sz, x) ^ 1);
		} else {
			scanf ("%d%d\n", &x, &y);
			clear_place (root, x, y, 1, sz);
		}
	}

	printf ("%d", ans);
	return 0;
}
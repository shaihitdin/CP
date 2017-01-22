#include <bits/stdc++.h>

using namespace std;

struct node {
	int ans, l_e, r_e, l_e_dec, l_e_mn, r_e_mn, r_e_mx, add, l_e_;
	node () {
		l_e = r_e = add = 0;
		l_e_mx = l_e_mn = r_e_mn = r_e_mx = ans = 1;
	}
};

inline void push (int v, int sz) {
	if (t[v].add == 0)
		return;
	t[v].l_e += t[v].add;
	t[v].r_e += t[v].add;
	if (sz > 1) {
		t[v + v].add += t[v].add;
		t[v + v + 1].add += t[v].add;
	}
}



inline void upd (int v, int Tl, int Tr, int l, int r, int add) {
	push (v, Tr - Tl + 1);
	if (Tl > r || Tr < l)
		return;
	if (l <= Tl && Tr <= r) {
		t[v].add += add;
		push (v, Tr - Tl + 1);
		return;
	}
	
	/*
	3 cases
	1 -> left side
	*/
	
	int mid = (Tl + Tr) / 2;
	upd (v + v, Tl, mid, l, r, add);
	upd (v + v + 1, mid + 1, Tr, l, r, add);
	t[v].ans = max (t[v + v].ans, t[v + v + 1].ans);
	if (t[v + v].r_e > t[v + v + 1].l_e)
		t[v].ans = max (t[v].ans, t[v + v].r_e_mn + t[v + v
	else

	t[v].l_e = t[v + v].l_e;
	t[v].r_e = t[v + v + 1].r_e;
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		upd (1, 1, n, i, i, a[i]);
	}


	cin >> m;

	while (m--) {
	
	}
	
	return 0;
}
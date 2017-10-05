#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

struct node {
	ll sum;
	node *x;
	node *l, *r;
	node () {
		l = r = x = 0;
		sum = 0;
	}
};


inline void upd2 (node *t, int Tl, int Tr, int x, int val) {
	if (Tl > x || Tr < x)
		return;
	if (Tl == x && Tr == x) {
		t -> sum += val;
		return;
	}
	int mid = (Tl + Tr) / 2;
	if (!t -> l)
		t -> l = new node (), t -> r = new node ();
	upd2 (t -> l, Tl, mid, x, val);
	upd2 (t -> r, mid + 1, Tr, x, val);
	t -> sum = t -> l -> sum + t -> r -> sum;
}

inline void upd1 (node *t, int Tl, int Tr, int x, int y, int val) {
	if (Tl > x || Tr < x)
		return;
	upd2 (t -> x, 1, n, y, val);
	if (Tl == Tr)
		return;
	int mid = (Tl + Tr) / 2;
	upd1 (t -> l, Tl, mid, x, y, val), upd1 (t -> r, mid + 1, Tr, x, y, val);
}

inline ll get2 (node *t, int Tl, int Tr, int sx, int fx) {
	if (!t)
		return 0;
	if (Tl > fx || Tr < sx)
		return 0;
	if (sx <= Tl && Tr <= fx)
		return t -> sum;
	int mid = (Tl + Tr) / 2;
	return get2 (t -> l, Tl, mid, sx, fx) + get2 (t -> r, mid + 1, Tr, sx, fx);
}

inline ll get1 (node *t, int Tl, int Tr, int sx, int fx, int sy, int fy) {
	if (Tl > fx || Tr < sx)
		return 0;
	if (sx <= Tl && Tr <= fx)
		return get2 (t -> x, 1, n, sy, fy);
	int mid = (Tl + Tr) / 2;
	return get1 (t -> l, Tl, mid, sx, fx, sy, fy) + get1 (t -> r, mid + 1, Tr, sx, fx, sy, fy);
}



inline node* Build (int Tl, int Tr) {
	if (Tl == Tr)
		return new node ();
	int mid = (Tl + Tr) / 2;
	return new node (Build (Tl, mid), Build (mid + 1, Tr));
}

inline void add (int x) {
	auto x0 = s[a[x]].lower_bound (x);
	auto x2 = x0;
	--x0;
	upd2 (rootmn, 1, n, x + 1, *x2, x);
	upd2 (rootmn, 1, n, *x0 + 1, x, x);
	upd2 (rootmn, 1, n, *x0 + 1, *x2, -x);
	upd2 (rootmn, 1, n, x, x + 1, -x);
}

set <int> s[N];

inline void del (int x) {

}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> m;

	node *rootmn = Build (1, n);	
	node *rootmx = Build (1, n);
		
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		s[i].insert (0);
		s[i].insert (n + 1);
	}
	
	for (int i = 1; i <= n; ++i) {
		add (i);
	}
	
	while (m--) {
		int qtype;
		cin >> qtype;
		if (qtype == 1) {
			int p, x;
			cin >> p >> x;
			del (p);
			a[p] = x;
			add (p);
		} else {
		    int l, r;
		    cin >> l >> r;
		    cout << get1 (rootmx, 1, n, 1, l, 1, r);
		}
	}
	
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 100;


struct node {
	int x;
	node *l, *r;
	node () {
		x = 0;
		l = r = 0;
	}
	node (int xx) {
		x = xx;
		l = r = 0;	
	}
	node (node *Tl, node *Tr) {
		l = Tl;
		r = Tr;
		x = Tl -> x + Tr -> x;
	}
};

inline node* Build (int Tl, int Tr) {
	if (Tl == Tr)
		return new node ();
	int mid = (Tl + Tr) / 2;
	return new node (Build (Tl, mid), Build (mid + 1, Tr));
}

inline node* upd (node *t, int Tl, int Tr, int x) {
	if (Tl > x || Tr < x)
		return t;
	if (Tl == x && Tr == x)
		return new node ((t -> x) + 1);
	int mid = (Tl + Tr) / 2;
	return new node (upd (t -> l, Tl, mid, x), upd (t -> r, mid + 1, Tr, x));
}

inline int get (node *t, node *t2, int Tl, int Tr, int l, int r) {
	if (Tl > r || Tr < l)
		return 0;
	if (l <= Tl && Tr <= r)
		return t -> x - t2 -> x;
	int mid = (Tl + Tr) / 2;
	return get (t -> l, t2 -> l, Tl, mid, l, r) + get (t -> r, t2 -> r, mid + 1, Tr, l, r);
}


node *root[N];
int a[N], b[N];
int n, q;

inline int get_subrect (int sx, int sy, int fx, int fy) {
	if (sx > fx || sy > fy)
		return 0;
	return get (root[fx], root[sx - 1], 1, n, sy, fy);
}


main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> q;

	root[0] = Build (1, n);
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		b[a[i]] = i;
	}
	
	for (int i = 1; i <= n; ++i)
		root[i] = upd (root[i - 1], 1, n, b[i]);
	
	
	for (int i = 1; i <= q; ++i) {
		int sx, fx, sy, fy;
		cin >> sy >> sx >> fy >> fx;
		int one = get_subrect (1, 1, sx - 1, sy - 1);
		int two = get_subrect (1, sy, sx - 1, fy);
		int three = get_subrect (1, fy + 1, sx - 1, n);
		
		int four = get_subrect (sx, 1, fx, sy - 1);
		int five = get_subrect (sx, sy, fx, fy);
		int six = get_subrect (sx, fy + 1, fx, n);
	
		int seven = get_subrect (fx + 1, 1, n, sy - 1);
		int eight = get_subrect (fx + 1, sy, n, fy);
		int nine = get_subrect (fx + 1, fy + 1, n, n);
	
		ll ans = 0;
		
		ans += one * 1ll * five;
		ans += one * 1ll * six;
		ans += one * 1ll * eight;
		ans += one * 1ll * nine;
		ans += two * 1ll * four;
		ans += two * 1ll * five;
		ans += two * 1ll * six;
		ans += two * 1ll * seven;
		ans += two * 1ll * eight;
		ans += two * 1ll * nine;

		ans += three * 1ll * four;
		ans += three * 1ll * five;
		ans += three * 1ll * seven;
		ans += three * 1ll * eight;

		ans += four * 1ll * five;
		ans += four * 1ll * six;
		ans += four * 1ll * eight;
		ans += four * 1ll * nine;

		ans += five * 1ll * (five - 1) / 2;
		ans += five * 1ll * six;
		ans += five * 1ll * seven;
		ans += five * 1ll * eight;
		ans += five * 1ll * nine;

		ans += six * 1ll * seven;
		ans += six * 1ll * eight;

		
		//cerr << one << " " << two << " " << three << "\n" << four << " " << five << " " << six << "\n" << seven << " " << eight << " " << nine << "\n";
		
		cout << ans << '\n';
	}
	
	return 0;
}
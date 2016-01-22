#include <bits/stdc++.h>

using namespace std;

struct node {
	int x;
	node *l, *r;
	node () {
		x = 0;
		l = r = 0;
	}
	node (const int &el) {
		x = el;
		l = r = 0;
	}
	node (node *Tl, node *Tr) {
		l = Tl;
		r = Tr;
		x = Tl -> x + Tr -> x;
	}
};

const int N = 1e5 + 100;

node *root[N];

inline node * Build (const int &Tl, const int &Tr) {
	if (Tl == Tr)
		return new node ();
	int mid = (Tr + Tl) >> 1;
	return new node (Build (Tl, mid), Build (mid + 1, Tr));
}

inline node * upd (node *root, const int &Tl, const int &Tr, const int &x, const int &delta) {
	if (Tl > x || Tr < x)
		return root;
	if (Tl == x && Tr == x)
		return new node (root -> x + delta);

	int mid = (Tr + Tl) >> 1;
	return new node (upd (root -> l, Tl, mid, x, delta), upd (root -> r, mid + 1, Tr, x, delta));
}

inline int get (node *root, const int &Tl, const int &Tr, const int &l, const int &r) {
	if (Tl > r || Tr < l)
		return 0;
	if (l <= Tl && Tr <= r)
		return root -> x;
	int mid = (Tr + Tl) >> 1;
	return get (root -> l, Tl, mid, l, r) + get (root -> r, mid + 1, Tr, l, r);
}

vector <int> g[N], g2[N];
int d[N], d2[N];


int main () {

	freopen ("k-decomposition.in", "r", stdin);
	freopen ("k-decomposition.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int n, m;
	
	cin >> n >> m;

	for (int i = 1; i <= m; ++i) {
		int l, r;
		cin >> l >> r;
		++l, ++r;
		g[l].emplace_back (r);
		g2[r].emplace_back (l);
	}

	for (int i = 1; i <= n; ++i) {
		d[i] = g[i].size ();
		d2[i] = g2[i].size ();
		d[i] += d[i - 1];
		d2[i] += d2[i - 1];
	}
	
	root[n + 1] = Build (1, n);

	for (int i = n; i >= 1; --i) {
		root[i] = upd (root[i + 1], 1, n, 1, 0);
		for (auto it : g[i])
			root[i] = upd (root[i], 1, n, it, 1);
	}

	for (int k = 1; k <= n; ++k) {
		int ans = 0;
		for (int l = 1; l <= n; ++l) {
			int r = l + k - 1;
			r = min (n, r);
			
			ans += max (0, d[r] - d[l]);
			ans += max (0, d2[r - 1] - d2[l - 1]);
			
			ans -= get (root[l + 1], 1, n, l + 1, r - 1);
			
			//cerr << l << " " << r << " " << max (0, d[r] - d[l]) << " " << max (0, d2[r - 1] - d2[l - 1]) << " " << get (root[l + 1], 1, n, l + 1, r - 1) << "\n";
			
			l = r;
		}
	
		cout << ans << "\n";
	}
	
	return 0;
}
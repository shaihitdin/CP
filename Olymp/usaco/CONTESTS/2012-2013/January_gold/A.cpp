#include <bits/stdc++.h>

using namespace std;

map <int, int> el;

struct node {
	int sum;
	node *l, *r;
	
	node () {
		sum = 0;
		l = r = 0;
	}
	node (const int &x) {
		sum = x;
		l = r = 0;
	}
	node (node *ll, node *rr) {
		sum = ll -> sum + rr -> sum;
		l = ll;
		r = rr;
	}
};

const int sz = 1 << 17;

int a[sz], n, k;

vector <int> g[sz];
node * root[sz];

inline node *  build (const int &Tl, const int &Tr) {
	if (Tl == Tr)
		return new node (g[a[Tl]][0] == Tl);
	int mid = (Tl + Tr) >> 1;
	return new node (build (Tl, mid), build (mid + 1, Tr));
}

inline node * upd (node *o_root, const int &x, const int &to, const int &Tl, const int &Tr) {
	if (Tl > x || Tr < x)
		return o_root;
	if (Tl == x && Tr == x)
		return new node (to);
	int mid = (Tl + Tr) >> 1;
	return new node (upd (o_root -> l, x, to, Tl, mid), upd (o_root -> r, x, to, mid + 1, Tr));
}

inline int get (node *root, const int &l, const int &r, const int &Tl, const int &Tr) {
	if (Tl > r || Tr < l)
		return 0;
	if (l <= Tl && Tr <= r)
		return root -> sum;
	int mid = (Tl + Tr) >> 1;
	return get (root -> l, l, r, Tl, mid) + get (root -> r, l, r, mid + 1, Tr);
}

int main () {

	freopen ("lineup.in", "r", stdin);
	freopen ("lineup.out", "w", stdout);

	scanf ("%d%d", &n, &k);

	int cnt (0);

	for (int i = 1; i <= n; ++i) {
		int x;
		scanf ("%d", &x);
		if (!el.count (x))
			el[x] = ++cnt;
		a[i] = el[x];
	}

	g[0].push_back (-1);

	for (int i = 1; i <= n; ++i)
		g[a[i]].push_back (i);

	root[1] = build (0, sz - 1);

	for (int i = 2; i <= n; ++i) {
		root[i] = upd (root[i - 1], i - 1, 0, 0, sz - 1);
		auto it = upper_bound (g[a[i - 1]].begin (), g[a[i - 1]].end (), i - 1);
		if (it != g[a[i - 1]].end ())
			root[i] = upd (root[i], *it, 1, 0, sz - 1);
	}

	int ans = 0;

	for (int i = 1; i <= cnt; ++i) {
		for (int l = 0, r = 0; r < g[i].size (); ++r) {
			while (get (root[g[i][l]], g[i][l], g[i][r], 0, sz - 1) - 1 > k)
				++l;
			ans = max (ans, r - l + 1);
		}
	}

	printf ("%d", ans);

	return 0;
}
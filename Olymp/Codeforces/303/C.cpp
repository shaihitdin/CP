#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100, sz = 1 << 30;

int x[N], h[N];
int n, d[N];

struct node {
	node *l, *r;
	int mx;
	node () {
		l = r = 0;
		mx = 0;
	}
};

inline void upd (node *root, const int &Tl, const int &Tr, const int &x, const int &val) {
	if (Tl > x || Tr < x)
		return;
	if (Tl == x && Tr == x) {
		root -> mx = max (root -> mx, val);
		return;
	}	
	int mid = (Tl + Tr) >> 1;
	if (!root -> l)
		root -> l = new node (), root -> r = new node ();
	upd (root -> l, Tl, mid, x, val);
	upd (root -> r, mid + 1, Tr, x, val);
	root -> mx = max (root -> l -> mx, root -> r -> mx);
}

inline int get (node *root, const int &Tl, const int &Tr, const int &r) {
	if (!root)
		return 0;
	if (Tl > r)
		return 0;
	if (Tr <= r)
		return root -> mx;
	int mid = (Tl + Tr) >> 1;
	return max (get (root -> l, Tl, mid, r), get (root -> r, mid + 1, Tr, r));
}

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> x[i] >> h[i];
	

	node *root = new node (), *root1 = new node ();
	int ans = 0;

	for (int i = 1; i <= n; ++i) {
		d[i] = d[i - 1];
		int temp = get (root, 0, sz - 1, x[i] - h[i] - 1), temp1 = get (root1, 0, sz - 1, x[i] - h[i] - 1);
		upd (root, 0, sz - 1, x[i], max (d[i], temp + 1));
		d[i] = max (d[i], max (temp1, temp + 1));		
		upd (root1, 0, sz - 1, x[i] + h[i], d[i]);
		ans = max (ans, d[i] + 1);
	}
	
	cout << ans;

	return 0;
}

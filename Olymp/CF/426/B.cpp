#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 35050, K = 52;

struct node {
	int sum;
	node *l, *r;
	
	node (const int &x) {
		l = r = 0;
		sum = x;
	}

	node (node *lhs, node *rhs) {
		l = lhs;
		r = rhs;
		sum = lhs -> sum + rhs -> sum;
	}

};


inline int MID (const int &l, const int &r) {
	return (r + l) >> 1;
}

inline int get (node *t, const int &Tl, const int &Tr, const int &l, const int &r) {
	if (Tr < l || Tl > r)
		return 0;
	if (l <= Tl && Tr <= r)
		return t -> sum;
	int mid = MID (Tl, Tr);
	return get (t -> l, Tl, mid, l, r) + get (t -> r, mid + 1, Tr, l, r);
}

inline node * upd (node *o_root, const int &l, const int &r, const int &x, const int &to) {
	if (l == r)
		return new node (to);
	int mid = MID (l, r);
	if (x <= mid)
		return new node (upd (o_root -> l, l, mid, x, to), o_root -> r);
	else
		return new node (o_root -> l, upd (o_root -> r, mid + 1, r, x, to));
}

inline node * Build (const int &l, const int &r) {
	if (l == r)
		return new node (0);
	int mid = MID (l, r);
	return new node (Build (l, mid), Build (mid + 1, r));
}

int pre[N], nxt[N];
node* root[N];
int n, k, a[N];

inline void find_opt (int d_prev[], int d[], int opt[], int l, int r, int opt_l, int opt_r) {
	if (l > r)
		return;
	int mid = (r + l) / 2;
	for (int i = opt_l; i <= min (mid - 1, opt_r); ++i) {
		int val = get (root[mid], 1, n, i + 1, n);
		if (d[mid] < d_prev[i] + val) {
			opt[mid] = i;
			d[mid] = d_prev[i] + val;
		}			
	}
	if (l == r) {
		return;
	}
	find_opt (d_prev, d, opt, l, mid - 1, opt_l, opt[mid]);
	find_opt (d_prev, d, opt, mid + 1, r, opt[mid], opt_r);
}

int d[N][K], opt[N][K];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	root[0] = Build (1, n);
	
	for (int i = 1; i <= n; ++i) {
		root[i] = upd (root[i - 1], 1, n, i, 1);
		if (pre[a[i]])
			root[i] = upd (root[i], 1, n, pre[a[i]], 0);
		nxt[pre[a[i]]] = i;
		pre[a[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		if (!nxt[i])
			nxt[i] = n + 1;
	}
	
	for (int i = 1; i <= n; ++i) {
		d[i][1] = get (root[i], 1, n, 1, i);
		opt[i][1] = 0;
	}
	/*
	for (int i = 2; i <= k; ++i) {
		find_opt (d[i - 1], d[i], opt[i], i, n, 1, n);
	}
	*/
	
	
	
	
	for (int i = 1; i <= n; ++i) {
		opt[i][k + 1] = i - 1;
		for (int j = k; j >= 1; --j) {
			int val = get (root[i], 1, n, opt[i - 1][j] + 1, n);
			for (int it = opt[i - 1][j]; it <= opt[i][j + 1]; ++it) {
				if (d[i][j] < d[it][j - 1] + val) {
					d[i][j] = d[it][j - 1] + val;
					opt[i][j] = it;
				}
				if (nxt[it + 1] > i)
					--val;
			}
		}
	}
	cout << d[n][k];
	
	return 0;
}
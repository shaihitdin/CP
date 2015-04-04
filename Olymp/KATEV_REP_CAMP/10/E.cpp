#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 1, sz1 = 1 << 17;
int a[sz1], n, m;

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
	if (l <= x && x <= mid)
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

node *roots[N];

vector <int> v[N];
int sz[N];
int cnt[N];
long long ans;

int main () {
	freopen ("gazmyas.in", "r", stdin);
	freopen ("gazmyas.out", "w", stdout);
	
	ios_base :: sync_with_stdio (0);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	roots[0] = Build (0, sz1 - 1);
	
	for (int i = 1; i <= n; ++i) {
		if (!(a[i] & 1))
			++cnt[a[i]];
		roots[i] = upd (roots[i - 1], 0, sz1 - 1, a[i], cnt[a[i]]);
	}
	int last = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] & 1)
			last = i;
		else
			ans += get (roots[last], 0, sz1 - 1, a[i], N);
	}
	cout << ans;	
	return 0;
}

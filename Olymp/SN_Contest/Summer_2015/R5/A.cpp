#include <bits/stdc++.h>

using namespace std;

const int sz = 1 << 17, N = 1e5 + 100;

struct node {
	int x, add;
};

node t[sz + sz];

inline void push (const int &v, const int &sz) {
	if (t[v].add == 0)
		return;
	t[v].x += sz * t[v].add;
	if (v < sz) {
		t[v + v].add += t[v].add;
		t[(v + v) | 1].add += t[v].add;
	}
	t[v].add = 0;
}

inline int get (const int &v, const int &Tl, const int &Tr, const int &l, const int &r) {
	if (Tl > r || Tr < l)
		return 0;
	push (v, Tr - Tl + 1);
	if (l <= Tl && Tr <= r) {
		return t[v].x;
	}
	int mid = (Tl + Tr) >> 1;
	return get (v + v, Tl, mid, l, r) + get ((v + v) | 1, mid + 1, Tr, l, r);
}

inline void upd (const int &v, const int &Tl, const int &Tr, const int &l, const int &r, const int &val) {
	if (Tl > r || Tr < l)
		return;
	if (l <= Tl && Tr <= r) {
		t[v].add += val;
		push (v, Tr - Tl + 1);
		return;
	}
	int mid = (Tl + Tr) >> 1;
	upd (v + v, Tl, mid, l, r, val);
	upd ((v + v) | 1, mid + 1, Tr, l, r, val);
	t[v].x = t[(v + v) | 1].x + t[v + v].x;
}

inline int cnt (const int &l, const int &r, const int &x) {
	return r / x - ((l - 1) / x);
}

int add[N], delta[N], d[N], a[N], q_type[N], c[N];
int n, m;

inline int get (const int &l, const int &r) {
	return d[r] - d[l - 1];
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	scanf ("%d", &n);

	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &a[i]);
	}

	scanf ("%d", &m);

	int MAGIC = 1000;
	int lst = 0;

	for (int i = 1; i <= n; ++i)
		d[i] = (d[i - 1] + a[i]);

	for (int i = 1; i <= m; ++i) {
		scanf ("%d", &q_type[i]);
		if (q_type[i] == 1) {
			int l, r, x;
			scanf ("%d%d%d", &l, &r, &x);
			upd (1, 0, sz - 1, l, r, x);
		} else if (q_type[i] == 2) {
			scanf ("%d%d", &delta[i], &c[i]);
		} else {
			int l, r;
			scanf ("%d%d", &l, &r);
			int ans = get (l, r) + get (1, 0, sz - 1, l, r);
			for (int j = lst + 1; j < i; ++j)
				if (q_type[j] == 2)
					ans += c[j] * cnt (l, r, delta[j]);
			printf ("%d\n", ans);
			fflush (stdout);
		}

		if (lst + MAGIC == i) {
			memset (add, 0, sizeof (add));
			for (int j = lst + 1; j <= i; ++j)
				if (q_type[j] == 2)
					add[delta[j]] += c[j];
			for (int j = 1; j <= n; ++j)
				if (add[j])
					for (int k = j; k <= n; k += j)
						a[k] += add[j];
			for (int j = 1; j <= n; ++j)
				d[j] = (d[j - 1] + a[j]);
			lst = i;
		}
		
	}
	
	return 0;
}
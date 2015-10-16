#include <bits/stdc++.h>

using namespace std;

const int sz = 1 << 19, N = 3e5 + 100;

int t[sz + sz];

inline void push (const int &v) {
	if (v >= sz)
		return;
	if (!t[v])
		return;
	t[v + v] = t[v + v + 1] = t[v];
	t[v] = 0;
}

inline void upd (const int &v, const int &Tl, const int &Tr, const int &l, const int &r, const int &x) {
	if (Tl > r || Tr < l)
		return;
	push (v);
	if (l <= Tl && Tr <= r) {
		t[v] = x;
		push (v);
		return;
	}
	int mid = (Tl + Tr) >> 1;
	upd (v + v, Tl, mid, l, r, x);
	upd (v + v + 1, mid + 1, Tr, l, r, x);
}

int l[N], r[N], x[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int n, m;
	scanf ("%d%d", &n, &m);

	for (int i = 1; i <= m; ++i)
		scanf ("%d%d%d", &l[i], &r[i], &x[i]);
	
	for (int i = m; i >= 1; --i) {
		if (l[i] == x[i]) {
			upd (1, 0, sz - 1, l[i] + 1, r[i], x[i]);
		} else if (r[i] == x[i]) {
			upd (1, 0, sz - 1, l[i], r[i] - 1, x[i]);
		} else {
			upd (1, 0, sz - 1, l[i], x[i] - 1, x[i]);
			upd (1, 0, sz - 1, x[i] + 1, r[i], x[i]);
		}
	}
	
	for (int i = 1; i <= sz; ++i)
		push (i);
	
	for (int i = 1; i <= n; ++i) {
		cout << t[i + sz] << " ";
	}
	
	return 0;
}
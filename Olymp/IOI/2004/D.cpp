#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 100, inf = 1e9, sz = 1 << 21;

int t[sz + sz];


inline int get (int l, int r) {
	int res = inf;
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l & 1)
			res = min (res, t[l++]);
		if (!(r & 1))
			res = min (res, t[r--]);
		if (l > r)
			break;
	}
	return res;
}

inline void upd (int pos, const int &val) {
	for (pos += sz, t[pos] = val, pos >>= 1; pos; pos >>= 1)
		t[pos] = min (t[pos << 1], t[(pos << 1) | 1]);
}

vector <int> v[N];
int a[N], n;
int l[N], r[N], st[N], enq;
vector <int> ansl, ansr;

int main () {
	
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	scanf ("%d", &n);

	for (int i = 1; i <= n; ++i) {
		int x;
		scanf ("%d", &x);
		a[x + 1] = i;
	}
	st[enq = 0] = 0;

	for (int i = 1; i <= n; ++i) {
		while (enq && a[st[enq]] < a[i])
			--enq;
		l[i] = st[enq] + 1;
		st[++enq] = i;
	}
	
	st[enq = 0] = n + 1;
	
	for (int i = n; i; --i) {
		while (enq && a[st[enq]] > a[i])
			--enq;
		r[i] = st[enq] - 1;
		st[++enq] = i;
	}
	
	for (int i = 1; i <= n; ++i)
		v[l[i]].push_back (i);
	
	for (int i = 1; i <= n; ++i)
		upd (i, inf);
	
	for (int i = n; i; --i) {
		int temp = get (i + 1, r[i]);
		if (temp != inf) {
			ansl.push_back (i);
			ansr.push_back (temp);
			int cl;
			while ((cl = get (i + 1, n)) != inf)
				upd (cl, inf);
		}
		upd (i, i);
		for (auto it : v[i])
			upd (it, inf);
	}
		
	reverse (ansl.begin (), ansl.end ());
	reverse (ansr.begin (), ansr.end ());
	
	printf ("%d\n", ansl.size ());
	for (int i = 0; i < ansl.size (); ++i)
		printf ("%d %d\n", ansl[i], ansr[i]);

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 100, sz = 1 << 19;

vector <int> gx[N], gy[N], g[N];
int st[N], stq, enq;
int d[N];
int t[sz + sz + 100];
int sx[N], sy[N], fx[N], fy[N];
int n;
vector <int> cc;

inline int f (int x, int y) {
	if (x == y)
		return x;
	if (x == -2 || y == -2) {
		if (x == -2)
			return y;
		else
			return x;
	}
	return -1;
}

inline void push (int v, int sz) {
	if (sz == 1)
		return;
	if (t[v] != -1)
		t[v + v] = t[v + v + 1] = t[v];
}

inline int get (int v, int Tl, int Tr, int l, int r) {
	if (Tl > r || Tr < l)
		return -2;
	push (v, Tr - Tl + 1);
	if (l <= Tl && Tr <= r)
		return t[v];
	int mid = (Tl + Tr) >> 1;
	return f (get (v + v, Tl, mid, l, r), get (v + v + 1, mid + 1, Tr, l, r));
}

inline void upd (int v, int Tl, int Tr, int l, int r, int val) {
	if (Tl > r || Tr < l)
		return;
	push (v, Tr - Tl + 1);
	if (l <= Tl && Tr <= r) {
		t[v] = val;
		push (v, Tr - Tl + 1);
		return;
	}
	int mid = (Tl + Tr) >> 1;
	upd (v + v, Tl, mid, l, r, val);
	upd (v + v + 1, mid + 1, Tr, l, r, val);
	t[v] = f (t[v + v], t[v + v + 1]);
}


int main () {

	freopen ("roofs.in", "r", stdin);
	freopen ("roofs.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0), cout.tie (0);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> sx[i] >> sy[i] >> fx[i] >> fy[i];
		--fx[i], --fy[i];
		cc.emplace_back (sx[i]);
		cc.emplace_back (sy[i]);
		cc.emplace_back (fx[i]);
		cc.emplace_back (fy[i]);
	}
	
	sort (cc.begin (), cc.end ());
	cc.resize (unique (cc.begin (), cc.end ()) - cc.begin ());

	for (int i = 1; i <= n; ++i) {
		sx[i] = lower_bound (cc.begin (), cc.end (), sx[i]) - cc.begin ();
		fx[i] = lower_bound (cc.begin (), cc.end (), fx[i]) - cc.begin ();
		sy[i] = lower_bound (cc.begin (), cc.end (), sy[i]) - cc.begin ();
		fy[i] = lower_bound (cc.begin (), cc.end (), fy[i]) - cc.begin ();
		gx[sx[i]].emplace_back (i);
		gy[sy[i]].emplace_back (i);
	}	
	
	upd (1, 1, sz, 1, sz, 0);
	
	for (int i = 0; i < cc.size (); ++i) {
		for (auto v : gy[i]) {
			int from = sx[v], to = fx[v];
			while (from <= to) {
				int with = get (1, 1, sz, from, from);
				int l = from, r = to + 1;
				while (r - l > 1) {
					int mid = (r + l) >> 1;
					if (get (1, 1, sz, from, mid) == with)
						l = mid;
					else
						r = mid;
				}
				g[min (with, v)].emplace_back (max (v, with));
				upd (1, 1, sz, from, l, v);
				from = l + 1;
			}
		}
	}

	upd (1, 1, sz, 1, sz, 0);
	
	for (int i = 0; i < cc.size (); ++i) {
		for (auto v : gx[i]) {
			int from = sy[v], to = fy[v];
			while (from <= to) {
				int with = get (1, 1, sz, from, from);
				int l = from, r = to + 1;
				while (r - l > 1) {
					int mid = (r + l) >> 1;
					if (get (1, 1, sz, from, mid) == with)
						l = mid;
					else
						r = mid;
				}
				g[min (with, v)].emplace_back (max (v, with));
				upd (1, 1, sz, from, l, v);
				from = l + 1;
			}
		}
	}
	
	
	for (int i = n; i >= 1; --i) {
		for (auto to : g[i]) {
			g[to].emplace_back (i);
		}
	}
	
	st[enq++] = 1;
	d[1] = 1;

	while (stq < enq) {
		int v = st[stq++];
		for (auto to : g[v]) {
			if (!d[to]) {
				d[to] = d[v] + 1;
				st[enq++] = to;
			}
		}
	}
	
	cout << d[n] - 1;


	return 0;
}
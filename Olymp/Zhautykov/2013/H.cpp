#include <iostream>
#include <stdio.h>
using namespace std;
const int N = (3e5) + 1, t_N = (1 << 20);
int sz;
struct tree {
	int mx[t_N], st[t_N], to[t_N];
} t;
inline void push (const int &v, const int &Tl, const int &Tr) {
	if (t.st[v] != 0) {
		if (v < sz) {
			int mid = (Tr + Tl) >> 1;
			if (t.st[(v << 1)] == 0 || (t.to[(v << 1)] + (Tl - t.st[(v << 1)]) < t.to[v] + (Tl - t.st[v]))) {
				t.st[(v << 1)] = t.st[v];
				t.to[(v << 1)] = t.to[v];
			}
			if (t.st[(v << 1) + 1] == 0 || (t.to[(v << 1) + 1] + ((mid + 1) - t.st[(v << 1) + 1]) < t.to[v] + ((mid + 1) - t.st[v]))) {
				t.st[(v << 1) + 1] = t.st[v];
				t.to[(v << 1) + 1] = t.to[v];
			}
		}
		else 
			t.mx[v] = max (t.mx[v], (Tl - t.st[v]) + t.to[v]);
		t.st[v] = 0;
		t.to[v] = 0;
	}
}
inline void upd (const int &v, const int &Tl, const int &Tr, const int &x, const int &l, const int &r) {
	if (Tr < l || r < Tl)
		return;
	push (v, Tl, Tr);
	if (l <= Tl && Tr <= r) {
		t.st[v] = l;
		t.to[v] = x;
		push (v, Tl, Tr);
		return;
	}
	int mid = (Tr + Tl) >> 1;
	upd ((v << 1), Tl, mid, x, l, r);
	upd ((v << 1) + 1, mid + 1, Tr, x, l, r);
}
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	int n, m;
	scanf ("%d%d", &n, &m);
	sz = (1 << 19);
	for (int i = 1; i <= m; ++i) {
		int l, r, x;
		scanf ("%d%d%d", &l, &r, &x);
		upd (1, 0, sz - 1, x, l, r);
	}
	for (int i = 1; i <= n; ++i)
		upd (1, 0, sz - 1, -100, i, i); 
	for (int i = 1; i <= n; ++i)
		printf ("%d ", t.mx[i + sz]);
	return 0;
}
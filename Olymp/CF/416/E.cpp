#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

int a[N];

struct qq {
	int l, r, i;
}
struct save {
	int *x, y;
}

inline int make_eq (int) {

}

inline void add_q (int v, int Tl, int Tr, int l, int r, int id) {
	if (Tl > r || Tr < l)
		return;
	int mid = (Tl + Tr) / 2;
	if (l <= mid && mid < r) {
		query[v].push_back ({l, r, id});
		return;
	}
	add_q (v + v, Tl, mid, l, r, id);
	add_q (v + v + 1, mid + 1, Tr, l, r, id);
}

inline bool cmp (const qq &a, const qq &b) {
	return a.r < b.r;
}

inline int get_p (int v) {
	if (p[v] == v)
		return v;
	return p[v] = get_p (p[v]);
}

inline void Merge (int a, int b) {
	a = get_p (a), b = get_p (b);
	if (a == b)
		return;
	if (lvl[a] < lvl[b])
		swap (a, b);
	p[b] = a;
	if (lvl[a] == lvl[b])
		++lvl[a];
}

inline void CLEAR (int Tl, int Tr) {
	
}

inline void rec (int v, int Tl, int Tr) {
	if (Tl != Tr) {
		int mid = (Tl + Tr) / 2;
		rec (v + v, Tl, mid);
		rec (v + v + 1, mid + 1, Tr);
	}
	if (Tl == Tr) {
		for (int i = 1; i <= n; ++i) {
			
		}
	}
	for (int i = Tl; i <= mid; ++i) {
	
	}
	for (int 
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> m >> q;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	
	for (int i = 1; i <= q; ++i) {
		cin >> l[i] >> r[i];
		add_q (1, 1, m, l[i], r[i], i);
	}
	
	for (int i = 0; i <= 1e6; ++i)
		p[i] = i;
	
	rec (1, 1, m);
	
	
	return 0;
}
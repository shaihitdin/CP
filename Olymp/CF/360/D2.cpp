/// Stupido del problemo

#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);
  
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

const int oo = 1e9, bpr = 1e9 + 7, N = 2050, sz = 1 << 20;

int t[sz + sz + 100];
int p[N], len[N];

inline int get_pos2 (int v, int Tl, int Tr) {
	if (Tl == Tr)
		return Tl;
	int mid = (Tl + Tr) >> 1;
	if (t[v] == t[v + v])
		return get_pos2 (v + v, Tl, mid);
	return get_pos2 (v + v + 1, mid + 1, Tr);
}

inline int get_mx (int v, int Tl, int Tr, int l, int r) {
	if (Tl > r || Tr < l)
		return -1;
	if (l <= Tl && Tr <= r)
		return t[v];
	int mid = (Tl + Tr) >> 1;
	return max (get_mx (v + v, Tl, mid, l, r), get_mx (v + v + 1, mid + 1, Tr, l, r));
}

inline int get_pos (int v, int Tl, int Tr, int l, int r, int mx) {
	if (Tl > r || Tr < l)
		return -1;
	if (l <= Tl && Tr <= r) {
		if (t[v] == mx)
			return get_pos2 (v, Tl, Tr);
		else
			return -1;
	}
	int mid = (Tl + Tr) >> 1;
	return max (get_pos (v + v, Tl, mid, l, r, mx), get_pos (v + v + 1, mid + 1, Tr, l, r, mx));
}

inline void upd (int v, int Tl, int Tr, int x, int delta) {
	if (Tl > x || Tr < x)
		return;
	if (Tl == Tr) {
		t[v] = delta;
		return;
	}
	int mid = (Tl + Tr) >> 1;
	upd (v + v, Tl, mid, x, delta), upd (v + v + 1, mid + 1, Tr, x, delta);
	t[v] = max (t[v + v], t[v + v + 1]);
}

inline int get_p (int v) {
	return p[v] = ((p[v] == v) ? v : get_p (p[v]));
}

inline bool Merge (int a, int b) {
	a = get_p (a), b = get_p (b);
	if (a == b)
		return 0;
	if (len[a] < len[b])
		swap (a, b);
	p[b] = a;
	if (len[a] == len[b])
		++len[a];
	return 1;
}

int u[sz + 100], v[sz + 100], w[sz + 100];
int n, m, q;

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n >> m >> q;

	for (int i = 1; i <= m; ++i) {
		cin >> u[i] >> v[i] >> w[i];
		upd (1, 1, m, i, w[i]);
	}
	
	while (q--) {
		int l, r;
		cin >> l >> r;
		for (int i = 1; i <= 2 * (n + 10); ++i)
			p[i] = i, len[i] = 0;
		vector <int> ids;
		ids.clear ();
		for (int it = 1; it <= r - l + 1; ++it) {
			int val = get_mx (1, 1, m, l, r);
			if (val == -1)
				break;
			int id = get_pos (1, 1, m, l, r, val);
			if (!Merge (u[id] * 2, v[id] * 2 + 1) || !Merge (u[id] * 2 + 1, v[id] * 2))
				break;
			upd (1, 1, m, id, -1);
			ids.eb (id);
		}
		cout << get_mx (1, 1, m, l, r) << "\n";
		for (auto id : ids)
			upd (1, 1, m, id, w[id]);
	}
	
	return 0;
}
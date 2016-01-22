#include <bits/stdc++.h>

using namespace std;

const int sz = (1 << 17);

map <int, int> Map[sz + sz + 100];

int n, m;
int l[sz], r[sz];
int cnt_, cnt[sz];

inline void add (const int &v, const int &Tl, const int &Tr, const int &l, const int &r, const int &x, const int &y) {
	if (Tl > r || Tr < l)
		return;
	if (l <= Tl && Tr <= r) {
		Map[v][x] = y;
		return;
	}
	int mid = (Tl + Tr) >> 1;
	add (v + v, Tl, mid, l, r, x, y);
	add (v + v + 1, mid + 1, Tr, l, r, x, y);
}

inline void del (const int &v, const int &Tl, const int &Tr, const int &l, const int &r, const int &x) {
	if (Tl > r || Tr < l)
		return;
	if (l <= Tl && Tr <= r) {
		Map[v].erase (x);
		return;
	}
	int mid = (Tl + Tr) >> 1;
	del (v + v, Tl, mid, l, r, x);
	del (v + v + 1, mid + 1, Tr, l, r, x);
}

inline pair <int, int> get (const int &v, const int &Tl, const int &Tr, const int &x) {
	if (Tl == x && Tr == x) {
		if (Map[v].size ())
			return *Map[v].rbegin ();
		else
			return make_pair (-1, -1);
	}
	int mid = (Tl + Tr) >> 1;
	pair <int, int> res = make_pair (-1, -1);
	if (Map[v].size ())
		res = *Map[v].rbegin ();
	if (x <= mid)
		return max (res, get (v + v, Tl, mid, x));
	else
		return max (res, get (v + v + 1, mid + 1, Tr, x));
}

int main () {

	freopen ("stacks.in", "r", stdin);
	freopen ("stacks.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> m;

	for (int i = 1; i <= m; ++i) {
		char q_type;
		cin >> q_type;
		if (q_type == 'A') {
			int x;
			cnt[++cnt_] = i;
			cin >> l[i] >> r[i] >> x;
			add (1, 1, sz, l[i], r[i], i, x);
		} else if (q_type == 'G') {
			int x;
			cin >> x;
			cout << get (1, 1, sz, x).second << "\n";
		} else {
			int x;
			cin >> x;
			x = cnt[x];
			del (1, 1, sz, l[x], r[x], x);
		}
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 100, sz = (1 << 18);

struct node {
	ll sum_cap, sum, new_c;
	node () {
		new_c = -1;
		sum_cap = 0;
		sum = 0;
	}
	node (node l, node r) {
		sum_cap = l.sum_cap + r.sum_cap;
		sum = l.sum + r.sum;
		new_c = -1;
	}
} t[sz + sz + 100];

inline void push (int v) {
	if (t[v].new_c == -1)
		return;                 
	t[v].sum = t[v].new_c * t[v].sum_cap;
	if (v + v + 1 <= sz + sz)
		t[v + v].new_c = t[v + v + 1].new_c = t[v].new_c;
	t[v].new_c = -1;
}


inline void upd (int v, int Tl, int Tr, int l, int r, int x) {
	push (v);
	if (Tl > r || Tr < l)
		return;
	if (l <= Tl && Tr <= r) {
		t[v].new_c = x;
		push (v);
		return;
	}
	int mid = (Tl + Tr) / 2;
	upd (v + v, Tl, mid, l, r, x);
	upd (v + v + 1, mid + 1, Tr, l, r, x);
	t[v] = node (t[v + v], t[v + v + 1]);	
}


inline void upd_eq (int v, int Tl, int Tr, int ps, ll x) {
	push (v);
	if (Tl > ps || Tr < ps)
		return;
	if (Tl == Tr) {
		t[v].sum_cap = x;
		return;
	}
	int mid = (Tl + Tr) / 2;
	upd_eq (v + v, Tl, mid, ps, x);
	upd_eq (v + v + 1, mid + 1, Tr, ps, x);
	t[v] = node (t[v + v], t[v + v + 1]);

}

inline void upd (int v, int Tl, int Tr, int ps, ll &x) {
	push (v);
	if (Tl > ps || Tr < ps)
		return;
	if (Tl == Tr) {
		x = -x;
		ll need = min (t[v].sum_cap, x);
		ll cost = t[v].sum / t[v].sum_cap;
		t[v].sum_cap -= need;
		x -= need;
		x = -x;
		t[v].sum = t[v].sum_cap * cost;
		return;
	}
	int mid = (Tl + Tr) / 2;
	upd (v + v, Tl, mid, ps, x);
	upd (v + v + 1, mid + 1, Tr, ps, x);
	t[v] = node (t[v + v], t[v + v + 1]);
}


inline ll get (int v, int Tl, int Tr, int l, int r) {
	push (v);
	if (Tl > r || Tr < l)
		return 0;
	if (l <= Tl && Tr <= r) {
		return t[v].sum;
	}
	int mid = (Tl + Tr) / 2;
	return get (v + v, Tl, mid, l, r) + get (v + v + 1, mid + 1, Tr, l, r);
}

ll w[N], g[N], p[N];
int sx[N], fx[N];
ll ans[N];
vector <int> to_answer[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n, q;

	cin >> n >> q;

	for (int i = 1; i < n; ++i)
		cin >> w[i];
	w[n] = 1e18;		
	for (int i = 1; i <= n; ++i)
		cin >> g[i] >> p[i];
	

	for (int i = 1; i <= q; ++i) {
		cin >> sx[i] >> fx[i];
		to_answer[sx[i]].emplace_back (i);
	}
	
	int st[N], sz = 0;
	int side[N];
	for (int i = n; i >= 1; --i) {
		while (sz && p[i] < p[st[sz]]) --sz;
		if (!sz)
			side[i] = n;
		else
			side[i] = st[sz] - 1;
		st[++sz] = i;
	}
	
	for (int i = n; i >= 1; --i) {		
		upd_eq (1, 1, n, i, w[i]);
		upd (1, 1, n, i, side[i], p[i]);
		ll val = -g[i];
		while (val != 0) {
			int l = i - 1, r = n;
			while (r - l > 1) {
				int mid = (r + l) / 2;
				if (get (1, 1, n, 1, mid) == 0)
					l = mid;
				else
					r = mid;				
			}
			upd (1, 1, n, r, val);
		}

		for (auto id : to_answer[i]) {
			ans[id] = get (1, 1, n, i, fx[id] - 1);
		}
	}
	
	for (int i = 1; i <= q; ++i) {
		cout << ans[i] << "\n";
	}
	
	return 0;
}
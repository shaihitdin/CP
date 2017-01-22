#include <bits/stdc++.h>

using namespace std;

const int bpr = 1e9 + 21, sz = 1 << 20;

pair <int, int> t[sz + sz + 100];
int a[sz], x[sz], y[sz], val[sz];
vector <int> cc;
vector <pair <int, int> > qs[sz];
pair <int, int> part[sz];
int addq[sz];

inline void add (int &x, const int &y) {
	x += y;
	if (x >= bpr)
		x -= bpr;
}

inline void M (pair <int, int> &x, const pair <int, int> &y) {
	if (x.first == y.first)
		add (x.second, y.second);
	else if (x.first < y.first)
		x = y;
}

inline void upd (int x, const pair <int, int> &val) {
	M (t[x += sz], val);
	while (x >>= 1)
		M (t[x] = t[x + x], t[x + x + 1]);
}

inline void CL () {
	for (int i = 0; i < sz + sz + 100; ++i)
		t[i] = make_pair (0, 0);
}

inline pair <int, int> get (int l, int r) {
	pair <int, int> res = make_pair (0, 1);
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l & 1)	M (res, t[l++]);
		if (!(r & 1)) M (res, t[r--]);
		if (l > r) break;
	}
	return res;
}

bool important[sz];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif
/*
	ios_base :: sync_with_stdio (0);
	cin.tie (0);
*/
	int n, m;
	
	scanf ("%d%d", &n, &m);

	cc.resize (n + m);
	
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &a[i]);
		cc[i - 1] = a[i];
	}
	for (int i = 1; i <= m; ++i) {
		scanf ("%d%d", &x[i], &y[i]);
		cc[n + i - 1] = y[i];
	}
	
	sort (cc.begin (), cc.end ()), cc.resize (unique (cc.begin (), cc.end ()) - cc.begin ());
	
	for (int i = 1; i <= n; ++i)
		a[i] = lower_bound (cc.begin (), cc.end (), a[i]) - cc.begin () + 1;
	for (int i = 1; i <= m; ++i)
		y[i] = lower_bound (cc.begin (), cc.end (), y[i]) - cc.begin () + 1;
		
	for (int i = 1; i <= m; ++i)
		qs[x[i]].emplace_back (make_pair (y[i], i));
	
	int mx_val = -1;
	
	for (int i = 1; i <= n; ++i) {
		for (auto lk : qs[i])
			val[lk.second] = get (1, lk.first - 1).first;
		auto x = get (1, a[i] - 1);
		mx_val = max (mx_val, x.first + 1);
		upd (a[i], make_pair (x.first + 1, x.second));
		part[i] = x;
	}
	
	int cnt = t[1].second;

	CL ();

	for (int i = n; i; --i) {
		for (auto lk : qs[i])
			val[lk.second] += get (lk.first + 1, n + m).first;
		auto x = get (a[i] + 1, n + m);
		upd (a[i], make_pair (x.first + 1, x.second));
		important[i] = (mx_val == x.first + 1 + part[i].first && cnt == (part[i].second * 1ll * x.second) % bpr);
	}
	
	for (int i = 1; i <= m; ++i) {
		if (val[i] == mx_val)
			addq[i] = 1;
		else if (val[i] <= mx_val - 2 && important[x[i]])
			addq[i] = -1;
	}
		
	for (int i = 1; i <= m; ++i)
		printf ("%d\n", mx_val + addq[i]);
	
	return 0;
}
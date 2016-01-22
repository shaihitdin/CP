#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e5 + 1000, sz = 1 << 18;
const ll oo = 1e16;

struct node {
	ll mx, as1, as2;
	node () {
		mx = as1 = as2 = -oo;
	}
	node (node Tl, node Tr) {
		mx = as1 = as2 = -oo;
		mx = max (mx, Tl.mx);
		mx = max (mx, Tr.mx);
		mx = max (mx, Tl.as1 + Tr.as2);
		as1 = max (as1, max (Tl.as1, Tr.as1));
		as2 = max (as2, max (Tl.as2, Tr.as2));
	}
};

node t[sz + sz + 100];
ll sum[N];
int d[N], h[N];

inline void upd (int x, ll delta1, ll delta2) {
	t[x += sz].mx = -oo;
	t[x].as1 = delta1;
	t[x].as2 = delta2;
	while (x >>= 1)
		t[x] = node (t[x + x], t[x + x + 1]);
}

inline node get (int l, int r) {
	vector <node> res, resa;
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l & 1)
			res.emplace_back (t[l++]);
		if (!(r & 1))
			resa.emplace_back (t[r--]);
		if (l > r)
			break;
	}
	reverse (resa.begin (), resa.end ());
	for (auto it : resa)
		res.emplace_back (it);
	//reverse (res.begin (), res.end ());
	node ans;
	ans = node ();
	for (auto it : res)
		ans = node (ans, it);
	/*
	for (auto it : res) {
		cerr << it.as1 << " " << it.as2 << " " << it.mx << "\n"; 
	}
	*/
	return ans;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int n, m;
	
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		cin >> d[i];
	}
	
	for (int i = 1; i <= n; ++i) {
		cin >> h[i];
	}
	
	for (int i = 1; i <= n + 1; ++i)
		sum[i] = sum[i - 1] + d[i - 1];

	for (int i = n + 2; i <= n + n; ++i)
		sum[i] = sum[i - 1] + d[i - 1 - n];
	
	for (int i = 1; i <= n; ++i)
		upd (i, -sum[i] + 2 * h[i], sum[i] + 2 * h[i]);
	
	for (int i = n + 1; i <= n + n; ++i)
		upd (i, -sum[i] + 2 * h[i - n], sum[i] + 2 * h[i - n]);
	/*	
	for (int i = 1; i <= n; ++i) {
		cerr << i << " " << -sum[i] + 2 * h[i] << " " << sum[i] + 2 * h[i] << "\n";
	}	
	for (int i = n + 1; i <= n + n; ++i) {
		cerr << i << " " << -sum[i] + 2 * h[i - n] << " " << sum[i] + 2 * h[i - n] << "\n";
	}
	
	cerr << "\n\n\n";
	*/
	for (int i = 1; i <= m; ++i) {
		int l, r;
		cin >> l >> r;
		if (l <= r) {
			//cerr << r + 1 << " " << n + l - 1 << "\n";
			cout << get (r + 1, n + l - 1).mx << "\n";
		} else {
			cout << get (r + 1, l - 1).mx << "\n";
		}
	}
	
	return 0;
}
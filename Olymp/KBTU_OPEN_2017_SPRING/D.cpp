#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct query {
	int l, r, id;
};

const int N = 1e4 + 100, block = 9901;

int a[N * 100];
ll t1[N + 1], t2[N + 1];
ll res[N];
ll ans = 0;

inline bool operator < (const query &a, const query &b) {
	if (a.l / block == b.l / block)
		return a.r < b.r;
	return a.l < b.l;
}


inline void upd (ll t[], int x, int delta) {
	for (int i = x; i <= N; i |= (i + 1))
		t[i] += delta;
}

inline ll get (ll t[], int r) {
	ll res = 0;
	for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
		res += t[i];
	}
	return res;
}


inline ll get (ll t[], int l, int r) {
	return get (t, r) - get (t, l - 1);
}

inline void add (int x) {
	x = a[x];
	ll sum_bigger = get (t1, x);
	upd (t1, x, x);
	ans += sum_bigger;
	ans += x * (get (t2, x + 1, N) + 1);
	upd (t2, x, +1);
}

inline void del (int x) {
	x = a[x];
	ll sum_bigger = get (t1, x) - x;
	upd (t1, x, -x);
	ans -= sum_bigger;
	ans -= (get (t2, x + 1, N) + 1) * x;
	upd (t2, x, -1);
}


int main () {

	freopen ("fate.in", "r", stdin);
	freopen ("fate.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
		
	int n, m;
	scanf ("%d%d", &n, &m);

	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);
	vector <query> q;
	for (int i = 1; i <= m; ++i) {
		int l, r;
		scanf ("%d%d", &l, &r);
		q.push_back ({l, r, i});
	}
	sort (q.begin (), q.end ());

	int l = 1, r = 1;
	add (1);

	for (int i = 0; i < q.size (); ++i) {
		while (r < q[i].r) add (++r);
		while (q[i].l < l) add (--l);
		while (r > q[i].r) del (r--);
		while (q[i].l > l) del (l++);
		res[q[i].id] = ans;
	}	

	for (int i = 1; i <= m; ++i)
		printf ("%lld\n", res[i]);
	
	return 0;
}
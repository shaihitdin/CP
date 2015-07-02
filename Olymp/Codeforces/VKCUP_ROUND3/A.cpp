#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 1;

typedef pair <int, int> pii;

#define mkp make_pair
#define F first
#define S second

vector <int> nst, nend, mst, mend;

int main () {

	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	scanf ("%d%d", &n, &m);

	for (int i = 1; i <= n; ++i) {
		scanf ("%d%d", &l[i], &r[i]);
		compress.insert (l[i]);
		compress.insert (r[i]);
	}
	
	for (int i = 1; i <= m; ++i) {
		scanf ("%d%d%d", &a[i], &b[i], &c[i]);
		compress.insert (a[i]);
		compress.insert (b[i]);
	}

	
	int tc = 0;

	for (auto it : compress) {
		cc[it] = ++tc;
		rc[tc] = it;
	}

	for (int i = 1; i <= n; ++i)
		l[i] = cc[l[i]], r[i] = cc[r[i]];
	for (int i = 1; i <= m; ++i)
		a[i] = cc[a[i]], b[i] = cc[b[i]];

	for (int i = 1; i <= n; ++i)
		nst[l[i]].push_back (i), nend[r[i]].push_back (i);
	for (int i = 1; i <= m; ++i)
		mst[a[i]].push_back (i), mend[b[i]].push_back (i);


	ll ans = 0, ans1, ans2;
	
	/// [l, b]

	multiset <int> ls;

	for (int i = 1; i <= tc; ++i) {
		for (int it : nst)
			ls.insert (i);
		for (int j : mend) {
			auto it = ls.lower_bound (a[j]);
			if (it != ls.end ()) {
				int el = *it;
				if (ans < (rc[i] - rc[el]) * 1ll * c[j]) {
					ans = (rc[i] - rc[el]) * 1ll * c[j];
					ans1 = nst[el][0];
					ans2 = j;
				}
			}
		}
		for (int it : nend)
			ls.erase (l.find (l[it]));
	}

	/// [a, r]

	multiset <int> rs;
	
	for (int i = tc; i; --i) {
		for (int it : nend)
			rs.insert (i);
		for (int j : mst) {
			auto it = rs.upper_bound (b[j]);
			if (it != rs.begin ()) {
				--it;
				int el = *it;
				if (ans < (rc[el] - rc[i]) * 1ll * c[j]) {
					ans = (rc[el] - rc[i]) * 1ll * c[j];
					ans1 = nend[el][0];
					ans2 = j;
				}
			}
		}
		for (int it : nst)
			rs.erase (r.find (r[it]));
	}
	
	/// [l, r]
	
	multiset <pii> as;
	
	for (int i = 1; i <= tc; ++i) {
		for (int it : mst)
			as.insert (mkp (i, it));
		for (int j : nend) {
			auto it = as.upper_bound (mkp (l[end], -1));
			if (it != as.begin ()) {
				--it;
				int el = *it.F;
				if (ans < (rc[r[j]] - rc[l[j]]) * 1ll * c[j]) {
					ans = (rc[r[j]] - rc[l[j]]) * 1ll * c[j];
					ans1 = j;
					ans2 = *it.S;
				}
			}
		}
		for (int it : mend)
			as.erase (mkp (a[it], it));
	}
	
	/// [a, b]

	multiset <pii> ls1;

	for (int i = 1; i <= tc; ++i) {
		for (int it : nst)
			ls1.insert (mkp (i, it));
		for (int j : 
	}

	
	return 0;
}
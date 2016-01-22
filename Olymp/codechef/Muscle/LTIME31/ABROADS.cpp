#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 100;

typedef long long ll;

ll sum[N], add[N];
int p[N];
int ban[N];
int del[N], ss[N];
int n, m, q;
int x[N], y[N];
ll ans[N];
char q_type[N];

inline int get_p (int x) {
	return p[x] = ((p[x] == x) ? x : get_p (p[x]));
}

multiset <ll> Set;

inline void Merge (int a, int b) {
	a = get_p (a), b = get_p (b);
	if (a == b)
		return;
	Set.erase (Set.find (sum[a]));
	p[a] = b;
	Set.erase (Set.find (sum[b]));
	sum[b] += sum[a];
	Set.insert (sum[b]);
}

vector <int> eq[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> m >> q;

	for (int i = 1; i <= n; ++i) {
		int ke;
		cin >> ke;
		eq[i].emplace_back (ke);
	}
	for (int i = 1; i <= m; ++i)
		cin >> x[i] >> y[i];
	
	for (int i = 1; i <= q; ++i) {
		cin >> q_type[i];
		if (q_type[i] == 'D') {
			cin >> del[i];
			ban[del[i]] = 1;
		} else {
			cin >> ss[i] >> add[i];
			eq[ss[i]].emplace_back (add[i]);
		}
	}

	for (int i = 1; i <= n; ++i) {
		p[i] = i, Set.insert (eq[i].back ());
		sum[i] = eq[i].back ();
	}
	for (int i = 1; i <= m; ++i)
		if (!ban[i])
			Merge (x[i], y[i]);

	for (int i = q; i >= 1; --i) {
		ans[i] = *Set.rbegin ();	
		if (q_type[i] == 'D') {
			Merge (x[del[i]], y[del[i]]);
		} else {
			int f = get_p (ss[i]);
			Set.erase (Set.find (sum[f]));
			sum[f] -= eq[ss[i]].back ();
			eq[ss[i]].pop_back ();
			sum[f] += eq[ss[i]].back ();
			Set.insert (sum[f]);
		}
	}
	
	for (int i = 1; i <= q; ++i) {
		cout << ans[i] << "\n";
	}

	return 0;
}
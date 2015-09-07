#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

#define prev can

int n;

ll k, a[N];

int prev[N], nxt[N];

set <pair <ll, int> > Set;

inline ll calc (const int &x, const int &y) {
	return a[x] + a[y] + (y - x) * 1ll * (y - x);
}

inline ll calc_p (const int &x) {
	return calc (prev[x], nxt[x]) - (calc (prev[x], x) + calc (x, nxt[x]) - a[x]);
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= n; ++i) {
		a[i] *= k;
		a[i] *= k;
	}
	nxt[n] = -1;
	ll bst = n;

	/*
	for (int i = n - 1; i; --i) {
		nxt[i] = bst;
		if (a[bst] + (bst - i) * (bst - i) > a[i] + 1)
			bst = i;
	}
	*/

	for (int i = 1; i < n; ++i)
		nxt[i] = i + 1;

	for (int i = nxt[1], lst = 1;; i = nxt[i]) {
		prev[i] = lst;
		if (i == n)
			break;
		Set.insert (make_pair (calc (lst, nxt[i]) - 
		(calc (lst, i) + calc (i, nxt[i]) - a[i]), i));
	}
	
	
	while (Set.size () > k - 2 || (Set.size () && Set.begin () -> first < 0)) {
		auto it = *Set.begin ();
		int i = it.second;
		Set.erase (Set.begin ());
		auto it1 = Set.find (make_pair (calc_p (prev[i]), prev[i])), it2 = Set.find (make_pair (calc_p (nxt[i]), nxt[i]));
		
		prev[nxt[i]] = prev[i];
		nxt[prev[i]] = nxt[i];
		if (it1 != Set.end ()) {
			Set.erase (it1);
			Set.insert (make_pair (calc_p (prev[i]), prev[i]));
		}
		if (it2 != Set.end ()) {
			Set.erase (it2);
			Set.insert (make_pair (calc_p (nxt[i]), nxt[i]));
		}
	}
	
	ll ans = 0;
	
	for (auto it : Set)
		ans += a[it.second] + (it.second - prev[it.second]) * 1ll * (it.second - prev[it.second]);
	
	ans += a[1];
	ans += a[n];
	ans += (n - prev[n]) * 1ll * (n - prev[n]);
	
	cout << ans;

	return 0;
}
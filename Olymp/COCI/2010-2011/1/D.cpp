#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

int n, m;
int a[N];
multiset <int> Set;


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	scanf ("%d%d", &m, &n);

	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);

	int l = -1, r = 2e9 + 1;

	while (r - l > 1) {
		int mid = (r + l) >> 1;
		ll sum = 0;
		for (int i = 1; i <= n; ++i) {
			int x = max (0, a[i] - mid);
			sum += x;
		}
		if (sum <= m)
			r = mid;
		else
			l = mid;
	}
	
	for (int i = 1; i <= n; ++i) {
		int x = max (0, a[i] - r);
		m -= x;
		a[i] -= x;
	}
	
	for (int i = 1; i <= n; ++i) {
		if (a[i] > 0)
			Set.insert (a[i]);
	}
	
	while (Set.size () && m) {
		int it = *Set.rbegin ();
		Set.erase (Set.find (it));
		--it;
		--m;
		if (it > 0)
			Set.insert (it);
	}
	
	ll sum = 0;

	
	while (Set.size ()) {
		int it = *Set.begin ();
		Set.erase (Set.begin ());
		sum += it * 1ll * it;
	}

	printf ("%lld", sum);
	
	return 0;
}
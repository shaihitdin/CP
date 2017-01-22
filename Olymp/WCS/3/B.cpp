#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9, N = 2e5 + 100;

set <pair <int, pair <int, int> > > Set;

int ans = oo, n, m;
int a[N], b[N];

inline void print () {
	if (ans == oo)
		cout << -1;
	else
		cout << ans;
	exit (0);
}

int main () {

	#ifdef UNBROKEN
	freopen ("in", "r", stdin);
	#endif

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= m; ++i)
		cin >> b[i];
			
	for (int i = 0; i <= n; ++i)
		Set.insert (make_pair (0, make_pair (i, 0)));
	
	while (Set.size ()) {
	
	}
		
	print ();
	
	return 0;
}
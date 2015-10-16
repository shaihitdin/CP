#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "ticket3."
#define pb push_back

const int N = 2e5;

int n, a[N];

int main () {
//	#ifdef LOCAL
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);
//	#endif

	cin >> n;

	int s = 0;
	for (int i = 1; i <= 2 * n; ++i) {
		cin >> a[i];
		s += a[i];
	}	

	int x = 0;
	
	for (int i = 1; i <= n; ++i)
		x += a[i];
	
	int y = 0;
	
	for (int i = 1; i <= 2 * n; i += 2)
		y += a[i];
	
	int z = 0;

	for (int i = 1; i <= 2 * n; ++i)
		if (a[i] & 1)
			z += a[i];	
	
	if (s - x == x || s - y == y || s - z == z)
		cout << "YES\n";
	else
		cout << "NO\n";	

	return 0;
}
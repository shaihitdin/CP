/// Stupido del problemo

#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);
  
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second
#define int ll

const int oo = 1e9, bpr = 1e9 + 7, N = 1e5 + 100;

int a[N], dpref[N], dsuff[N], d[N];

inline int get (int l, int r) {
	return d[r] - d[l - 1];
}

main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int t;

	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		for (int i = 1; i <= n; ++i)
			d[i] = d[i - 1] + a[i];
		d[n + 1] = d[n];
		for (int i = 1, j = 0; i <= n; ++i) {
			dpref[i] = d[i] - d[j];
			if (d[j] > d[i])
				j = i;
		}
		for (int i = n, j = n + 1; i; --i) {
			dsuff[i] = get (i, n) - get (j, n);
			if (get (j, n) > get (i, n))
				j = i;
		}
		int ans = -oo;
		for (int i = 1; i <= n; ++i)
			ans = max (ans, dpref[i]);
		for (int i = 2; i < n; ++i)
			ans = max (ans, dpref[i - 1] + dsuff[i + 1]);
		cout << ans << "\n";
	}

	return 0;
}
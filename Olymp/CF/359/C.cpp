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

const int oo = 1e9, bpr = 1e9 + 7, N = 1e5 + 100;

ll p[N][3];
int n;

inline ll calc (int dimension, ll x) {
	ll res = 0;
	for (int i = 1; i <= n; ++i)
		res = max (res, abs (p[i][dimension] - x));
	return res;
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int t;
	cin >> t;

	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i)
			for (int j = 0; j < 3; ++j)
				cin >> p[i][j];
		ll ans[5];
		for (int i = 0; i < 3; ++i) {
			ll l = -2e18, r = 2e18;
			while (r - l > 30) {
				ll mid1 = l + (r - l) / 3;
				ll mid2 = r - (r - l) / 3;
				if (calc (i, mid1) > calc (i, mid2))
					l = mid1;
				else
					r = mid2;
			}
			ans[i] = l;
			for (; l <= r; ++l)
				if (calc (i, l) < calc (i, ans[i]))
					ans[i] = l;
		}
		for (int i = 0; i < 3; ++i)
			cout << ans[i] << " ";
		cout << "\n";
	}
	
	return 0;
}
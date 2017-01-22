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

const int oo = 1e9, bpr = 1e9 + 7, N = 2e5 + 100, K = 220;

ll f[N], frev[N];
ll d[K][K];
ll catalan[N];

inline ll bin_pow (ll x, ll y) {
	if (!y)
		return 1;
	if (y & 1)
		return bin_pow (x, y - 1) * x % bpr;
	ll c = bin_pow (x, y / 2);
	return c * c % bpr;
}

inline ll cnk (ll n, ll k) {
	if (k > n)
		return 0;
	ll res = f[n];
	res = res * frev[k] % bpr;
	res = res * frev[n - k] % bpr;
	return res;
}

inline void add (ll &x, ll y) {
	x += y;
	if (x >= bpr)
		x -= bpr;
}


int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	for (int i = f[0] = 1; i < N; ++i)
		f[i] = f[i - 1] * i % bpr;
	for (int i = 0; i < N; ++i)
		frev[i] = bin_pow (f[i], bpr - 2);
	for (int i = 1; i < N / 2; ++i)
		catalan[i] = cnk (2 * i, i) * bin_pow (i + 1, bpr - 2) % bpr;

	d[0][0] = 1;

	for (int i = 1; i < K; ++i)
		for (int j = 1; j <= i; ++j)
			for (int k = 1; k <= i; ++k)
				add (d[i][k], d[i - j][k - 1] * catalan[j] % bpr);	
	
	int t;

	cin >> t;

	while (t--) {
		int t1, t2;
		cin >> t1 >> t2;
		ll ans = 0;
		for (int i = 1; i <= t2; ++i)
			add (ans, d[t2][i] * cnk (t1 + t1 + 1, i) % bpr);
		ans = ans * f[t1] % bpr;
		ans = ans * f[t2] % bpr;
		ans = ans * catalan[t1] % bpr;
		cout << ans << "\n";
	}

	return 0;
}
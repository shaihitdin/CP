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
#include <iomanip>

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
#define lw lower_bound

const int oo = 1e9, bpr = 1e9 + 7, N = 1e5 + 100;

int a[N], dp[N], p[N], n, sum[N];

inline int get (int l, int r) {
	if (l == 0)
		return sum[r];
	return sum[r] - sum[l - 1];
}


int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> a[i];
	a[n] = 2e9;

	for (int i = 0; i <= n; ++i)
		dp[i] = 1e9;
	
	dp[0] = 0;

	for (int i = 0; i < n; ++i) {
		dp[lw (a, a + n, a[i] + 90) - a] = min (dp[lw (a, a + n, a[i] + 90) - a], dp[i] + 50);
		dp[lw (a, a + n, a[i] + 1440) - a] = min (dp[lw (a, a + n, a[i] + 1440) - a], dp[i] + 120);
		dp[i + 1] = min (dp[i] + 20, dp[i + 1]);
	}
	
	for (int i = n; i > 0; --i)
		dp[i - 1] = min (dp[i - 1], dp[i]);
	
	int now = 0;

	for (int i = 0; i < n; ++i) {
		cout << dp[i + 1] - now << "\n";
		now = dp[i + 1];
	}

	return 0;
}
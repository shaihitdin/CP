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

int d[N];

inline int fcb (int x) {
	int y = cbrt (x);
	y -= 3;
	y = max (1ll, y);
	for (; y * y * y <= x; ++y);
	--y;
	return y;
}

inline int calc (int x) {
	if (x <= 1e5)
		return d[x];
	int d = fcb (x);
	return calc (x - d * d * d) + 1;
}

main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int n;

	cin >> n;

	pair <int, int> ans;

	for (int i = 1; i < N; ++i) {
		int z = fcb (i);
		d[i] = d[i - z * z * z] + 1;
	}
	
	for (int i = max (1ll, n - int(3e5)); i <= n; ++i)
		ans = max (ans, mp (calc (i), i));
	
	for (int i = 1; i * i * i <= n; ++i) {
		ans = max (ans, mp (calc (i * i * i - 1), i));
	}
	
	cout << ans.fe << " " << ans.se << "\n";

	return 0;
}
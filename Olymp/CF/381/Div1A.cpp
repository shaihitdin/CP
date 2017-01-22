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
#define int ll

const int oo = 1e18, bpr = 1e9 + 7, N = 2e5 + 100, sz = (1 << 19);

int a[N], l[N], r[N];

main() {

	#ifdef LOCAL
	freopen("in", "r", stdin);
	#endif

	srand(23523);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int n, m;
	cin >> n >> m;

	int ans = 1e9;
	
	for (int i = 1; i <= m; ++i) {
 		cin >> l[i] >> r[i];
		ans = min (ans, r[i] - l[i] + 1);
	}
	
	cout << ans << "\n";

	for (int i = 0; i < n; ++i) {
		cout << i % ans << " ";
	}

	return 0;
}
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

const int oo = 1e9, bpr = 1e9 + 7, N = -1;

int gcd (int a, int b) {
	return b ? gcd (b, a % b) : a;
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
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int g = gcd (c, d);
		int ans = abs ((a % g) - (b % g));
		ans = min (ans, min ((a % g), (b % g)) + (g - max ((a % g), (b % g))));
		cout << ans << "\n";
	}
	
	return 0;
}
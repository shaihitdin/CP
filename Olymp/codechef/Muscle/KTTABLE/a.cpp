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

const int oo = 1e9, bpr = 1e9 + 7, N = 1e4 + 100;

int n, a[N];

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
			cin >> a[i];
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			int x;
			cin >> x;
			ans += (a[i] - a[i - 1] >= x);
		}
		cout << ans << "\n";
	}
	
	return 0;
}
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

const int bpr = 1e9 + 7, N = 3010;
const ll oo = 1e18;

ll nx[N * 101], pre[N * 101];
int a[N], n;
set <int> Set;
vector <int> cc;

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
		
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		Set.insert (a[i]);
		for (int cnt = 0; cnt < 50; ++cnt) {
		int x = a[i] - cnt - 1;
		for (; Set.count (x); --x);
		Set.insert (x);
		x = a[i] + 1 + cnt;
		for (; Set.count (x); ++x);
		Set.insert (x);
		}
	}
	
	for (auto it : Set)
		cc.eb (it);
	
	for (int i = 1; i <= n; ++i)
		a[i] = lower_bound (cc.begin (), cc.end (), a[i]) - cc.begin ();
	
	for (int i = 0; i < cc.size (); ++i)
		nx[i] = abs (cc[i] - cc[a[1]]);
	
	for (int i = 2; i <= n; ++i) {
		memcpy (pre, nx, sizeof (nx));
		for (int j = 0; j < cc.size (); ++j)
			nx[j] = oo;
		ll mn = oo;
		for (int j = 0; j < cc.size (); ++j) {
			nx[j] = min (nx[j], mn + abs (cc[j] - cc[a[i]]));
			mn = min (mn, pre[j]);
		}
	}
	
	ll ans = oo;

	for (int i = 0; i < cc.size (); ++i)
		ans = min (ans, nx[i]);

	cout << ans;
	
	return 0;
}
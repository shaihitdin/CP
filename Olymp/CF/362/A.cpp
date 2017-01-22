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

const int oo = 1e9, bpr = 1e9 + 7, N = -1;

map <int, int> cost;

inline bool is_parent (int v, int u) { //is v parent of u?
	while (u > v)
		u >>= 1;
	return u == v;
}

main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int q;
	cin >> q;

	while (q--) {
		int q_type;
		cin >> q_type;
		if (q_type == 1) {
			int x, y, z;
			cin >> x >> y >> z;
			while (!is_parent (x, y)) {
				cost[x] += z;
				x >>= 1;
			}
			while (y != x) {
				cost[y] += z;
				y >>= 1;
			}
		} else {
			int x, y, res = 0;
			cin >> x >> y;
			while (!is_parent (x, y)) {
				res += cost[x];
				x >>= 1;
			}
			while (y != x) {
				res += cost[y];
				y >>= 1;
			}
			cout << res << "\n";
		}
	}
	
	return 0;
}
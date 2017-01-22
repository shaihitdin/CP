/// izizi

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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 0;
const ll sz = 1ll << 33;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

struct lulno {
	int type, x, y;
};

vector <lulno> cc;

inline pair <ll, ll> Rotate (pair <int, int> a) {
	return mp (a.fe - a.se, a.fe + a.se);
}

inline bool operator < (const lulno &a, const lulno &b) {
	return a.type < b.type;
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n >> m >> q;

	for (int i = 1; i <= q; ++i) {
		char f;
		int x, y;
		cin >> f >> x >> y;
		cc.pb ({f == 'B', x, y});
	}
	
	sort (cc.begin (), cc.end ());
	
	
	
	return 0;
}
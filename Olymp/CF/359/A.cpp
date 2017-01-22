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

const int oo = 1e9, bpr = 1e9 + 7, N = -1;

inline int cnt (int x) {
	if (x == 0)
		return 1;
	int val = 0;
	while (x) {
		x /= 7;
		++val;
	}
	return val;
}

inline bool bit (int mask, int pos) {
	return (mask >> pos) & 1;
}


int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int n, m;

	cin >> n >> m;
	
	int p1 = cnt (n - 1), p2 = cnt (m - 1);
	int ans = 0;

	for (int mask = 0; mask < (1 << 7); ++mask) {
		vector <int> cc;
		for (int i = 0; i < 7; ++i) {
			if (bit (mask, i))
				cc.eb (i);
		}
		if (cc.size () != p1 + p2)
			continue;
		for (;;) {
			ll t1 = 0, t2 = 0;
			for (int i = 0; i < p1; ++i)
				t1 = t1 * 7 + cc[i];
			for (int i = p1; i < p1 + p2; ++i)
				t2 = t2 * 7 + cc[i];
			if (t1 < n && t2 < m) {
				++ans;
			}
			if (!next_permutation (cc.begin (), cc.end ()))
				break;
		}
	}
	
	cout << ans;

	return 0;
}
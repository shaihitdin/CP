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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 5e4 + 100;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

int a[N], ans, n;

inline int gcd (int x, int y) {
	return y ? gcd (y, x % y) : x;
}

inline void check (int x) {
	int part2 = 0;
	for (int i = 1; i < n; ++i) {
		if (a[i] % x != 0)
			part2 = gcd (a[i], part2);
		if (ans > min ((part2 == 0) ? oo : part2, x))
			return;
	}
	if (part2 == 0) {
		part2 = a[n];
	} else {
		if (a[n] % x != 0)
			part2 = gcd (a[n], part2);
	}
	ans = max (ans, min (part2, x));
}


int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int test;
	
	cin >> test;

	while (test--) {
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		ans = 0;
		vector <int> cc;
		for (int i = 1; i * i <= a[1]; ++i) {
			if (a[1] % i == 0) {
				cc.eb (i);
				cc.eb (a[1] / i);
			}
		}
		sort (cc.begin (), cc.end ());
		reverse (cc.begin (), cc.end ());
		for (auto x : cc)
			check (x);
		cout << ans << '\n';
	}

	return 0;
}
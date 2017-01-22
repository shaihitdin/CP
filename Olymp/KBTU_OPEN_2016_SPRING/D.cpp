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

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

inline bool is_prime (int x) {
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0)
			return 0;
	if (x < 2)
		return 0;
	return 1;
}

inline int min_divisor (int x) {
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0)
			return i;
	return x;
}

int main() {
	freopen ("legend.in", "r", stdin);
	freopen ("legend.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int n;
	cin >> n;
	if (n <= 1e5) {
		int ans = -1, ansd = -1;
		for (int i = 4; i <= n; ++i) {
			if (!is_prime (i) && min_divisor (i) >= ansd) {
				ans = i, ansd = min_divisor (i);
			}
		}
		cout << ans;
		return 0;
	}
	if (n < 4) {
		cout << -1;
		return 0;
	}
	
	for (int x = sqrt (n) + 10; x >= 0; --x) {
		if (x * 1ll * x > n)
			continue;
		if (is_prime (x)) {
			for (int y = n / x;; --y) {
				if (is_prime (y)) {
					cout << x * y;
					return 0;
				}
			}
		}
	}
	
	cout << -1;
	return 0;
}
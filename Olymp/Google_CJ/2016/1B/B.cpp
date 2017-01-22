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
  
const int bpr = 1e9 + 7, N = 0;
const ll oo = 2e18;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

string a, b;
pair <ll, pair <int, int> > dp[20][4];
// 0 -> eq, 1 -> c first value is bigger, 2 -> j second value is bigger
ll pw10[20];

inline ll calc (int val, int i, int j) {
	int x = i - j;
	if (val == 2)
		x = -x;
	return x;
}

inline ll go (int ps, int val) {
	if (ps == a.size ())
		return 0;
	if (dp[ps][val].fe != -1) {
		return dp[ps][val].fe;
	}
	auto res = dp[ps][val];
	res.fe = oo;
	int pw = a.size () - 1 - ps;
	if (a[ps] == '?' && b[ps] == '?') {
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				if (val == 0) {
					if (i > j) {
						res = min (res, mp ((i - j) * pw10[pw] + go (ps + 1, 1), mp (i, j)));
					} else if (i == j) {
						res = min (res, mp (0 + go (ps + 1, 0), mp (i, j)));
					} else if (i < j) {
						res = min (res, mp ((j - i) * pw10[pw] + go (ps + 1, 2), mp (i, j)));
					}
				} else {
					res = min (res, mp (calc (val, i, j) * pw10[pw] + go (ps + 1, val), mp (i, j)));
				}
			}
		}
	} else if (a[ps] == '?') {
		for (int i = 0; i < 10; ++i) {
			int j = b[ps] - '0';
			if (val == 0) {
				if (i > j) {
					res = min (res, mp ((i - j) * pw10[pw] + go (ps + 1, 1), mp (i, j)));
				} else if (i == j) {
					res = min (res, mp (0 + go (ps + 1, 0), mp (i, j)));
				} else if (i < j) {
					res = min (res, mp ((j - i) * pw10[pw] + go (ps + 1, 2), mp (i, j)));
				}
			} else {
				res = min (res, mp (calc (val, i, j) * pw10[pw] + go (ps + 1, val), mp (i, j)));
			}
		}
	} else if (b[ps] == '?') {
		for (int j = 0; j < 10; ++j) {
			int i = a[ps] - '0';
			if (val == 0) {
				if (i > j) {
					res = min (res, mp ((i - j) * pw10[pw] + go (ps + 1, 1), mp (i, j)));
				} else if (i == j) {
					res = min (res, mp (0 + go (ps + 1, 0), mp (i, j)));
				} else if (i < j) {
					res = min (res, mp ((j - i) * pw10[pw] + go (ps + 1, 2), mp (i, j)));
				}
			} else {
				res = min (res, mp (calc (val, i, j) * pw10[pw] + go (ps + 1, val), mp (i, j)));
			}
		}
	} else {
		int i = a[ps] - '0', j = b[ps] - '0';
		if (val == 0) {
			if (i > j) {
				res = min (res, mp ((i - j) * pw10[pw] + go (ps + 1, 1), mp (i, j)));
			} else if (i == j) {
				res = min (res, mp (0 + go (ps + 1, 0), mp (i, j)));
			} else if (i < j) {
				res = min (res, mp ((j - i) * pw10[pw] + go (ps + 1, 2), mp (i, j)));
			}
		} else {
			res = min (res, mp (calc (val, i, j) * pw10[pw] + go (ps + 1, val), mp (i, j)));
		}
	}
	dp[ps][val] = res;
	return res.fe;
}

inline void go2 (int ps, int val) {
	if (ps == a.size ())
		return;
	a[ps] = dp[ps][val].se.fe + '0';
	b[ps] = dp[ps][val].se.se + '0';
	if (val == 0) {
		int c = int (a[ps] - '0') - (b[ps] - '0');
		if (c > 0)
			go2 (ps + 1, 1);
		else if (c == 0)
			go2 (ps + 1, 0);
		else
			go2 (ps + 1, 2);
	} else {
		go2 (ps + 1, val);
	}
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int test;

	for (int i = pw10[0] = 1; i <= 18; ++i)
		pw10[i] = pw10[i - 1] * 10;
	
	cin >> test;
	for (int test_num = 1; test_num <= test; ++test_num) {
		cout << "Case #" << test_num << ": ";
		cin >> a >> b;
		for (int i = 0; i < 20; ++i)
			for (int j = 0; j < 4; ++j)
				dp[i][j].fe = -1;
		go (0, 0);
		go2 (0, 0);
		cout << a << " " << b << "\n";
	}
	
	return 0;
}
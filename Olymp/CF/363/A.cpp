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

const int oo = 1e9, bpr = 1e9 + 7, N = -1;

inline bool bit (int mask, int pos) {
	return (mask >> pos) & 1;
}

int n, a[220];
int d[220][4];

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= 2; ++j)
			d[i][j] = oo;
	
	d[1][0] = !bit (a[1], 0);
	d[1][1] = !bit (a[1], 1);
	d[1][2] = 1;
	
	for (int i = 2; i <= n; ++i) {
		if (bit (a[i], 0))
			d[i][0] = min (d[i - 1][1], d[i - 1][2]);
		if (bit (a[i], 1))
			d[i][1] = min (d[i - 1][0], d[i - 1][2]);
		d[i][2] = min (d[i - 1][0], d[i - 1][1]);
		d[i][2] = min (d[i][2], d[i - 1][2]);
		++d[i][2];
	}
	
	int res = d[n][0];
	for (int i = 0; i <= 2; ++i)
		res = min (res, d[n][i]);
	
	cout << res;

	return 0;
}
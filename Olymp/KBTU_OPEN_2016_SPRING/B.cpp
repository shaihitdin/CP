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
  
const int oo = 1e9, bpr = 1e9 + 9, N = 5e5 + 100;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second
#define int ll

int n;
int f[N], frev[N];
int d[N];

inline int bin_pow (int x, int y) {
	if (!y)
		return 1;
	if (y & 1)
		return bin_pow (x, y - 1) * x % bpr;
	int c = bin_pow (x, y / 2);
	return c * c % bpr;
}

inline int cnk (int n, int k) {
	int res = f[n];
	res = res * frev[k] % bpr;
	res = res * frev[n - k] % bpr;
	return res;
}

main() {
	freopen ("spacey.in", "r", stdin);
	freopen ("spacey.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n;
/*
	for (int i = f[0] = 1; i < N; ++i)
		f[i] = f[i - 1] * i % bpr;
	for (int i = 0; i < N; ++i)
		frev[i] = bin_pow (f[i], bpr - 2);
*/	
	if (n & 1) {
		cout << 0;
		return 0;
	}
	
	int ans = bin_pow (3, n / 2);


	
	return 0;
}
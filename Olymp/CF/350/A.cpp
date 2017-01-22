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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 2e5 + 100;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

int cnt[10];

inline int calc (int n, int x) {
	memset (cnt, 0, sizeof (cnt));
	for (int i = 1; i <= n; ++i, x = (x + 1) % 7) {
		++cnt[x];
	}
	return cnt[6] + cnt[0];
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int n;

	cin >> n;
	
	int mx = 0, mn = 1e9;
	
	for (int i = 0; i < 7; ++i) {
		int val = calc (n, i);
		mx = max (mx, val);
		mn = min (mn, val);
	}
	
	cout << mn << " " << mx;
	
	return 0;
}
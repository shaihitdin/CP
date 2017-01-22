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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 5e5 + 100;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

ll sum[N];
int c[N];
int n, k;

inline ll find_r () {
	int l = c[1] - 1, r = bpr;
	while (r - l > 1) {
		int mid = (r + l) >> 1;
		int ps = upper_bound (c + 1, c + n + 1, mid) - c;
		ll val = (sum[n] - sum[ps - 1]) - mid * 1ll * (n - ps + 1);
		if (val <= k)
			r = mid;
		else
			l = mid;
	}
	return r;
}

inline ll find_l () {
	int l = 0, r = c[n] + 1;
	while (r - l > 1) {
		int mid = (r + l) >> 1;
		int ps = lower_bound (c + 1, c + n + 1, mid) - c - 1;
		ll val = mid * 1ll * ps - sum[ps];
		if (val <= k)
			l = mid;
		else
			r = mid;
	}
	return l;
}


int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	

	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
		cin >> c[i];
	
	sort (c + 1, c + n + 1);

	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + c[i];
	}
	
	sum[n + 1] = sum[n];
	
	int l = find_l (), r = find_r ();

	if (l >= r)
		cout << (sum[n] % n > 0);
	else
		cout << r - l;

	return 0;
}
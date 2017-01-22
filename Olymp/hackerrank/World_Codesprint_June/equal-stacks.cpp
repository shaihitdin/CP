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

const int oo = 1e9, bpr = 1e9 + 7, N = 1e5 + 100;

int n[4];
int sum[4];
int a[4][N];

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	for (int i = 1; i <= 3; ++i)
		cin >> n[i];

	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= n[i]; ++j) {
			cin >> a[i][j];
			sum[i] += a[i][j];
		}
		reverse (a[i] + 1, a[i] + n[i] + 1);
	}
	
	while (1) {
		int mn = sum[1], mx = sum[1];
		for (int i = 2; i <= 3; ++i) {
			mn = min (mn, sum[i]);
			mx = max (mx, sum[i]);
		}
		if (mn == mx) {
			cout << mn;
			return 0;
		}
		for (int i = 1; i <= 3; ++i) {
			if (sum[i] > mn) {
				sum[i] -= a[i][n[i]--];
			}
		}
	}
	
	return 0;
}
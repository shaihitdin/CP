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

const int oo = 1e9, bpr = 1e9 + 7, N = 22;

ld p[N];
ld d[(1 << 20) + 10];
int n, k;
ld ans[N];

inline bool bit (int mask, int pos) {
	return (mask >> pos) & 1;
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
		cin >> p[i];
	
	d[0] = 1;

	for (int i = 0; i < n; ++i)
		ans[i] = 1;
	
	
	cout << fixed;
	cout << setprecision (7);
	
	for (int i = 0; i < n; ++i)
		cout << ans[i] << " ";
	
	return 0;
}
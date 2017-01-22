/// Forever

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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 1e6 + 100;

#define mp make_pair

int f[N];

int main() {                                                             
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	

	int n, m;
	
	cin >> n >> m;

	f[0] = 1;

	for (int i = 1; i < N; ++i)
		f[i] = (f[i - 1] * 1ll * i) % bpr;
	
	int ans = 1;
	
	for (int i1 = 1, j1 = 1, i2 = 1, j2 = 1; !(i1 == n && j1 == m);) {
		int cnt = abs (i1 - i2) + 1;
		ans = (ans * 1ll * f[cnt]) % bpr;
		if (i2 != n)
			++i2;
		else
			++j2;
		if (j1 != m)
			++j1;
		else
			++i1;
	}
	
	cout << ans;
	
	return 0;
}
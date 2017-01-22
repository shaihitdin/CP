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

#define pii pair<int, int>
  
#define pb push_back
#define mp make_pair
  
#define f first
#define s second
  
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);
  
const int oo = 1e9, bpr = 1e9 + 7, N = 1e6 + 100;

int a[N], gotill[N], b[N];

inline void add (int &x, int y) {
	x += y;
	if (x >= bpr)
		x -= bpr;
	x += bpr;
	if (x >= bpr)
		x -= bpr;
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int n;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		--a[i];
	}

	int ans = 0;

	for (int i = 1; i <= n; ++i)
		add (ans, a[i]);
	
	for (int l = n; l >= 1; --l) {
		add (ans, (gotill[l] * 1ll * b[l]) % bpr);
		b[l - 1] = min (a[l - 1], a[l]);
		gotill[l - 1] = (b[l - 1] + gotill[l] * 1ll * min (b[l], b[l - 1])) % bpr;
	}

	cout << ans;
	
	return 0;
}
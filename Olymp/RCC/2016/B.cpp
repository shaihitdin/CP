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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 1e5 + 100;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

int a[N];
int u[N];
int t[N];

inline void upd (int x) {
	for (; x < N; x |= (x + 1))
		++t[x];
}

inline int get (int r) {
	int res = 0;
	for (; r >= 0; r &= (r + 1), --r)
		res += t[r];
	return res;
}

inline int get (int l, int r) {
	return get (r) - get (l - 1);
}

ll d[N];

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int test;

	cin >> test;

	while (test--) {
		int n, h;
		cin >> n >> h;

		memset (t, 0, sizeof (t));
		
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		
		for (int i = 1; i <= n; ++i)
			d[i] = d[i - 1] + a[i];
		
		for (int i = 1; i <= n; ++i) {
			cin >> u[i];
			if (u[i])
				upd (i);
		}		

		int ans = 0;
		
		if (!u[1])
			++ans, upd (1);
		
		for (int i = 1, j = 1; i <= n; ++i) {
			while (j < n && d[j] - d[i - 1] < h)
				++j;
			if (!get (i, j))
				++ans, upd (j);
		}
		cout << ans << "\n";
	}
	
	return 0;
}
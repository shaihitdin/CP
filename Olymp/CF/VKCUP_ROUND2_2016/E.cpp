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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 1e6 + 100, sz = 1 << 20;

#define mp make_pair

int T[sz + sz + 100];

inline void upd (int x, int delta) {
	T[x += sz] += delta;
	while (x >>= 1)
		T[x] = T[x + x] + T[x + x + 1];
}

inline int get (int l, int r) {
	int res = 0;
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l & 1)	res += T[l++];
		if (!(r & 1))	res += T[r--];
		if (l > r)	break;
	}
	return res;
}

int ans[N], t[N], a[N], x[N];
vector <int> cc, cc2, g[N];
int n;

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> t[i] >> x[i];
		cc.emplace_back (x[i]);
		cc2.emplace_back (t[i]);
	}
	
	sort (cc.begin (), cc.end ());
	sort (cc2.begin (), cc2.end ());
	
	cc.resize (unique (cc.begin (), cc.end ()) - cc.begin ());
	cc2.resize (unique (cc2.begin (), cc2.end ()) - cc2.begin ());
	
	for (int i = 1; i <= n; ++i) {
		x[i] = lower_bound (cc.begin (), cc.end (), x[i]) - cc.begin () + 1;
		t[i] = lower_bound (cc2.begin (), cc2.end (), t[i]) - cc2.begin () + 1;
		g[x[i]].emplace_back (i);
	}
	
	for (int i = 1; i <= cc.size (); ++i) {
		for (auto f : g[i]) {
			if (a[f] == 1) {
				upd (t[f], 1);
			} else if (a[f] == 2) {
				upd (t[f], -1);
			} else {
				ans[f] = get (0, t[f]);
			}
		}
		for (auto f : g[i]) {
			T[t[f] + sz] = 0;
			upd (t[f], 0);
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 3)
			cout << ans[i] << "\n";
	}
	
	return 0;
}
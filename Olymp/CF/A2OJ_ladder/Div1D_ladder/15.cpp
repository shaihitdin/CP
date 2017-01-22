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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 3e5 + 100;

#define mp make_pair

vector <int> gg[N], g[N];
ll ans[N];
ll d[N];
int n, m, a[N], b[N], p[N];

inline ll get (int l, int r) {
	if (l <= 0)
		return d[r];
	return d[r] - d[l];
}


int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> p[i];

	cin >> m;

	for (int i = 1; i <= m; ++i) {
		cin >> a[i] >> b[i];
		g[b[i]].emplace_back (i);
	}	
	
	for (int i = 1; i <= n; ++i) {
		vector <int> cc;
		for (auto it : g[i]) {
			cc.emplace_back (a[it] % i);
			gg[a[it] % i].emplace_back (it);
		}
		sort (cc.begin (), cc.end ());
		cc.resize (unique (cc.begin (), cc.end ()) - cc.begin ());
		for (auto x : cc) {
			d[x] = p[x];
			int lst = x;
			for (int j = x + i; j <= n; lst = j, j += i)
				d[j] = d[j - i] + p[j];
			for (auto bek : gg[x])
				ans[bek] = get (a[bek] - b[bek], lst);
			gg[x].clear ();
		}
	}
	
	for (int i = 1; i <= m; ++i)
		cout << ans[i] << "\n";
	
	return 0;
}
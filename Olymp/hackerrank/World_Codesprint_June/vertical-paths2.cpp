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

const int oo = 1e9, bpr = 1e9 + 7, N = 5e5 + 100;


struct path {
	int c, u, v;
};

inline bool operator < (const path &a, const path &b) {
	return a.c < b.c;
}

int p[N];
vector <pair <int, int> > g[N];
int lim[N], slim[N];

inline void dfs (int v, int pp = 0) {
	p[v] = pp;
	for (auto to : g[v]) {
		if (to.fe == pp) {
			lim[v] = to.se;
			continue;
		}
		dfs (to.fe, v);
	}
}

inline bool bit (int mask, int pos) {
	return (mask >> pos) & 1;
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
		
	int t;

	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i < n; ++i) {
			int a, b, d;
			cin >> a >> b >> d;
			g[a].eb (mp (b, d));
			g[b].eb (mp (a, d));
		}

		dfs (1);		
	
		vector <path> qs;
		
		for (int i = 1; i <= m; ++i) {
			int u, v, c;
			cin >> u >> v >> c;
			qs.pb ({c, u, v});
		}
		sort (qs.begin (), qs.end ());
		reverse (qs.begin (), qs.end ());

		ll ans = 0;
		for (int i = 1; i <= n; ++i)
			slim[i] = lim[i];
		
		for (auto it : qs) {
			bool can = 1;
			for (int x = it.v; x != it.u; x = p[x])
				can &= (lim[x] > 0);
			if (can) {
				for (int x = it.v; x != it.u; x = p[x])
					--lim[x];
				ans += it.c;
			}
		}
		
		if (m <= 20) {
			for (int mask = 0; mask < (1 << m); ++mask) {
				for (int i = 1; i <= n; ++i)
					lim[i] = slim[i];
				ll tmp = 0;
				for (int j = 0; j < m; ++j) {
					if (bit (mask, j)) {
						auto it = qs[j];
						for (int x = it.v; x != it.u; x = p[x])
							--lim[x];
						tmp += it.c;
					}
				}
				bool can = 1;
				for (int i = 1; i <= n; ++i)
					if (lim[i] < 0)
						can = 0;
				if (can)
					ans = max (ans, tmp);
			}
		}

		cout << ans << "\n";

		for (int i = 1; i <= n; ++i) {
			g[i].clear ();
		}
	}
	
	return 0;
}
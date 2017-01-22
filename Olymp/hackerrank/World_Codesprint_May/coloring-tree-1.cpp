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
int vv, cnt[N], a[N], d[N];
vector <int> g[N];
int n;

inline void dfs (int v, int pp) {
	if (cnt[a[v]]++ == 0)
		++vv;
	d[v] = vv;
	for (auto to : g[v]) {
		if (to == pp)
			continue;
		dfs (to, v);
	}
	if (--cnt[a[v]] == 0)
		--vv;
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	for (int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].eb (y);
		g[y].eb (x);
	}
	
	for (int i = 1; i <= n; ++i) {
		dfs (i, i);
		ll ans = 0;
		for (int j = 1; j <= n; ++j)
			ans += d[j];
		cout << ans << "\n";
	}
	
	return 0;
}
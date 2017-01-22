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

const int oo = 1e9, bpr = 1e9 + 7, N = 3e5 + 100;

int a[N], p[N], n;
bool u[N];
vector <int> g[N], top;

inline void dfs (int v, int pp) {
	if (u[v])
		return;
	p[v] = pp;
	u[v] = 1;
	for (auto to : g[v]) {
		if (!u[to])
			dfs (to, v);
	}
}

inline void topsort (int v) {
	if (u[v])
		return;
	u[v] = 1;
	for (auto to : g[v])
		topsort (to);
	top.eb (v);
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		//g[i].eb (a[i]);
		g[a[i]].eb (i);
	}
	
	for (int i = 1; i <= n; ++i)
		topsort (i);
	
	reverse (top.begin (), top.end ());

	memset (u, 0, sizeof (u));

	for (auto v : top)
		dfs (v, top[0]);
	
	int ans = 0;

	for (int i = 1; i <= n; ++i)
		ans += (p[i] != a[i]);

	cout << ans << "\n";

	for (int i = 1; i <= n; ++i)
		cout << p[i] << " ";

	return 0;
}
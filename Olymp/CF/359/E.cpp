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

const int oo = 1e9, bpr = 1e9 + 7, N = 2e5 + 100;

int n, m, q, x[N], y[N], l[N], r[N], s[N], t[N];
vector <int> g[N];
int d[1001][1001];
int ans[N];

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n >> m >> q;

	for (int i = 1; i <= m; ++i) {
		cin >> x[i] >> y[i];
	}
	
	for (int i = 1; i <= q; ++i) {
		cin >> l[i] >> r[i] >> s[i] >> t[i];
		g[r[i]].eb (i);
	}
	
	memset (d, -1, sizeof (d));

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j)
			d[j][j] = i;
		int mxc;
		for (int j = 1; j <= n; ++j) {
		    mxc = max (d[y[i]][j], d[x[i]][j]);
			d[y[i]][j] = d[x[i]][j] = mxc;
		}
		for (auto it : g[i]) {
			if (d[t[it]][s[it]] >= l[it])
				ans[it] = 1;
		}
	}
	
	for (int i = 1; i <= q; ++i) {
		if (ans[i])
			cout << "Yes\n";
		else
			cout << "No\n";
	}	

	return 0;
}
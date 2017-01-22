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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 1e5 + 100;

#define mp make_pair

vector <int> g[2][N];
bool u[N];
int n, m;

inline int solve (vector <int> a[N], vector <int> b[N]) {
	memset (u, 0, sizeof (u));
	vector <pair <int, int> > cc;
	for (int i = 1; i <= n; ++i)
		cc.emplace_back (mp (a[i].size (), i));
	sort (cc.begin (), cc.end ());
	reverse (cc.begin (), cc.end ());
	for (auto it : cc) {
		int v = it.second;
		bool flag[2];
		flag[0] = flag[1] = 0;
		for (int to : a[v])
			if (!u[to])
				flag[1] = 1;
			else
				flag[0] = 1;
		if (flag[1] && flag[0])
			return oo;
		for (int to : b[v]) {
			if (u[to]) {
				flag[1] = 1;
			} else {
				if (flag[1])
					u[to] = 1;
				else
					flag[0] = 1;
			}
		}
		if (flag[1] && flag[0])
			return oo;
		if (flag[1])
			u[v] = 1;
	}
	for (int v = 1; v <= n; ++v) {
		for (int to : a[v])
			if (u[to] && u[v])
				return oo;
			else if (!u[to] && !u[v])
				return oo;
		for (int to : b[v])
			if ((u[to] ^ u[v]) == 1)
				return oo;
	}
	int res = 0;
	for (int i = 1; i <= n; ++i)
		res += u[i];
	return res;
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n >> m;

	for (int i = 1; i <= m; ++i) {
		int x, y;
		char col;
		cin >> x >> y >> col;
		if (col == 'R')
			g[0][x].emplace_back (y), g[0][y].emplace_back (x);
		else
			g[1][x].emplace_back (y), g[1][y].emplace_back (x);
	}	
	
	int val[2];
	val[0] = solve (g[0], g[1]);
	val[1] = solve (g[1], g[0]);
	
	if (val[0] == oo && val[1] == oo) {
		cout << -1;
		return 0;
	}
	
	if (val[0] < val[1]) {
		cout << val[0] << "\n";
		solve (g[0], g[1]);
	} else {
		cout << val[1] << "\n";
		solve (g[1], g[0]);
	}
	
	for (int i = 1; i <= n; ++i)
		if (u[i])
			cout << i << " ";
	
	return 0;
}
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

bool u[N];
int c[N];
vector <int> g[N];
int n, m;

inline void dfs (int v, int col = 1) {
	u[v] = 1;
	c[v] = col;
	for (auto to : g[v]) {
		if (u[to]) {
			if (c[to] == c[v]) {
				cout << -1;
				exit (0);
			}
			continue;
		}
		dfs (to, col ^ 1);
	}
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
		cin >> x >> y;
		g[x].eb (y);
		g[y].eb (x);
	}
	
	for (int i = 1; i <= n; ++i)
		if (!u[i])
			dfs (i);
	
	vector <int> ans1, ans2;

	for (int i = 1; i <= n; ++i) {
		if (c[i])
			ans1.eb (i);
		else
			ans2.eb (i);
	}
	
	cout << ans1.size () << "\n";
	for (auto it : ans1)
		cout << it << " ";
	cout << "\n";
	cout << ans2.size () << "\n";
	for (auto it : ans2)
		cout << it << " ";	

	return 0;
}

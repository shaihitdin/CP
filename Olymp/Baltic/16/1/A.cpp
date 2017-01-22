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
  
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

const int bpr = 1e9 + 7, N = 5050;
const ll oo = 1e18;

vector <int> g[N], g2[N];
int st[N], stq, enq;
ll ans = oo;
int d[N], p[N];
ll res[N];
int n;

inline void dfs (int v) {
	for (auto to : g2[v]) {
		dfs (to);
		res[v] += res[to];
	}
	++res[v];
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		while (x--) {
			int y;
			cin >> y;
			g[y].eb (i);
		}
	}
	for (int i = 1; i <= n; ++i) {
		memset (d, 0, sizeof (d));
		d[i] = 1;
		stq = enq = 0;
		st[++enq] = i;
		while (stq != enq) {
			int v = st[++stq];
			for (auto to : g[v]) {
				if (!d[to]) {
					d[to] = d[v] + 1;
					p[to] = v;
					st[++enq] = to;
				}
			}
		}
		if (enq != n)
			continue;
		ll tx = 0;
		for (int j = enq; j; --j) {
			int v = st[j];
			res[v] = 0;
			for (auto to : g[v]) {
				if (p[to] == v && to != i) {
					res[v] += res[to];
				}
			}
			tx += ++res[v];
		}
		ans = min (ans, tx);
	}
	
	cout << ans;
	
	return 0;
}
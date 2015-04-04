#include <string.h>
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

const int N = 200020;

typedef long long ll;

vector <int> g[N];
bool point[N];
int tin[N], fup[N], timer;
int n, m, x, y;
vector <int> cnt[N];
int sz[N];
ll ans[N];

inline void dfs (const int &v, const int &p) {
	tin[v] = ++timer;
	fup[v] = timer;
	sz[v] = 1;
	int child = 0;
	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (to == p)
			continue;
		if (tin[to]) {
			fup[v] = min (fup[v], tin[to]);
		} else {
			dfs (to, v);
			++child;
			if (tin[v] <= fup[to]) {
				point[v] = 1;
				cnt[v].push_back (sz[to]);
			}
			fup[v] = min (fup[v], fup[to]);
			sz[v] += sz[to];
		}
	}
	if (p == -1) {
		if (child > 1)
			point[v] = 1;
		else
			point[v] = 0;
	}
	if (point[v]) {
		int was = 0;
		for (int i = 0; i < cnt[v].size(); ++i) {
			int it = cnt[v][i];
			ans[v] += ((1ll * (it)) * (1ll * (n - it - 1 - was)));
			was += it;
		}
	}
}

int main () {
	
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	ios_base :: sync_with_stdio (0);

	cin >> n >> m;

	for (int i = 1; i <= m; ++i) {
		cin >> x >> y;
		g[x].push_back (y);
		g[y].push_back (x);
	}

	dfs (1, -1);
	for (int i = 1; i <= n; ++i)
		ans[i] = (ans[i] + n - 1);
	
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << "\n";
	return 0;
}
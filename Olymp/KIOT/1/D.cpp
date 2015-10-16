#include <bits/stdc++.h>

using namespace std;

const int N = 400;

inline int get_p (const int &x) {
	return x == p[x] ? x : p[x] = get_p (p[x]);
}

inline void Merge (int a, int b) {
	a = get_p (a);
	b = get_p (b);
	if (sz[a] < sz[b])
		swap (a, b);
	sz[a] += sz[b];
	p[b] = a;
}

int used[N];
string place[N];
int n;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> place[i];
		int m;
		cin >> m;
		for (int i = 1; i <= m; ++i) {
			int x;
			cin >> x;
			g[i].emplace_back (x);
		}
	}

	for (int i = 1; i <= n; ++i)

	for (int i = 1; i <= n; ++i) {
		for (auto to : g[i]) {
			if (place[i] == place[to]) {
				Merge (i, to);
			}
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		
	}
	
	return 0;
}
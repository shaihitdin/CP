#include <bits/stdc++.h>

using namespace std;

const int N = 3300;

inline vector <int> primes_list (int x) {
	vector <int> res;
	for (int i = 2; i * i <= x; ++i) {
		while (x % i == 0)
			res.emplace_back (i), x /= i;
	}
	if (x > 1)
		res.emplace_back (x);
	return res;
}

map <int, vector <int> > vertex[110];
int cnt_v[2];
vector <int> g[N];
bool u[N];
int p[N], p2[N];
int n, m, a[110];

inline bool dfs (int v) {
	if (u[v])
		return 0;
	u[v] = 1;
	for (int to : g[v]) {
		if (!p[to] || dfs (p[to])) {
			p[to] = v;
			p2[v] = to;
			return 1;
		}
	}
	return 0;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	for (int i = 1; i <= n; ++i) {
		auto tmp = primes_list (a[i]);
		for (auto it : tmp)
			vertex[i][it].emplace_back (++cnt_v[i % 2]);
	}
	
	for (int i = 1; i <= m; ++i) {
		int x, y;
		cin >> x >> y;
		if (x % 2 == 1)
			swap (x, y);
		int z = __gcd (a[x], a[y]);
		auto tmp = primes_list (z);
		for (auto it : tmp) {
			for (auto it2 : vertex[x][it])
			for (auto it3 : vertex[y][it])
				g[it2].emplace_back (it3);
		}
	}
	
	int ans = 0;
	
	for (int run = 1; run;) {
		run = 0;
		memset (u, 0, sizeof (u));
		for (int i = 1; i <= cnt_v[0]; ++i)
			if (!p2[i])
				if (dfs (i))
					++ans, run = 1;
	}
	
	cout << ans;
	
	return 0;
}
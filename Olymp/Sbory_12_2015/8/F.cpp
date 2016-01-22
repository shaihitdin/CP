#include <bits/stdc++.h>

using namespace std;

const int N = 3e4 + 100, sN = 220;

bool prime[N];
bool u[sN];
vector <int> g[sN];
int p[sN];
int a[N];

inline bool dfs (int v, int pr) {
	if (u[v])
		return 1;
	u[v] = 1;
	for (auto to : g[v]) {
		if (to == pr)
			continue;
		if (dfs (to, v)) {
			p[to] = v;
			return 1;
		}
	}		
	return 0;
}


int main () {
	
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	int n;
	
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	memset (prime, 1, sizeof (prime));
	
	prime[1] = prime[0] = 0;

	for (int i = 2; i < N; ++i)
		if (prime[i])
			for (int j = i + i; j < N; j += i)
				prime[j] = 0;
	
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (prime[a[i] + a[j]]) {
				g[i].emplace_back (j);
			}		
		}
	}
	
	int ans = 0;
	
	for (int i = 1; i <= n; ++i) {
		memset (u, 0, sizeof (u));
		ans += dfs (i, -1);
	}
	
	if (ans != n) {
		cout << "Impossible\n";
		return 0;
	}
	
	memset (u, 0, sizeof (u));

	vector <vector <int> > res;

	for (int i = 1; i <= n; ++i) {
		vector <int> s;
		if (!u[i]) {
			int v = i;
			u[i] = 1;
			s.emplace_back (v);
			v = p[v];
			while (v != i) {
				u[v] = 1;
				s.emplace_back (v), v = p[v];
			}
			res.emplace_back (s);
		}
	}
	
	cout << res.size () << "\n";

	for (auto it : res) {
		cout << it.size () << " ";
		for (auto j : it)
			cout << j << " ";
		cout << "\n";
	}
	
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100;

int n, m;
int a[N], b[N], d[N];
map <int, int> Map;
vector <int> g[N];
int ans;


int main () {

	freopen ("dominoes.in", "r", stdin);
	freopen ("dominoes.out", "w", stdout);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
		Map[a[i]] = 0;
		Map[b[i]] = 0;
	}

	m = 1;
	for (auto it = Map.begin (); it != Map.end (); ++it, ++m)
		it -> second = m;
	
	--m;
	
	for (int i = 1; i <= n; ++i) {
		a[i] = Map[a[i]];
		b[i] = Map[b[i]];
		g[a[i]].emplace_back (b[i]);
	}
	
	for (int i = 1; i <= m; ++i) {
		for (auto to : g[i])
			if (to == i)
				++d[i];
		for (auto to : g[i]) {
			if (to != i)
				d[to] = max (d[to], d[i] + 1);
		}
		ans = max (ans, d[i]);
	}
	
	cout << ans;
	
	return 0;
}
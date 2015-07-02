#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;
typedef long long ll;

const int N = 4e5;

int p[N], sz[N];

vector <pii> g[N];


inline int get_p (const int &x) {
	return x == p[x] ? x : p[x] = get_p (p[x]);
}

inline void smerge (int a, int b) {
	a = get_p (a);
	b = get_p (b);
	if (sz[b] > sz[a])
		swap (a, b);
	p[b] = a;
	sz[a] += sz[b];
}

inline ll c_ans (int a) {
	a = get_p (a);
	return (sz[a] * 1ll * (sz[a] - 1)) / 2 - (sz[a] - 1);
}

int main () {

	freopen ("mst-add-edges.in", "r", stdin);
	freopen ("mst-add-edges.out", "w", stdout);

	ios_base :: sync_with_stdio (0);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i < n; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		g[w].push_back (pii (a, b));
	}

	for (int i = 1; i <= n; ++i)
		p[i] = i, sz[i] = 1;
	
	ll ans = 0;

	for (int i = 1; i <= k; ++i) {
		for (auto it : g[i]) {
			int v1 = it.first, v2 = it.second;
			ans -= c_ans (v1);
			ans -= c_ans (v2);
			smerge (v1, v2);
			ans += c_ans (v1);
		}
		cout << ans << "\n";
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 100;

set <int> g[N], good;
bool bad[N];
int p[N];
int n, m, k;
int to_del;

inline int get_p (int v) {
	return p[v] = ((p[v] == v) ? (v) : get_p (p[v]));
}

inline bool can (int v, int u) {
	v = get_p (v), u = get_p (u);
	return (u != v && !(g[v].find (u) != g[v].end () && g[u].find (v) != g[u].end ()));
}

inline bool Merge (int a, int b) {
    a = get_p (a), b = get_p (b);
    if (!can (a, b))
		return 0;
    if (g[a].size () > g[b].size ())
    	swap (a, b);
	vector <int> nlst;
	for (auto v : g[a])
		if (!can (v, b))
			nlst.emplace_back (v);
	g[a].clear ();
	g[b] = set <int> (nlst.begin (), nlst.end ());
	if (good.find (a) != good.end ()) {
		good.erase (a);
		good.insert (b);
	}
	p[a] = b;
	to_del = a;
	return 1;
}

int main () {
    #ifdef LOCAL
    freopen ("in", "r", stdin);
    #endif

    ios_base :: sync_with_stdio (0);
    cin.tie (0);
    cout.tie (0);

    cin >> n >> m >> k;

	for (int i = 1; i <= n; ++i)
		p[i] = i;
	
	for (int i = 1; i <= m; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].insert (b);
		g[b].insert (a);
	}
	
	for (auto v : g[1])
		bad[v] = 1;
		
	for (int i = 2; i <= n; ++i)
		if (!bad[i])
			good.insert (i);
/*	
	for (int i = 2; i <= n; ++i) {
		for (int j = 2; j <= n; ++j) {
			cerr << i << " " << j << " " << can (i, j) << "\n";
		}
	}
	
	cerr << "\n";
*/	
	for (int i = 2; i <= n; ++i) {
		if (!bad[i])
			continue;
		for (int j = i + 1; j <= n && !Merge (j, i); ++j);
	}
	
	for (int i = 2; i <= n; ++i) {
		if (good.find (get_p (i)) != good.end ())
			continue;
		for (auto v : good)
			if (Merge (i, v))
				break;
	}

	for (int i = 2; i <= n; ++i) {
		if (get_p (i) == i && good.find (i) != good.end () && good.size () > k) {
			bool flag = 0;
			for (auto v : good) {
				if (Merge (v, i)) {
					flag = 1;
					break;
				}
			}
			if (flag)
				good.erase (to_del);
		}
	}
/*	
	for (int i = 2; i <= n; ++i) {
		for (int j = 2; j <= n; ++j) {
			cerr << i << " " << j << " " << can (i, j) << "\n";
		}
	}
*/	
	if (good.size () != k) {
		cout << "im";
	} else {
		for (int i = 2; i <= n; ++i) {
			if (good.find (get_p (i)) == good.end ()) {
				cout << "im";
				break;
			}
		}
	}
	cout << "possible";

	return 0;
}
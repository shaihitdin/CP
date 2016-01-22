#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "bipartite."
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef pair <int, int> PII;
typedef double ld;

const int N = 3000;

set <pair <int, int> > g[N];

int n, m, col[N];


int main () {

	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);

	srand (time (0));
	
	cin >> n >> m;

	for (int i = 1; i <= m; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].insert (make_pair (y, i));
		g[y].insert (make_pair (x, i));
	}

	for (int i = 1; i <= n; ++i) {
		col[i] = rand () & 1;
	}

	vector <int> ans;

	bool ok = 1;
	
	while (ok) {
		ok = 0;
		for (int i = 1; i <= n; ++i) {
			int cnt = 0;			
			for (auto to : g[i]) {
				if (col[to.first] == col[i])
					++cnt;
			}
			if (cnt * 2 > g[i].size ()) {
				col[i] ^= 1;
				ok = 1;
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		vector <pair <int, int> > to_erase;
		for (auto to : g[i]) {
			if (col[to.first] == col[i]) {
				ans.emplace_back (to.second);
				to_erase.emplace_back (to);
				g[to.first].erase (make_pair (i, to.second));
			}
		}
		for (auto to : to_erase)
			g[i].erase (to);
	
	}
	
	cout << ans.size () << "\n";
	
	for (auto it : ans) {
		cout << it << " ";
	}

	return 0;             
}       
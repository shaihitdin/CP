#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)

typedef int ll;

const int N = 5e3 + 120;
const ll INF = 1e9 + 9;
                              
int n;
int a[N];
vector <int> g[N];

ll d[N][N];
bool u[N][N]; 
int clear[N];
int timer, id[N], sz[N];

int b_dfs(int x, int pr = -1) {
	id[++timer] = x;
	if (!clear[x]) {
		clear[x] = 1;
		forn(i, 0, int(g[x].size()) - 1) {
			if (g[x][i] == pr) {
				g[x].erase(g[x].begin() + i);
				break;
			}
		}
	}
	if (!g[x].size())
		return sz[x] = 1;            
	for (auto to : g[x]) 
		sz[x] += b_dfs(to, x);
	return sz[x];
}

main () {
	freopen ("tree.in", "r", stdin);
	freopen ("tree.out", "w", stdout);

	cin >> n;
	forn(i, 1, n)
		cin >> a[i];
	forn(i, 1, n - 1) {
	    int f, t;
		cin >> f >> t;
		g[f].push_back(t); 
		g[t].push_back(f);
	}                         

	b_dfs(1);
    forn(i, 1, n)
    	forn(j, 0, n)
    		d[i][j] = INF;           

	for1(t, n, 1) {
		int x = id[t];
		forn(k, 0, sz[x]) {
			if (g[x].size() == 0) {
				if (k > 1) d[x][k] = INF;
				else d[x][k] = abs(a[x] - k);
				continue;
			}
			if (g[x].size() == 1) {
				int to = g[x][0];
				d[x][k] = d[to][k] + abs(a[x] - k);
				continue;
			}	
			d[x][k] = INF;           
			forn(k1, 0, k) {
				int to1 = g[x][0], to2 = g[x][1];
				int cur = d[to1][k1] + d[to2][k - k1] + abs(a[x] - k); 
				d[x][k] = min(d[x][k], cur);
			}	
		}
	}

	int ans = INF;
	forn(i, 0, sz[1])
		ans = min(ans, d[1][i]);
				
	cout << ans << "\n";

	return 0;
}
        
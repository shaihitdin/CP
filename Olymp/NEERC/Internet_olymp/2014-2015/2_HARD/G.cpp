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

int dp(int x, int k, int pr = -1) {
	if (u[x][k]) return d[x][k];
	u[x][k] = 1;
	if (!clear[x]) {
		clear[x] = 1;
		forn(i, 0, int(g[x].size()) - 1) {
			if (g[x][i] == pr) {
				g[x].erase(g[x].begin() + i);
				break;
			}
		}
	}                                      
	if (g[x].size() == 0) {
		if (k > 1) return d[x][k] = INF;
		return d[x][k] = abs(a[x] - k);
	}
	if (g[x].size() == 1) {
		int to = g[x][0];
		return d[x][k] = dp(to, k, x) + abs(a[x] - k);
	}	
	d[x][k] = INF;           
	forn(k1, 0, k) {
		int to1 = g[x][0], to2 = g[x][1];
		int cur = dp(to1, k1, x) + dp(to2, k - k1, x) + abs(a[x] - k); 
		d[x][k] = min(d[x][k], cur);
	}	
	return d[x][k];
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

	int ans = INF;
	forn(i, 0, min(n, int(1e2)))
		ans = min(ans, dp(1, i));
	forn(i, 0, max(0, n - int(1e2)))
		ans = min(ans, dp(1, i));
		
	cout << ans << "\n";

	return 0;
}
        
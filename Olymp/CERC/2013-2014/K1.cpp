#include <bits/stdc++.h>

using namespace std;

const int N = 31;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define pb push_back

int n;
int a[N][N];

int u[N];
vector <int> cur, cyc, lw, oreder;

void dfs(int x, bool two = 0) {
	if (u[x] == 2) return;
	if (u[x] == 1) {
		while (cur.back() != x) {
			cyc.pb(cur.back());
			cur.pop_back();
		}
		cyc.pb(x);	
		return;
	}
	u[x] = 1; 
	cur.pb(x);
	if (cur.size() > lw.size()) lw = cur;
	forn(i, 1, 26) {
		if (!a[x][i]) {
			dfs(i, two);
			if (cyc.size())
				return;
		}	
	}
	cur.pop_back();
	u[x] = 2;
	if (!two)
		oreder.pb(x);
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int t;
	
	cin >> t;

	while (t--) {
		lw.clear();
		cyc.clear();
		cur.clear();
		oreder.clear();
		forn(i, 1, 26) {
			u[i] = 0;
			forn(j, 1, 26)
				a[i][j] = 0;
		} 
		cin >> n;   
		for (int i = 1; i <= n; ++i) {
			char c1, c2;
			cin >> c1 >> c2;
			c1 = c1 - 'a' + 1;
			c2 = c2 - 'a' + 1;
			a[c1][c2] = 1;
		}    
		forn(x, 1, 26) {
			dfs(x);
			if (cyc.size()) {
				int sz = cyc.size();
			
				vector <int> ans;
				while (ans.size() < 39)
					for (auto x : cyc)
						ans.pb(x);
				while (ans.size() > 39)
					ans.pop_back();

				forn(i, 0, 19) {
					forn(j, 0, 19)
						cout << char('a' + ans[i + j] - 1);
					cout << "\n";
				}
				break;
			}
		}
		if (cyc.size()) continue; 
		cur.clear();
		lw.clear();             
		while (oreder.size()) {
			memset(u, 0, sizeof(u));
			dfs(oreder.back(), 1);
			oreder.pop_back();
		}	                                           		
		int m = (lw.size() + 1) / 2;
		forn(i, 0, m - 1) {
			forn(j, 0, m - 1)
				cout << char('a' + lw[i + j] - 1);
			cout << "\n";
		}	
	}

	return 0;
}

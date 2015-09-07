#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "mitm."

typedef long long ll;                                         

const int N = 2e3;

int n, m, a, b, meet, base; 
vector <int> g[maxn];
 
int main () {
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> m;
	cin >> a >> b >> meet >> base;
	forn(i, 1, m) {
		int f, t;
		cin >> f >> t;
		g[f].pb(t), g[t].pb(f);
	}

	printf("%d\n", );
                            
	return 0;         	
}               
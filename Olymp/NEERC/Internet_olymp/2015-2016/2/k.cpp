#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "mushrooms."
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef pair <int, int> PII;

const int N = 2e6;
const int INF = 1e9 + 9;               
                        
int n;
int a[N];
vector <int> g[N];

int main () {
//	#ifdef LOCAL
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);
//	#endif

	ios_base :: sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    forn(i, 1, n)
    	cin >> a[i];
    forn(i, 1, n - 1) {
    	int f, t;
    	cin >> f >> t;
    	g[f].pb(t);
    	g[t].pb(f);
    }

    int l = 1, r = 1e9, mid = 0;
    while (l < r) {
    	mid = (l + r) >> 1;
    	if (possible(mid)) l = mid;
    	else r = mid - 1;
    }
    cout <<     

	return 0;
}

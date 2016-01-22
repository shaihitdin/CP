#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "arrangement."
#define pb push_back
#define F first
#define S second
 
typedef long long ll;      
typedef pair <ll, ll> PII;
typedef long double ld;
           
const int N = 2e5;
const int INF = 1e9 + 9;               

int n, m;
int a[100][100]; 

int dx[] = {-1, 0, +1, 0};
int dy[] = {0, +1, 0, -1};

inline bool inside (const int &x, const int &y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

main () {
	#ifdef LOCAL
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	a[1][1] = 0;
	int cnt = 0;
	forn(i, 2, m) {
		PII p(1, i);
		while (p.S && p.F <= n) {
			a[p.F][p.S] = ++cnt;
			++p.F, --p.S;
		}
	}
	forn(i, 2, n - 1) {
		PII p(i, m);
		while (p.S && p.F <= n) {
			a[p.F][p.S] = ++cnt;
			++p.F, --p.S;
		}
	}                   
	a[n][m] = n * m - 1;
	//assert(cnt == n * m - 2);

	forn(i, 1, n) {
		forn(j, 1, m) {
			cout << a[i][j] << " ";
		} 
		cout << "\n";
	}

	return 0;
}

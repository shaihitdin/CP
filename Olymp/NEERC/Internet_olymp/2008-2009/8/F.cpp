#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "railway."

const int N = 2e5;
                 
int n;
int d[N];
int z[N];
int s, t;
int c1, c2, c3, r;

int main () {
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);  

	cin >> n;
	forn(i, 1, n) 
		cin >> d[i];
	forn(i, 1, n)
		cin >> z[i];
	cin >> s >> t;
	cin >> c1 >> c2 >> c3 >> r;

	printf("%d\n", max(c1, abs(z[s] - z[t]) * c1));	
	int dist = abs(d[s] - d[t]);
	printf("%d\n", (dist < r) ? dist * c2 : dist * c3);	

	return 0;
}
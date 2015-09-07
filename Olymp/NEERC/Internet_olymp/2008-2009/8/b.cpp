#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "key."

typedef long long ll;                                         

const int N = 2e3;

int n, p;
int d[N][N];

int a[N], sz;
 
int main () {
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> p;
	forn(i, 1, p) 
		if (p % i == 0)
			a[++sz] = i;
		
	d[0][0] = 0;
	forn(i, 1, n)
		forn(j, 1, p)
			forn(k, 1, sz)
				if (j % a[k] == 0)
					d[i][j] = max(d[i][j], d[i - 1][j / a[k]] + a[k]);

	printf("%d\n", d[n][p]);
                            
	return 0;         	
}
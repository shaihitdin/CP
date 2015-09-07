#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "football."

typedef long long ll;

const int N = 100;

int n, k;
int d[N][N];

int calc() {
	d[0][0] = 1;                  
	forn(i, 0, n) {
		forn(j, 1, k) {
			d[i][j] += d[i][j - 1];
			if (i >= 1) d[i][j] += d[i - 1][j - 1];
			if (i >= 3) d[i][j] += d[i - 3][j - 1];
		}
	}
}

int main () {
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	scanf("%d %d\n", &n, &k);
	calc();
	printf("%d\n", d[n][k]);

	return 0;         	
}
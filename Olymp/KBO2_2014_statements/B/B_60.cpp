#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
using namespace std;
const int N = 1006;
typedef long long ll;
const ll inf = 1e15;
int n, k, a[N][N];
ll d[N][N], pref[N][N], suff[N][N];
char filein[N];
int main (int argc, char *argv[]) {
	freopen ("garland.in", "r", stdin);
	freopen ("garland.out", "w", stdout);
	scanf ("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= k; ++j)
			scanf ("%d", &a[i][j]);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= k; ++j)
			d[i][j] = inf;
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= k; ++j)
    		for (int l = 1; l <= k; ++l)
    			if (j != l)
    				d[i][j] = min (d[i][j], d[i - 1][l] + a[i][j]);
    }
    ll ans = inf;
    for (int i = 1; i <= k; ++i)
    	ans = min (ans, d[n][i]);
    printf ("%I64d", ans);
    return 0;
}
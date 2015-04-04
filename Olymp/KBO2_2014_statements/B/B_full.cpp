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
	for (int i = 0; i < strlen (argv[1]); ++i)
		filein[i] = argv[1][i];
	freopen (filein, "r", stdin);
	filein[strlen (filein)] = '.';
	filein[strlen (filein)] = 'a';
	freopen (filein, "w", stdout);
	scanf ("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= k; ++j)
			scanf ("%d", &a[i][j]);
    for (int i = 1; i <= n + 1; ++i)
    	pref[i][0] = inf, suff[i][k + 1] = inf;
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= k; ++j)
    		d[i][j] = min (pref[i - 1][j - 1], suff[i - 1][j + 1]) + a[i][j];
    	for (int j = 1; j <= k; ++j)
    		pref[i][j] = min (pref[i][j - 1], d[i][j]);
		for (int j = k; j >= 1; --j)
			suff[i][j] = min (suff[i][j + 1], d[i][j]);
    }
    printf ("%I64d", pref[n][k]);
	return 0;
}
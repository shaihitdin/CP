/*
ID: shaihit1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int N = 301, inf = 1000000000;

int d[61][N], a[N], n, m, k, ans;

int main() {
    freopen ("barn1.in", "r", stdin);
    freopen ("barn1.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 0; i <= n + 1; ++i)
    	for (int j = 0; j <= k + 1; ++j)
    		d[i][j] = inf;
    
    for (int i = 1; i <= k; ++i)
    	cin >> a[i];
    sort (a + 1, a + k + 1);

    d[0][1] = 0;
    for (int i = 0; i < n; ++i)
    	for (int j = 1; j <= k; ++j)
    		for (int l = j + 1; l <= k + 1; ++l)
    			d[i + 1][l] = min (d[i + 1][l], d[i][j] + a[l - 1] - a[j] + 1);
    ans = inf;
    /*
    for (int i = 0; i <= n; ++i)
    	cerr << d[i][k + 1] << " ";
    */
    for (int i = 0; i <= n; ++i)
    	ans = min (ans, d[i][k + 1]);
    cout << ans << "\n";
    return 0;
}
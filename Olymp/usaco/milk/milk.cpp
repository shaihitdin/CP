/*
ID: shaihit1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int N = 5001;

int n, m, ans;

int a[N], b[N], c[N];

inline bool cmp (const int &x, const int &y) {
	return a[x] < a[y];
}

int main() {
    freopen ("milk.in", "r", stdin);
    freopen ("milk.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
    	cin >> a[i] >> b[i];
    	c[i] = i;
    }
    sort (c + 1, c + m + 1, cmp);

    for (int i = 1; n; ++i) {
    	int can = min (n, b[c[i]]);
    	ans += can * a[c[i]];
    	n -= can;
    }
    cout << ans << "\n";
    return 0;
}

#include <iostream>
#include <stdio.h>
using namespace std;
const int N = (1e5) + 1;
const long long mod = (1e9) + 7;
long long d[N], n, ans;
char a[N];
int main () {
    freopen ("binary.in", "r", stdin);
    freopen ("binary.out", "w", stdout);
    scanf ("%d\n", &n);
    for (int i = 1; i <= n; ++i)
        scanf ("%c",&a[i]);
    d[0] = 1;
    for (int i = 2; i <= n; ++i) {
        if (a[i] == '1' && a[i - 1] != a[i - 3]) {
            d[i] = d[i - 2];
        }
        d[i] += d[i - 1];
        d[i] %= mod;
    }
    ans = 0;
    for (int i = 1; i <= n; ++i)
    	ans = max (ans, d[i]);
    printf ("%I64d", ans);
    return 0;
}
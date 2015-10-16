#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <map>
#include <string.h>
#include <stdio.h>
#include <string>
using namespace std;
#define mkp make_pair
#define F first
#define S second
const short N = 30001;
map <short, short> mp[N];
short ans, n, d, x;
short u[N], temp, add;
inline void f_max (short &x, const short &y) {
    if (y > x)
        x = y;
}
inline short max1 (const short &x, const short &y) {
    return x > y ? x : y;
}
int main () {
    #ifndef ONLINE_JUDGE
    freopen ("in", "r", stdin);
    freopen ("out", "w", stdout);
    #endif
    auto it = mp[0].begin();
    scanf ("%d%d", &n, &d);
    for (short i = 1; i <= n; ++i) {
        scanf ("%d", &x);
        ++u[x];
    }          
    /*
    for (short i = 0; i < N; ++i)
        mp[i].reserve (500);
    */
    mp[d][d] = u[d];
    for (short i = d; i < N; ++i) {
        add = u[i];
        for (it = mp[i].begin(); it != mp[i].end(); ++it) {
            temp = it -> S + add; 
            f_max (ans, temp);
            for (short j = max1 (it -> F - 1, 1); j <= it -> F + 1; ++j) {
                if (i + j < N)  f_max (mp[i + j][j], temp);
            }
        }
    }
    fprintf (stderr, "%f", clock() / (float) CLOCKS_PER_SEC);
    printf ("%d", ans);
    return 0;
}
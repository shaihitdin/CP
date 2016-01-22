#include <bits/stdc++.h>
 
 
using namespace std;
 
const int sz = 1 << 17, D = 21, bpr = 10007;
 
typedef long long ll;
 
short t[sz + sz][D];
int c, n;
int a[sz], b[sz];
ll tmp[D];
 
inline void upd (int x, const int &na, const int &nb) {
    x += sz;
    for (int i = 0; i <= c; ++i)
        t[x][i] = 0;
    t[x][1] = na % bpr;
    t[x][0] = nb % bpr;
    while (x >>= 1) {
        for (int i = 0; i <= c; ++i)
            tmp[i] = 0;
        for (int i = 0; i <= c; ++i)
            for (int j = 0; j <= c; ++j)
                tmp[min (c, i + j)] += int (t[x + x][i]) * t[x + x + 1][j];
        for (int i = 0; i <= c; ++i)
            t[x][i] = tmp[i] % bpr;
    }
}
 
int main () {
 
    #ifdef LOCAL
    freopen ("in", "r", stdin);
    freopen ("out", "w", stdout);
    #endif
 
    ios_base :: sync_with_stdio (0);
    cin.tie (0);
 
    cin >> n >> c;
 
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
 
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        upd (i, a[i], b[i]);
    }
    
    for (int i = n + 1; i <= sz; ++i) {
        upd (i, 0, 1);
    }
    
    upd (0, 0, 1);
    
    int q;
    
    cin >> q;
 
    while (q--) {
        int p, a, b;
        cin >> p >> a >> b;
        upd (p, a, b);
        cout << t[1][c] << "\n";
    }
    
    return 0;
}
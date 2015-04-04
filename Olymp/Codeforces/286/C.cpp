#include <bits/stdc++.h>

using namespace std;
#define mkp make_pair
#define F first
#define S second
const short N = 30001;

vector <unordered_map <short, short> > mp (N, unordered_map <short, short> (400));
//unordered_map <short, short> mp[N];
vector <int> vvv[N];
short ans, n, d, x;
short u[N], temp, add;
inline void f_max (short &x, const short &y) {
    if (y > x)
        x = y;
}
inline int max1 (const int &x, const int &y) {
    return x > y ? x : y;
}
int main () {
    #ifndef ONLINE_JUDGE
    freopen ("in", "r", stdin);
    freopen ("out", "w", stdout);
    #endif
    auto it = mp[0].begin();
    scanf ("%hd%hd", &n, &d);
    for (int i = 1; i <= n; ++i) {
        scanf ("%hd", &x);
        ++u[x];
    }          
    for (int i = 0; i < N; ++i) {
        mp[i].reserve (400);
        mp[i].load_factor (0.6);
    }
    mp[d][d] = u[d];
    for (short i = d; i < N; ++i) {
    	//cerr << mp[i].load_factor() << " ";
        add = u[i];
        for (it = mp[i].begin(); it != mp[i].end(); ++it) {
            temp = it -> S + add; 
            f_max (ans, temp);
            for (short j = max1 (it -> F - 1, 1); j <= it -> F + 1; ++j) {
                if (i + j < N)
                    f_max (mp[i + j][j], temp);
            }
        }
    }
    fprintf (stderr, "%f", clock() / (float) CLOCKS_PER_SEC);
    printf ("%hd", ans);
    return 0;
}
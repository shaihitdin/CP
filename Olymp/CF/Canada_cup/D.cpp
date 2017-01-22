#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 100;

typedef long long ll;

#define int ll

int w[N], t[N], a[N];
int n;
int ans;

inline bool cmp (int x, int y) {
    return t[x] > t[y];
}

inline void ok () {
    int i = 2;
    int has = t[1];
    multiset <int> Set;
    while (1) {
        while (i <= n && has < t[a[i]])
            Set.insert (w[a[i]] - t[a[i++]] + 1);
        ans = min (ans, Set.size () + 1ll);
        int can = has;
        can = min (can, *Set.begin ());
        if (can < *Set.begin ())
            return;
        Set.erase (Set.begin ());
        has -= can;
    }
}

main () {
    #ifdef LOCAL
    freopen ("in", "r", stdin);
    #endif
    ios_base :: sync_with_stdio (0);
    cin >> n;
    ans = n;
    for (int i = 1; i <= n; ++i)
        cin >> t[i] >> w[i];
    for (int i = 1; i <= n; ++i)
    	a[i] = i;
    sort (a + 2, a + n + 1, cmp);
    ok ();
    cout << ans;
    return 0;
}
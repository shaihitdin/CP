#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <complex>

#define pb push_back
#define mp make_pair

#define f first
#define s second

#define ll long long

using namespace std;

const ll N = (ll) 1e5 + 7;

struct node {
    ll x, w;
};
bool cmp(node u, node v) {
    return u.x < v.x;
}

ll n;
node a[N];

ll dp[2][N];


int main() {
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
    #else
        //#define FNAME
        //freopen(FNAME".in", "r", stdin);
        //freopen(FNAME".out", "w", stdout);
    #endif

    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &a[i].x);
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &a[i].w);

    sort(a + 1, a + n + 1, cmp);

    for (ll j = 0; j <= n; j++)
        dp[0][j] = dp[1][j] = (ll) 1e18;

    dp[1][0] = -(ll) 1e18;
    dp[1][1] = a[1].x;
    for (ll i = 2; i <= n; i++) {
        for (ll j = 0; j <= i; j++) {
            dp[i&1][j] = (ll) 1e18;
            if (j < i && dp[(i - 1) & 1][j] != (ll) 1e18)
                dp[i & 1][j] = min(dp[i & 1][j], dp[(i - 1) & 1][j] + a[i].w);
            if (j) {
                ll pre = dp[(i - 1) & 1][j - 1];
                if (pre <= a[i].x && pre != (ll) 1e18)
                    dp[i & 1][j] = min(dp[i & 1][j], max(pre + a[i].w, a[i].x));
            }
        }
    }
    ll ans = 0;
    for (ll j = 0; j <= n; j++)
        if (dp[n & 1][j] != (ll) 1e18)
            ans = j;
    cout << n - ans;
    return 0;
}

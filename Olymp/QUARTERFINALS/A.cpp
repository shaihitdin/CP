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

using namespace std;

const int N = (int) 1e3 + 7;

int n, m;
int a[N][N];

map<int, bool> good;

int main() {
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
    #else
        //#define FNAME
        //freopen(FNAME".in", "r", stdin);
        //freopen(FNAME".out", "w", stdout);
    #endif

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        int cmax = 0;
        for (int j = 1; j <= m; j++) cmax = max(cmax, a[i][j]);
        good[cmax] = 1;
    }
    for (int j = 1; j <= m; j++) {
        int cmax = 0;
        for (int i = 1; i <= n; i++) cmax = max(cmax, a[i][j]);
        good[cmax] = 1;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!good.count(a[i][j])) ans += a[i][j];

    cout << ans;
    return 0;
}

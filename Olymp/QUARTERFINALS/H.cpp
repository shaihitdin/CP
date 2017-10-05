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

const int N = (int) 1e5 + 7;

int n;
int a[N];

int main() {
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
    #else
        //#define FNAME
        //freopen(FNAME".in", "r", stdin);
        //freopen(FNAME".out", "w", stdout);
    #endif

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 0; i <= min(3, n); i++) {
        int prod = 1;
        for (int j = 1; j <= i; j++) prod *= a[j];
        for (int k = n; k >= max(n - (3-i) + 1, i + 1); k--) prod *= a[k];
        ans = max(ans, prod);
    }
    ans = max(ans, a[n] * a[n - 1]);
    ans = max(ans, a[1] * a[2]);
    cout << ans;
    return 0;
}

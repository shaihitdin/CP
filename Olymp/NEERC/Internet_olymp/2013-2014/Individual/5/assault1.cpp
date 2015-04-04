#include <iostream>
#include <set>
#include <vector>
#include <stdio.h>
using namespace std;

typedef pair <int, int> pii;
const int N = 1e5 + 2, inf = 1e9;


vector <int> g[N];
int n, t[N], a[N], p[N];
long long d[N];

inline bool operator < (const pii &a, const pii &b) {
    return a.first > b.first;
}

set <pii> s;

int main () {
    freopen ("assault.in", "r", stdin);
    freopen ("assault.out", "w", stdout);
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i)
        scanf ("%d", &t[i]);
    t[n + 1] = 1e6;
    for (int i = n + 1; i; --i) {
        while (s.size() && (*s.begin()).first > t[i]) {
            g[i].push_back ((*s.begin()).second);
            s.erase (s.begin());
        }
        g[i].push_back (n + 1);
        s.insert (make_pair (t[i], i));
    }
    for (int i = 1; i <= n; ++i) {
        for (int to : g[i]) {
            if (d[to] < d[i] + a[i]) {
                d[to] = d[i] + a[i];
                p[to] = i;
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n + 1; ++i)
        ans = max (ans * 1LL, d[i]);
    printf ("%I64d", ans);
    return 0;
}
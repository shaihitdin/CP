#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

#define mkp make_pair
#define F first
#define S second

const short N = 6010, sz = (1 << 13);

short n, r[N];
vector <short> g[N];
vector <short> mx[N];
short ans;
short d[N];

inline short maxx (const short &x, const short &y) {
    return (x > y) ? x : y;
}

inline void add_element (const short &v, const short &delta) {
    if(mx[delta].size() == 0 || (mx[delta - 1][mx[delta - 1].size() - 1] < r[v] && mx[delta][mx[delta].size() - 1] > r[v])) {
        mx[delta].push_back (r[v]);
        d[delta] = r[v];
    }
}

inline void del_element (const short &v, const short &va) {
    if (mx[va][mx[va].size() - 1] == r[v]) {
        mx[va].pop_back();
        d[va] = mx[va][mx[va].size() - 1];
    }
}

bool u[N];

inline void dfs (const short &v) {
    u[v] = 1;
    short local = upper_bound (d + 1, d + n + 1, r[v]) - d;
    if (d[local - 1] < r[v] && d[local] > r[v]) {
	    ans = maxx (ans, local);
    }
    add_element (v, local);
    for (short to = 0; to < g[v].size(); ++to)
        if(!u[g[v][to]])
            dfs (g[v][to]);
    del_element (v, local);
}

pair <int, int> b[N];

short cnt;

int a[N];

int main () {
    
    #ifdef LOCAL
    freopen ("in", "r", stdin);
    freopen ("out", "w", stdout);
    #endif

    
    scanf ("%d", &n);
    
    for (short i = 1; i <= n; ++i)
        scanf ("%d", a + i);
    
    for (short i = 1; i <= n; ++i) {
        b[i].F = a[i];
        b[i].S = i;
    }
    
    sort (b + 1, b + n + 1);
    
    for (short i = 1; i <= n; ++i) {
        if (b[i].F == b[i-1].F)
            r[b[i].S] = cnt;
        else {
            r[b[i].S] = ++cnt;
        }
    }
    
    for (short i = 1; i < n; ++i) {
        short x, y;
        scanf ("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    r[n + 1] = 10000;
    
    for (int i = 1; i <= n; ++i) {
    	add_element (n + 1, i);
    }
    
    r[n + 2] = 0;

    add_element (n + 2, 0);
    
    for (short i = 1; i <= n; ++i) {
        memset (u, 0, sizeof(u));
        dfs (i);
    }
    
    printf ("%d", ans);
    
    return 0;
}
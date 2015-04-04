#include <bits/stdc++.h>

using namespace std;
const short N = 501;
vector <short> a[N];
bool u[N][N];
int n, m;
short x, y;
char q;
 
inline static void add (const short &x, const short &y) {
    if (u[x][y])
        return;
    u[x][y] = 1;
    short i = 0;
    for (; i < a[x].size() && a[x][i] < y; ++i);
    a[x].insert (a[x].begin() + i, y);
}
 
inline static int sqr (const short &i) {
    return i * i;
}
 
inline static void fmin (int &x, const int &y) {
    if (x > y)
        x = y;
}
 
inline static void fmins (short &x, const short &y) {
    if (x > y)
        x = y;
}
 
inline static void fmax (short &x, const short &y) {
    if (x < y)
        x = y;
}
 
inline static int dist (const short &i, const short &j, const short &x, const short &y) {
    return sqr (i - x) + sqr (j - y);
}
 
int main () {
    #ifndef ONLINE_JUDGE
    freopen ("in", "r", stdin);
    freopen ("out", "w", stdout);
    #endif
    for (int i = 0; i < N; ++i) {
        a[i].resize (N);
        a[i].resize (0);
    }
    scanf ("%d%d\n", &n, &m);
    for (short i = 1; i <= n; ++i) {
        for (short j = 1; j <= m; ++j) {
            q = getchar();
            if (q == 'x')
                add (i, j);
        }
        getchar();
    }
    scanf ("%d", &m);
    for (int test = 1; test <= m; ++test) {
        scanf ("%hd%hd", &x, &y);
        int ans = 250001;
        for (int i = 1; i <= n; ++i) {
            if (dist (i, y, x, y) >= ans)
                continue;
            if (a[i].begin() == a[i].end())
            	continue;
            int j = lower_bound (a[i].begin(), a[i].end(), y) - a[i].begin();
			fmin (ans, dist (i, a[i][j], x, y));
			if (j) 
				fmin (ans, dist (i, a[i][j - 1], x, y));
			if (j != a[i].size())
				fmin (ans, dist (i, a[i][j + 1], x, y));
        }
        printf ("%d\n", ans);
        add (x, y);
    }
 
    exit (0);
}
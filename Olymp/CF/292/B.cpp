#include <bits/stdc++.h>

using namespace std;

#define mkp make_pair
#define F first
#define S second

const short N = 2003;

short dx[] = {-1, 0, 0, 1};
short dy[] = {0, -1, 1, 0};
short n, m;
char a[N][N];

vector <pair <short, short> > g[N][N];

set <pair <short, int> > Set;

int main () {
    #ifndef ONLINE_JUDGE
    freopen ("in", "r", stdin);
    freopen ("out", "w", stdout);
    #endif


    scanf ("%hd%hd\n", &n, &m);

    for (short i = 1; i <= n; ++i) {
        for (short j = 1; j <= m; ++j) {
            a[i][j] = getchar();
        }
        getchar();

    }
    for (short i = 1; i <= n; ++i)
        a[i][0] = a[i][m + 1] = '*';
    for (short i = 1; i <= m; ++i)
        a[0][i] = a[n + 1][i] = '*';

    for (short i = 1; i <= n; ++i) {
        for (short j = 1; j <= m; ++j) {
            if (a[i][j] == '*')
                continue;
            for (short k = 0; k < 4; ++k) {
                if (a[i + dx[k]][j + dy[k]] != '*') {
                    g[i][j].push_back (mkp (i + dx[k], j + dy[k]));
                }
            }
            Set.insert (mkp (g[i][j].size(), (i << 12) | (j)));
        }
    }
    auto it = *Set.begin();
    short pos1, pos2;
    while (Set.size()) {
        it = *Set.begin();
        Set.erase (Set.begin());
        
        if (it.F > 1) {
            puts ("Not unique");
            exit (0);
        }
        if (it.F == 0)
            continue;
        pos1 = it.S >> 12;
        it.S ^= pos1 << 12;
        pos2 = it.S;
        auto from = g[pos1][pos2][0];
        Set.erase (mkp (g[from.F][from.S].size(), (from.F << 12)  | from.S));
        for (auto edge : g[from.F][from.S]) {
            for (short i = 0; i < g[edge.F][edge.S].size(); ++i) {
                auto edge1 = g[edge.F][edge.S][i];
                if (edge1 == mkp (from.F, from.S)) {
                    Set.erase (mkp (g[edge.F][edge.S].size(), (edge.F << 12) | edge.S));
                    g[edge.F][edge.S].erase (g[edge.F][edge.S].begin() + i);
                    Set.insert (mkp (g[edge.F][edge.S].size(), (edge.F << 12) | edge.S));
                    break;
                }
            }
        }
        if (abs (pos1 - from.F) == 1) {
            if (from.F < pos1) {
                a[from.F][from.S] = '^';
                a[pos1][pos2] = 'v';
            }
            else {
                a[from.F][from.S] = 'v';
                a[pos1][pos2] = '^';
            }               
        }
        else {
            if (from.S < pos2) {
                a[from.F][from.S] = '<';
                a[pos1][pos2] = '>';
            }
            else {
                a[from.F][from.S] = '>';
                a[pos1][pos2] = '<';
            }                       
        }
    }

    for (short i = 1; i <= n; ++i) {
        for (short j = 1; j <= m; ++j) {
            if (a[i][j] == '.') {
                puts ("Not unique");
                exit (0);           
            }
        }
    }

    for (short i = 1; i <= n; ++i) {
        for (short j = 1; j <= m; ++j) {
            putchar (a[i][j]);
        }
        putchar ('\n');
    }
    return 0;
}
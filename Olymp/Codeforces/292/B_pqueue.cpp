#include <bits/stdc++.h>

using namespace std;

#define mkp make_pair
#define F first
#define S second

const int N = 2003;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int n, m;
char a[N][N];

int sz[N][N];

set <pair <int, int> > Set;

int main () {
    #ifndef ONLINE_JUDGE
    freopen ("in", "r", stdin);
    freopen ("out", "w", stdout);
    #endif


    scanf ("%d%d\n", &n, &m);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            a[i][j] = getchar();
        }
        getchar();

    }
    for (int i = 1; i <= n; ++i)
        a[i][0] = a[i][m + 1] = '*';
    for (int i = 1; i <= m; ++i)
        a[0][i] = a[n + 1][i] = '*';

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == '*')
                continue;
            //g[i][j].resize (4);
            for (int k = 0; k < 4; ++k) {
                if (a[i + dx[k]][j + dy[k]] != '*') {
                	++sz[i][j];
                }
            }
            Set.insert (mkp (sz[i][j], (i << 12) | (j)));
        }
    }
    auto it = *Set.begin();
    int pos1, pos2;
    while (Set.size()) {
        it = *Set.begin();
        Set.erase (Set.begin());
        pos1 = it.S >> 12;
        it.S ^= pos1 << 12;
        pos2 = it.S;
		if (a[pos1][pos2] != '.')
			continue;
        if (it.F > 1) {
            puts ("Not unique");
            exit (0);
        }
        if (it.F == 0)
            continue;
        pair <int, int> from;
        for (int i = 0; i < 4; ++i)
        	if (a[pos1 + dx[i]][pos2 + dy[i]] == '.')
        		from = mkp (pos1 + dx[i], pos2 + dy[i]);

        Set.erase (mkp (sz[from.F][from.S], (from.F << 12)  | from.S));
        for (int i = 0; i < 4; ++i) {
        	if (a[pos1 + dx[i]][pos2 + dy[i]] == '.') {
        		auto edge = mkp (pos1 + dx[i], pos2 + dy[i]);
       	    	for (int j = 0; j < 4; ++j) {
       	    	    if (a[edge.F + dx[j]][edge.S + dy[j]] == '.') {
       	    	    	auto edge1 = mkp (edge.F + dx[j], edge.S + dy[j]);
       	    	    	if (edge1 == mkp (from.F, from.S)) {
       	    	    	    Set.erase (mkp (sz[edge.F][edge.S]--, (edge.F << 12) | edge.S));
       	    	    	    Set.insert (mkp (sz[edge.F][edge.S], (edge.F << 12) | edge.S));
       	    	    	    break;
        				}
        			}
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

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == '.') {
                puts ("Not unique");
                exit (0);           
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            putchar (a[i][j]);
        }
        putchar ('\n');
    }
    return 0;
}
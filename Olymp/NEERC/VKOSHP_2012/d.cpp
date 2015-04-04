#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;
#define forn(i, x, n) for(int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for(int i = int(n); i >= int(x); --i)
#define file "forest."

typedef long long ll;

const int maxn = 128;
const int INF = 2e9 + 7;

struct Cell {
    int r, c;
    Cell() {}
    Cell(int r, int c) : r(r), c(c) {}
};

struct Area { 
    Cell lu, rd;
    Area() {}
    Area(Cell lu, Cell rd) : lu(lu), rd(rd) {}
};       

inline bool in(Cell c, Area a) {
    return (a.lu.r <= c.r && c.r <= a.rd.r && a.lu.c <= c.c && c.c <= a.rd.c);
}

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

int n, m;         
char a[maxn][maxn];
char u[maxn][maxn];
              
void inc_all() {                                   
    forn(i, 1, n)
        forn(j, 1, m)
            if (u[i][j])
                ++a[i][j];  
    memset(u, 0, sizeof(u));
}

int ans;
Area field;
bool flag;    
    
bool able_to_inc() {
    flag = 0;
    forn(i, 1, n) {
        forn(j, 1, m) {
            forn(d, 0, 3) {
                Cell to(i + di[d], j + dj[d]);
                if (!in(to, field)) continue;
                if (a[to.r][to.c] - a[i][j] == 1) {
                    flag = 1;      
                    u[i][j] = 1;
                    break;
                }   
            }
        }   
    }
    return flag;
}

bool check_bs(int x) {
	forn(i, 1, x)
		
}

void out() {
    printf("%d\n", ans);
    forn(i, 1, n) {
        forn(j, 1, m)
            printf("%d ", a[i][j]);
        putchar('\n');
    }   
} 

int main() {
    freopen(file"in", "r", stdin);
    freopen(file"out", "w", stdout);

    scanf("%d %d", &n, &m);
    field = Area(Cell(1, 1), Cell(n, m));
    forn(i, 1, n)
        forn(j, 1, m)
            scanf("%d", &a[i][j]);                                                                                             
                /*
    for(;;) {
        if (!able_to_inc()) {
            out();
            return 0;   
        }
        inc_all();
        ++ans;
    }             */
    int l = 0, r = maxn * maxn, mid = 0;
    while(l < r) {
    	mid = (l + r) >> 1;
    	if (!check_bs(mid)) l = mid + 1;
    	else r = mid;
    }
}
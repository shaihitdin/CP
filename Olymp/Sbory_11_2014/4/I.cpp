#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <map> 
#include <time.h>
#include <assert.h>     
using namespace std;
#define forn(i, x, n) for(short i = short(x); i <= short(n); ++i) 
#define for1(i, n, x) for(short i = short(n); i >= short(x); --i)
#define file "relocation."
#define FastMax(a, b) (a > b ? a : b)
#define mp make_pair 
#define F first
#define S second

typedef long long ll;
typedef pair <short, short> PII;

const short maxn = 42;
const short INF = 42;

short tests_num;
short c1, c2, n;


inline bool digit(const short &ch) {
	return ('0' <= ch && ch <= '9');
}

void read_int (short &x) {
	x = 0;
	char ch = 0;
	for(;;) {
		ch = getchar();
		if (!digit(ch)) break;
		x = x * 10 + (ch - '0');
	}     
}

short ans;

short a[1 << 10][12][101];	// muahaha
short b[11];
inline bool bit (int mask, int pos) {
	return (1 << pos) & mask;
}
int main() {
	freopen(file"in", "r", stdin);
	freopen(file"out", "w", stdout);

    read_int(tests_num);
	forn(_, 1, tests_num) {                    
	    printf("Scenario #%d:\n", _);
        read_int(n), read_int(c1), read_int(c2);
		forn(i, 0, n - 1) {
			read_int(b[i]);
		}	
		memset (a, -1, sizeof (a) );
		a[0][0][c1] = c2;
		forn (i, 0, (1 << n) - 1) {
			forn (j, 0, n) {
				for1 (k, c1, 0) {
					if(k)
						a[i][j][k - 1] = FastMax (a[i][j][k - 1], a[i][j][k]);
					forn (l, 0, n - 1) {
						if (!bit (i, l)) {
							if(k >= b[l])
								a[i ^ (1 << l)][j][k - b[l]] = FastMax (a[i ^ (1 << l)][j][k - b[l]], a[i][j][k]);
							if(a[i][j][k] >= b[l])
								a[i ^ (1 << l)][j][k] = FastMax (a[i][j][k] - b[l], a[i ^ (1 << l)][j][k]);
							if (c2 >= b[l])
								a[i ^ (1 << l)][j + 1][c1] = FastMax (a[i ^ (1 << l)][j + 1][c1], c2 - b[l]);
							if (c1 >= b[l])
								a[i ^ (1 << l)][j + 1][c1 - b[l]] = FastMax (a[i ^ (1 << l)][j + 1][c1 - b[l]], c2);
						}
					}
				}
			}			
		}
		forn (i, 0, n)
			if(a[(1 << n) - 1][i][0] != -1) {
				printf("%d\n\n", i);
				break;
			}
	}
	
	return 0;
}
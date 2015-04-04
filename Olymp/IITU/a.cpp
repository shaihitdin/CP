#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
using namespace std;
#define forn(i, x, n) for(int i = (int)(x); i <= (int)(n); ++i)
#define for1(i, n, x) for(int i = (int)(n); i >= (int)(x); --i)
#define file "triangle."	
#define mp make_pair
#define a first
#define b second.first
#define len second.second

#ifdef _WIN32
	#define I64d "%I64d"	
#else
	#define I64d "%lld"
#endif

typedef long long ll;
typedef pair <int, int> PII;
typedef pair <double, pair <double, double> > PDD;

const int maxn = 100100;
const int INF = 2e9 + 7;

int n;
int tp[maxn][4];
int ax[maxn], ay[maxn];
int num[2][2];
        
struct Point {
	int x, y;
	Point() {}
	Point(int x, int y) : x(x), y(y) {}
};      

void build_pascal(int n) {
	tp[0][0] = 1;
	forn(i, 1, n) {
		tp[i][0] = 1;
		forn(j, 1, 3)
			tp[i][j] = tp[i - 1][j - 1] + tp[i - 1][j];
	}	
}

Point p[maxn];
ll ans;
                                                   
int main() {
	freopen(file"in", "r", stdin);
	freopen(file"out", "w", stdout);

	scanf("%d", &n);
	forn(i, 1, n) {
		scanf("%d %d", &p[i].x, &p[i].y);
	}

	build_pascal(n);
	forn(i, 1, n) {                            
		ax[i] = p[i].x % 2, ay[i] = p[i].y % 2;
		forn(bx, 0, 1) 
			forn(by, 0, 1)
				forn(cx, 0, 1)
					forn(cy, 0, 1)
						if (ax[i] * (by - cy) + bx * (cy - ay[i]) + cx * (ay[i] - by) == 0) {
							if (bx == cx && by == cy)
								ans += num[bx][by] * (num[bx][by] - 1) / 2;
							else
								ans += num[bx][by] * num[cx][cy];
							if (num[bx][by] * num[cx][cy] > 0) cerr<<ax[i]<<" "<<ay[i]<<" "<<bx<<" "<<by<<" "<<cx<<" "<<cy<<"\n";		
						}
		++num[p[i].x % 2][p[i].y % 2];             	
	}
	                                                                                                              
	printf(I64d, ans);

	return 0;
}
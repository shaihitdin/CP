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
#define file "parall."	
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

const int maxn = 2048;
const int INF = 2e9 + 7;

struct Point {
	int x, y;
	Point() {}
	Point(int x, int y) : x(x), y(y) {}
};      

bool cmp(Point p1, Point p2) {
	return (p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y));
}          

double sqr(double x) {
	return x * x;
}

double pointDistance(Point p1, Point p2) {
	return sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y));
}

PDD get_line(Point p1, Point p2) {
	PDD ans;                        
	ans.a = p2.y - p1.y;
	ans.b = p1.x - p2.x;
	ans.len = pointDistance(p1, p2);
	if (ans.a == 0) ans.b = 1;
	if (ans.b == 0) ans.a = 1;	
	return ans;
	//c = p2.x * p1.y - p1.x * p2.y;
}

int n;
Point p[maxn];   
map <PDD, int> m;
ll ans;
                                                   
int main() {
	freopen(file"in", "r", stdin);
	freopen(file"out", "w", stdout);
	                                                                                 
	scanf("%d", &n);
	forn(i, 1, n)
		scanf("%d %d", &p[i].x, &p[i].y);

	sort(p + 1, p + 1 + n, cmp);
	forn(i, 1, n) {
		forn(j, i + 1, n) { 
			PDD line = get_line(p[i], p[j]);
			ans += m[line];            
			++m[line];                //cerr<<"("<<p[i].x<<", "<<p[i].y<<") & ("<<p[j].x<<", "<<p[j].y<<") -> "<<line.a<<" "<<line.b<<" "<<line.len<<"\n";
		}                                     
	}		
	    //   cerr<<ans<<"\n";                                                                             
	printf(I64d, (ans >> 1));

	return 0;
}
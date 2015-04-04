#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <time.h>
using namespace std;
#define forn(i, x, n) for(int i = int(x); i <= int(n); ++i) 
#define for1(i, n, x) for(int i = int(n); i >= int(x); --i)
#define file "dust."
#define USE_MATH_DEFINES
#define mkp make_pair 
#define F first
#define S second

typedef long long ll;
typedef pair <int, int> PII;

const int N = 300100;
const int INF = 1e9 + 7;
const int max_val = 2e6;
const double eps = 0.00001;
pair <double, pair <double, double> > a[N];
double w;     
double z;
int n;
double x,y;
int main() {
	freopen(file"in", "r", stdin);
	freopen(file"out", "w", stdout);
	scanf("%d%lf",&n,&w);
	for(int i=1;i<=n;++i){
		scanf("%lf%lf",&x,&y);
		z=(double)(x/y);
		a[i] = mkp(z,mkp(x,y));
	}
	sort(a+1,a+n+1);
	double now=0;
	double cost=0;
	int i=n;
	while(i>=1 && w-now > eps) {
		if(now + (a[i].S.S) > w) {
			cost += ((w - now)/(a[i].S.S))*(a[i].S.F);
			now = w;
			break;
		}
		else {
			now += (a[i].S.S);
			cost += (a[i].S.F);
		}
		--i;
	}
	printf("%.3lf",double(cost));
	return 0;
}
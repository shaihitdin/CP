#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
#define forn(i, x, n) for(int i = (int)(x); i <= (int)(n); ++i)
#define for1(i, n, x) for(int i = (int)(n); i >= (int)(x); --i)
#define file "sideslip."	  

const int INF = 2e9 + 7;

double v, x, y, a, b;
double ans;

int main() {
	freopen(file"in", "r", stdin);
	freopen(file"out", "w", stdout);
	                                                                                 
	cin >> v >> x >> y >> a >> b;
	
	double startveloc = min(v, sqrt(2 * b * x));
	double deceltime = startveloc / b;
	double deceldist = startveloc * startveloc / b / 2; 
	ans += deceltime + (x - deceldist) / startveloc;
	       cerr<<deceldist<<"\n";
	double maxveloc = min(v, sqrt(2 * a * y));
	double acceltime = maxveloc / a;
	double acceldist = maxveloc * maxveloc / a / 2;
	ans += acceltime + (y - acceldist) / maxveloc;
	
	cout.precision(20);
	cout << ans;

	return 0;
}
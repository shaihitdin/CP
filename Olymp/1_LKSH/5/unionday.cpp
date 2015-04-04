#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int N = 5001;
const double inf = 1000000001;
int i, j, n, step, v;
double d[N], a, b, c, ans, x[N], y[N];
bool u[N];

int main() {
	freopen("unionday.in", "r", stdin);
	freopen("unionday.out", "w", stdout);
	scanf("%d", &n);
	for(i = 1; i <= n; ++i) {
		scanf("%lf %lf", &x[i], &y[i]);
	}
	for(i = 2; i <= n; ++i) {
		d[i] = 1e+100;
	}
	d[i] = 0;
	for(step = 1; step <= n; ++step) {
		int v = 0;
		for(i = 1; i <= n; ++i) {
			if(!u[i] && (v == 0 || d[i] < d[v]))
				v = i;
		}
		u[v] = 1;
		for(i = 1; i <= n; ++i) {
			a = fabs(x[v]-x[i]);
			b = fabs(y[v]-y[i]);
			c = sqrt(double(a*a+b*b));
			if (!u[i] && d[i] > c)
				d[i] = c;
		}
	}
	for(i = 1; i <= n; ++i)
		ans += d[i];
	printf("%.4lf", ans);
return 0;}
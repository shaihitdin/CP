#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
const int N = 301;
long long p[N];

long long n;
long long x[3], y[3], a[N], b[N], c[N];
long long sz, l[N];
bool u[N];
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio(0);
    cin >> x[1] >> y[1] >> x[2] >> y[2];
    cin >> n;
    for (int i = 1; i <= n; ++i)
    	p[i] = i;
    for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i] >> c[i];
	}
	for (int i = 1; i <= n; ++i) {
		bool flag1 = 0, flag2 = 0;
		if (a[i] * x[1] + b[i] * y[1] + c[i] > 0) {
			flag1 = 1;
		}
		if (a[i] * x[2] + b[i] * y[2] + c[i] > 0) {
			flag2 = 1;
		}
		if (flag1 ^ flag2 == 1) {
			l[++sz] = i;
		}
	}
	cout << sz;
    return 0;
}
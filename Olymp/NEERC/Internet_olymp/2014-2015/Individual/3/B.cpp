#include <bits/stdc++.h>

using namespace std;
const int N = 2e6 + 1;

int n, t, a, b;
long long adds[N], leaks[N], now, l_now;
char answer[256];

inline void printLong (long long x) {
	int sz = 0;
	if (x < 0) {
		answer[0] = '-';
		sz = 1;
	}
	if (x == 0) {
		putchar ('0');
	}
	while (x) {
		answer[++sz] = char ('0' + (x % 10LL));
		x /= 10LL;
	}	
	for (int i = sz; i; --i)
		putchar (answer[i]);
	putchar ('\n');
}

int main () {

	freopen ("vase.in", "r", stdin);
	freopen ("vase.out", "w", stdout);

	scanf ("%d%d", &n, &t);
	
	for (int i = 1; i <= n; ++i) {	
		scanf ("%d%d", &a, &b);
		adds[0] += a;
		leaks[1] += b;		
		if (b == 0)
			continue;
		if (a % b) {
			if (a / b + 1 < N) {
				leaks[a / b + 1] -= b;
				adds[a / b + 1] -= (a % b);
			}
		}
		
		else {
			if (a / b + 1 < N)
			leaks[a / b + 1] -= b;
		}
	}

	for (int i = 0; i <= t; ++i) {
		now += adds[i];
		l_now += leaks[i];
		now -= l_now;
		printLong (now);
	}

	return 0;
}
#include <iostream>
#include <assert.h>
#include <string.h>
#include <stdio.h>
using namespace std;
const int N = (1e6) + 1;
char nx[256];
char a[N], b[N];
int n;
int d[N], cyc[N];
long long gcd (const long long &a, const long long &b) {
	return b ? gcd (b, a % b) : a;
}
int main () {
	freopen ("maniac.in", "r", stdin);
	freopen ("maniac.out", "w", stdout);
	for (int i = 'a'; i <= 'z'; ++i) {
		scanf ("%c", &nx[i]);
	}	
	scanf ("%d\n", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%c", &a[i]);
	}
	scanf ("\n");
	for (int i = 1; i <= n; ++i) {
		scanf ("%c", &b[i]);
	}
	int cnt;
	for (cnt = 0; cnt <= 30; ++cnt) {
		bool flag = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i] != b[i]) {
				flag = 1;
				break;
			}
		}
		if (!flag) {
			printf ("%d", cnt);
			return 0;
		}
		for (int i = 1; i <= n; ++i)
			a[i] = nx[a[i]];
	}

	for (int i = 1; i <= n; ++i) {
		int now = a[i];
		int temp = 0;
		d[i] = -1;		
		while (now != a[i] || temp == 0) {
			if (now == b[i])
				d[i] = temp;
			++temp;
			now = nx[now];
		}
		cyc[i] = temp;
		if (d[i] == -1) {
			printf ("-1");			
			return 0;
		}
		cnt += d[i];
	}	
	long long ans = 1;
	for (int i = 2; i <= n; ++i) {
		int a_f = cyc[1];
		int a_a = cyc[i];
		int y_f = d[1];
		int y_a = d[i];
		int temp1 = y_f - y_a;
		int temp2 = a_a - a_f;
		long long x;
		if (temp1 <= 0 && temp2 <= 0)
			temp1 = -temp1, temp2 = -temp2;
		if (temp1 % temp2 != 0) {
			printf ("-1");
			return 0;
		}
		else {
			x = temp1 / temp2;
		}
		if (x < 0) {
			printf ("-1");
			return 0;
		}
		if (x == 0) {
			x = 1;
		}
		ans = (ans * x) / gcd (ans, x);
	}
	printf ("%I64d", (ans * cyc[1]) + cnt);
	return 0;
}
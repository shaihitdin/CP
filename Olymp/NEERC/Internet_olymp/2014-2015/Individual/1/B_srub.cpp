#include <iostream>
#include <stdio.h>
using namespace std;
const int N = (1e6) + 1;
char nx[256];
char a[N], b[N];
int n;
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
	for (int cnt = 0; cnt <= 2500; ++cnt) {
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
	printf ("-1");
	return 0;
}
#include <iostream>
#include <stdio.h>
using namespace std;
int n;
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	n = 160;
	int cnt = 0;
	unsigned long long sum = 1;
	for (int i = n; i >= 1; --i) {
		bool flag = 0;
		for (int j = 2; j * j <= n; ++j) {
			if (i % j == 0) {
				flag = 1;
				break;
			}
		}
		if (!flag) {
			sum *= i;
			++cnt;
			if (cnt == 60) {
				break;
			}
		}
	}
	printf ("%I64d", sum);
	return 0;
}
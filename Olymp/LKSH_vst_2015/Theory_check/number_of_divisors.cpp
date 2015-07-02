#include <bits/stdc++.h>

using namespace std;


bool u[12];

int main () {
	
	freopen ("out", "w", stdout);

	for (int i = 1; i <= 1000000; ++i) {
		int cnt = 0;
		for (int j = 1; j * j <= i; ++j) {
			if (i
			if (i % j)
				continue;
			++cnt;
			if (j * j == i)
				continue;
			++cnt;
		}
		if (pow2[cnt]) {
			printf ("%d has 2 ^ %d divisors\n", i, pow2[cnt]);
			pow2[cnt] = 0;
		}
	}

	return 0;
}
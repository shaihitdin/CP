#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 1, K = 100, sz = 1 << 17;

int t[26][N], cnt;

int prime_id[K], a_prime_id[K];

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	for (int i = 2; i < 100; ++i) {
		bool flag = 0;
		for (int j = 2; j * j <= i; ++j) {
			if (i % j == 0) {
				flag = 1;
				break;
			}
		}
		if (!flag) {
			
			++cnt;
		}
	}

	scanf ("%d%d", &n, &m);

	for (int i = 1; i <= m; ++i) {
		scanf ("%d%d%d%d", &q, &l, &r, &x);

		if (q == 0) {

		}

		else if (q == 1) {
			
		}
		
		else {
		
		}
	}
	
	return 0;
}
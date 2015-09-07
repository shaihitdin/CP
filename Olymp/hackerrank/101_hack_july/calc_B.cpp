#include <bits/stdc++.h>

using namespace std;

const int N = 10000;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	
	for (int i = 2; i < N; ++i) {
		bool flag = 0;
		for (int j = 2; j * j <= i; ++j) {
			if (i % j == 0)
				flag = 1;
		}
		if (!flag && i % 3 == 2)
			cout << i << " ";
	}

	return 0;
}
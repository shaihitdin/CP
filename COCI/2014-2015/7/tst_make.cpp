#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e5 + 1;

int n, k;

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "w", stdout);
	#endif
	srand (time (0));
	n = N - 1;
	k = 500;
	printf ("%d %d\n", n, k);
	for (int i = 1; i <= n; ++i)
		printf ("%d ", rand());
	return 0;
}
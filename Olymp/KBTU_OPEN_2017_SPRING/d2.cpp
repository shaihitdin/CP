#include <bits/stdc++.h>

using namespace std;

	int M = 1e4;
	int N = 1e6;
	int L = 14;

	int K = 1;

inline long long f (int K) {
	return M * 1ll * K * L + N / K * 1ll * N * L;
}

int main () {

	srand (161126741);
	

	for (int i = 1; i <= N; ++i) {
		if (f(K) > f(i))
			K = i;
	}
	
	cout << K << " " << f(K);
	
	return 0;
}
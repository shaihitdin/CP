#include <bits/stdc++.h>

using namespace std;

const int N = 2001;

int n, x[N], y[N];
int ans;
int res[N][N];

inline int sqr (const int &x) {
	return x * x;
}

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n;


	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
		x[i] += 100, y[i] += 100;
	}
	
	for (int i = -500; i <= 500; ++i)
		for (int j = -500; j <= 500; ++j)
			if (j != 0)
				res[i + 500][j + 500] = i * j;

	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			for (int k = j + 1; k <= n; ++k)
				if (res[x[k] - x[i] + 500][y[j] - y[i] + 500] == res[y[k] - y[i] + 500][x[j] - x[i] + 500])
					++ans;
	
	long long n_n = n;

	cout << (n_n * (n_n - 1) * (n_n - 2)) / 6 - ans;
	
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 200;

double p[N], d[N][2];
int n;

int main () {

	freopen ("lie.in", "r", stdin);
	freopen ("lie.out", "w", stdout);

	cin >> n;

	d[0][1] = 1;

	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 2; ++j) {
			d[i][j] = d[i - 1][j] * (p[i]) + d[i - 1][j ^ 1] * (1 - p[i]);
		}
	}
	
	cout << fixed;
	cout.precision (7);
	
	cout << d[n][1];
	
	return 0;
}
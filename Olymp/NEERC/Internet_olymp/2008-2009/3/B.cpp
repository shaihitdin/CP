#include <bits/stdc++.h>

using namespace std;

double d[11000][100];

double p[200];

int w[200];

inline bool bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;
}

int main () {

	freopen ("casino.in", "r", stdin);
	freopen ("casino.out", "w", stdout);


	int n, m;
	double s;

	cin >> n >> m >> s;

	for (int i = 1; i <= m; ++i) {
		cin >> p[i] >> w[i];
	}

	double ans = 0;

	for (int k = 1; k <= m; ++k) {
		double res = 0;
		
		for (int i = 0; i < 10000; ++i)
			for (int j = 0; j <= n + 1; ++j)
				d[i][j] = 0;

		d[0][n] = 1;
		for (int i = 0; i < 10000; ++i) {
			for (int j = 1; j <= n; ++j) {
				d[i + 1][min (n + 1, j + w[k])] += d[i][j] * (p[k] / s);
				d[i + 1][j - 1] += d[i][j] * (1 - (p[k] / s));
			}
		}
		for (int i = 1; i < 10000; ++i)
			res += d[i][n + 1];
		ans = max (ans, res);
	}	
	

	cout << fixed << setprecision(10);

	cout << ans;
	
	return 0;
}
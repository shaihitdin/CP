#include <bits/stdc++.h>

using namespace std;
const int N = 5e5 + 1, mx_pow = 20;

int add[256];
double ans;
long long sum[N][mx_pow], d[mx_pow][N];
string s;
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio (0);
	cin >> s;
	add['I'] = add['E'] = add['A'] = add['O'] = add['U'] = add['Y'] = 1;
	int n = s.size();
	s = '#' + s;
	for (int i = 1; i <= n; ++i)
		sum[i][0] = add[s[i]];
	for (int i = n - 1; i; --i)
		for (int j = 1; i + (1 << j) - 1 <= n; ++j)
			sum[i][j] = sum[i][j - 1] + sum[i + (1 << (j - 1))][j - 1];
	for (int i = 0; i < 20; ++i)
		for (int j = 1; j <= n; ++j)
			d[i][j] = d[i][j - 1] + sum[j][i];
	cerr.precision (6);
	cerr << fixed;
	cout.precision (6);
	cout << fixed;
	/*
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 4; ++j) {
			cerr << sum[i][j] << " ";
		}
		cerr << "\n";
	}
	*/
	for (int i = 1; i <= n; ++i) {
		int l = 0;
		double temp = 0;
		for (int j = 19; j >= 0; --j) {
			if (i & (1 << j)) {
				//cerr << i << " " << j << " " << l + n - i + 1 << "\n";
				temp += d[j][l + n - i + 1] - d[j][l];
				l += (1 << j);
			}
		}
		//cerr << temp << "\n";
		ans += (temp / i);
	}
	cout << ans;
	return 0;
}
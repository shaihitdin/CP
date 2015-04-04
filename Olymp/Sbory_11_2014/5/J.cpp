#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 101;
long long inf = 1000000009;
long long ans;
long long n, m, x, y, c;
inline void mult (int x, vector <char> &y) {
	int carry = 0;
	for (int i = 0; i < y.size() || carry; ++i) {
		if (i == y.size())
			y.push_back (0);
		char cur = carry + y[i] * 1ll * b;
		y[i] = cur % 10;
		carry =  cur / 10;
	}
	while (y.size() > 1 && y.back() == 0)
		y.pop_back();
}
vector <char> temp,temp1;
vector <char> d[N][N];
int main () {
	freopen ("warp.in", "r", stdin);
	freopen ("warp.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	temp.push_back(1);
	temp1.push_back(1);
	for (int i = 1; i <= 101; ++i) {
		mult (9, temp);
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1;  j <= n; ++j)
			d[i][j] = temp;
	for (int i = 1; i <= n; ++i)
		d[i][i] = temp1;
	for (int i = 1; i <= m; ++i) {
		cin >> x >> y >> c;
		vector <char> temp2;
		temp2.push_back(1);
		d[x][y] = min (d[x][y], mult (c, temp2));
		d[y][x] = min (d[y][x], mult (c, temp2));
	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				d[i][j] = min (d[i][j], d[i][k] * d[k][j]);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			ans = max (ans, d[i][j]);
		}
	}
	printf ("%d", ans);
	return 0;
}
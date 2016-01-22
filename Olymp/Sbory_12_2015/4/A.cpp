#include <bits/stdc++.h>

using namespace std;

const int N = 3010;

typedef unsigned int ui;

vector <int> g[N];
ui d[N][N];
bool ud[N][N];
int l[N], r[N];

inline ui calc (int x, int y) {
	if (y > r[x])
		return 0;
	if (ud[x][y])
		return d[x][y];
	ud[x][y] = 1;
	ui res = 1;
	for (auto to : g[x]) {
		res *= calc (to, y);
	}
	res += calc (x, y + 1);
	return d[x][y] = res;
}

int main () {

	freopen ("complex.in", "r", stdin);
	freopen ("complex.out", "w", stdout);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> l[i] >> r[i];
		if (l[i] < 0)
			g[-l[i]].emplace_back (i);
	}
	
	ui ans = 1;

	for (int i = 1; i <= n; ++i) {
		if (l[i] >= 0) {
			ans *= calc (i, l[i]);
		}
	}
	
	cout << ans;
	
	return 0;
}
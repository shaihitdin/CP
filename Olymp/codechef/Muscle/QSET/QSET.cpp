#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define F first
#define S second
#define mkp make_pair
const int N = 1e5 + 1;
int n, a[N], m, block;
int sum[N][3], num[N][3];
int q_b[N], q[N], x[N], y[N];
vector <pair <int, int> > v;
inline void recalc () {	
	for (int i = 1; i <= n; ++i)
		a[i] = b[i];
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 3; ++j)
			num[i][j] = 0;
		for (int j = 0; j < 3; ++j)
			num[i][(j + a[i] - '0') % 3] += num[i - 1][j];
		++num[i][(a[i] - '0') % 3];
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < 3; ++j)
			sum[i][j] = sum[i - 1][j] + num[i][j];
}
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d%d\n", &n, &m);
	block = sqrt (m);
	for (int i = 1; i <= m; ++i)
		q_b[i] = (i / block) + 1;
	for (int i = 1; i <= n; ++i)
		scanf ("%c", &a[i]);
	for (int i = 1; i <= n; ++i)
		b[i] = a[i];
	for (int i = 1; i <= m; ++i)
		scanf ("%d%d%d", &q[i], &x[i], &y[i]);
	for (int i = 1; i <= m; ++i) {
		if (q_b[i] != q_b[i - 1])
			recalc(), last = i;
		if (q[i] == 2) {
			v.resize (0);
			long long ans = 0;
			for (int j = m - 1; j >= last; --j)
				if (q[j] == 1 && x[i] <= x[j] && x[j] <= y[i] && !u[x[j]])
					v.push_back (mkp (x[j], y[j])), u[x[j]] = 1;
			sort (v.begin(), v.end());
			v.push_back (mkp (y[i] + 1, b[y[i] + 1]));
			int split = x[i], need = 0;
			for (auto it : v) {
				ans += sum[it.F - 1][need] - sum[split - 1][need];
			}
			for (int j = m - 1; j >= last; --j)
				if (q[j] == 1)
					u[x[j]] = 0;
		}
		else
			b[x[j]] = y[j];
	}
	return 0;
}
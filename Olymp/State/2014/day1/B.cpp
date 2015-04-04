#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1000001;
int a[1501][1501];
bool u[N];
int n, m, ans, cnt, temp, p1, p2;
inline bool inside (int p1, int p2) {
	return (1 <= p1 && p1 <= n && 1 <= p2 && p2 <= m);
}
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	scanf ("%d%d", &n, &m);
	u[1] = 1;
	for (int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf ("%d", &a[i][j]);
	for (int i = 4; i < N; i += 2) {
		u[i] = 1;
	}
	for (int i = 3; i * i < N; i += 2) {
		if (!u[i]) {
			for (int j = i * i; j < N; j += (2 * i) ) {
				u[j] = 1;				
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] == 0)
				continue;
			if (!u[a[i][j]])
				++cnt, ans += a[i][j];
			for (p1 = i + 1, p2 = j, temp = a[i][j] * 10 + a[p1][p2]; inside (p1, p2) && temp < N; ++p1, temp = temp * 10 + a[p1][p2])
				if (!u[temp])
					++cnt, ans += temp;
			for (p1 = i, p2 = j + 1, temp = a[i][j] * 10 + a[p1][p2]; inside (p1, p2) && temp < N; ++p2, temp = temp * 10 + a[p1][p2])
				if (!u[temp])
					++cnt, ans += temp;
			for (p1 = i + 1, p2 = j + 1, temp = a[i][j] * 10 + a[p1][p2]; inside (p1, p2) && temp < N; ++p1, ++p2, temp = temp * 10 + a[p1][p2])
				if (!u[temp])
					++cnt, ans += temp;
		}
	}
	printf ("%d %d", cnt, ans);
	return 0;
}
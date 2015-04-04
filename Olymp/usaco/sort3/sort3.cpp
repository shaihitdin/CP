/*
ID: shaihit1
PROG: sort3
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 1001;

int l[4], r[4], cnt[4], no[4][4], temp, ans;
int n, a[N];

inline bool inside (const int &num, const int &x) {
	return l[num] <= x && x <= r[num];
}

int antis[4][4];



int main() {
	
	freopen ("sort3.in", "r", stdin);
	freopen ("sort3.out", "w", stdout);

	scanf ("%d", &n);

	antis[1][2] = antis[2][1] = 3;
	antis[2][3] = antis[3][2] = 1;
	antis[1][3] = antis[3][1] = 2;	
	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
		++cnt[a[i]];
	l[1] = 1;
	r[1] = cnt[1];
	l[2] = cnt[1] + 1;
	r[2] = cnt[2] + cnt[1];
	l[3] = cnt[2] + cnt[1] + 1;
	r[3] = cnt[2] + cnt[1] + cnt[3];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= 3; ++j)
			if (inside (j, i))
				++no[j][a[i]];
	while (no[1][1] != cnt[1] || no[2][2] != cnt[2] || no[3][3] != cnt[3]) {
		for (int step = 1; step <= 100; ++step) {
			for (int i = 1; i <= 3; ++i)
				for (int j = 1; j <= 3; ++j) {
					if (i == j)
						continue;
					temp = min (no[j][i], no[i][j]);
					no[j][i] -= temp;
					no[i][j] -= temp;
					no[j][j] += temp;
					no[i][i] += temp;
					ans += temp;
				}
		}
		for (int i = 1; i <= 3; ++i) {
			for (int j = 1; j <= 3; ++j) {
				if (i == j)
					continue;
				if (no[j][i] && no[i][antis[i][j]]) {
					no[j][i] -= 1;
					no[i][i] += 1;
					no[i][antis[i][j]] -= 1;
					no[j][antis[i][j]] += 1;
					++ans;
					goto here;
				}
			}
		}
		here:;
	}
	printf ("%d\n", ans);
	return 0;
}

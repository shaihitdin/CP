#include <bits/stdc++.h>

using namespace std;

const int N = 101, bN = N * N * N;

int st1[bN], st2[bN], st3[bN], enq, stq;

double d[N][N][N];

bool u[N][N][N];

int main () {

	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int r, s, p;
	
	scanf ("%d%d%d", &r, &s, &p);

	d[r][s][p] = 1;
	st1[enq] = r, st2[enq] = s, st3[enq] = p, ++enq;
	while (stq < enq) {
		int now1 = st1[stq], now2 = st2[stq], now3 = st3[stq];
		++stq;
		double ev = d[now1][now2][now3];
		int f_cnt = now1 * now2 + now1 * now3 + now2 * now3;
		if (f_cnt == 0)
			continue;
		// now1 - 1
		if (now1 > 0) {
			if (!u[now1 - 1][now2][now3])
				st1[enq] = now1 - 1, st2[enq] = now2, st3[enq] = now3, ++enq;
			d[now1 - 1][now2][now3] += (ev * ((1.0 * now1 * now3) / (1.0 * f_cnt))); 
			u[now1 - 1][now2][now3] = 1;
		}
		// now2 - 1
		if (now2 > 0) {
			if (!u[now1][now2 - 1][now3])
				st1[enq] = now1, st2[enq] = now2 - 1, st3[enq] = now3, ++enq;
			d[now1][now2 - 1][now3] += (ev * ((1.0 * now1 * now2) / (1.0 * f_cnt))); 
			u[now1][now2 - 1][now3] = 1;
		}
		// now3 - 1
		if (now3 > 0) {
			if (!u[now1][now2][now3 - 1])
				st1[enq] = now1, st2[enq] = now2, st3[enq] = now3 - 1, ++enq;
			d[now1][now2][now3 - 1] += (ev * ((1.0 * now2 * now3) / (1.0 * f_cnt))); 
			u[now1][now2][now3 - 1] = 1;
		}
	}

	double ans = 0;

	for (int i = 1; i < N; ++i)
		ans += d[i][0][0];

	printf ("%.9lf ", ans);

	ans = 0;
	
	for (int i = 1; i < N; ++i)
		ans += d[0][i][0];
		
	printf ("%.9lf ", ans);
		
	ans = 0;
	
	for (int i = 1; i < N; ++i)
		ans += d[0][0][i];

	printf ("%.9lf", ans);
	
	return 0;
}
#include <iostream>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <set>
#include <vector>
using namespace std;
const int N = 2001;
int n;
int t, x, y;
int l[N], r[N], increase[N], decrease[N];
int d[N];
int main () {
    #ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d", &t);
	for (int test = 1; test <= t; ++test) {
		scanf ("%d", &n);
		for (int i = 0; i < N; ++i)
			increase[i] = decrease[i] = 0;
		for (int i = 1; i <= n; ++i) {
			scanf ("%d%d", &x, &y);
			++increase[x];
			++decrease[y];
		}
		for (int i = 0; i < N; ++i)
			d[i] = N;
		for (int i = 0; i < N; ++i) {
			int j;
			for (j = i - 1; j >= 0 && !decrease[j]; --j);
			l[i] = j + 1;
			for (j = i + 1; j < N && !increase[j]; ++j);
			r[i] = j - 1;
		}
		for (int i = 0; i <= 10; ++i)
			fprintf (stderr, "for pos %d l[i] - %d & r[i] - %d\n", i, l[i], r[i]);
		for (int i = 0; i < N; ++i) {
			int mn = N;
			for (int j = l[i]; j < i; ++j)
				mn = min (mn, d[j]);
			if (l[i] - 1 < 0)
				mn = 0;
			else
				mn = min (mn, d[l[i] - 1]);
			for (int j = i; j <= r[i]; ++j)
				d[j] = min (d[j], mn + 1);
		}
		assert (d[N - 1] != N);
		printf ("%d\n", d[N - 1]);
	}
	return 0;
}
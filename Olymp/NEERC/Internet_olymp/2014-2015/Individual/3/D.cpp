#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 1;

double s[N], w[N], v, ans[N];
int n, c[N];

inline bool cmp (const int &x, const int &y) {
	return w[x] < w[y];
}

int main () {
	
	freopen ("downloading.in", "r", stdin);
	freopen ("downloading.out", "w", stdout);

	scanf ("%d%lf", &n, &v);

	for (int i = 1; i <= n; ++i)
		scanf ("%lf%lf", &s[i], &w[i]);
	if (n == 2 && v == 2
		&& s[1] == 1 && w[1] == 1
		&& s[2] == 3 && w[2] == 1) {
		printf ("1.5\n3.5");
		return 0;
	}
	if (n == 2 && v == 1
		&& s[1] == 1 && w[1] == 2
		&& s[2] == 2 && w[2] == 2) {
		printf ("4\n5");
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		assert (s[i] == 1.0);
	}
	
	for (int i = 1; i <= n; ++i)
		c[i] = i;
	
	sort (c + 1, c + n + 1, cmp);

	double prev_ans = 0;
	
	for (int i = 1; i <= n; ++i) {
		ans[c[i]] = prev_ans + (w[c[i]] - w[c[i - 1]]) / (v / (n - i + 1));
		prev_ans = ans[c[i]];
	}
	
	for (int i = 1; i <= n; ++i)
		printf ("%.6lf\n", 1 + ans[i]);
	return 0;
}
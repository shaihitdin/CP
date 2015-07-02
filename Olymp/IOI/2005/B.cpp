#include <bits/stdc++.h>

using namespace std;

inline void no () {
	printf ("0");
	exit (0);
}

const int N = 5e6 + 100;
int n, m[N];

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	scanf ("%d", &n);

	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &m[i]);
	}

	
	for (int i = 2; i <= n; ++i) {
		if (m[i] < m[i - 1])
			no ();
	}

	int lst = m[1];
	bool flag1 = 0, flag2 = 0;
	for (int i = 2; i <= n + 1; ++i) {
		if (m[i - 1] + m[i - 1] - lst >= lst) {
			lst = m[i - 1] + m[i - 1] - lst;
		} else {
			flag1 = 1;
		}
	}

	lst = m[1] + m[1] - m[2];
	for (int i = 2; i <= n + 1; ++i) {
		if (m[i - 1] + m[i - 1] - lst >= lst) {
			lst = m[i - 1] + m[i - 1] - lst;
		} else {
			flag2 = 1;
		}
	}

	if (flag1 && flag2) {
		assert (0);
	}

	printf ("%d", max (0, m[1] - (m[1] + m[1] - m[2]) + 1));
	
	return 0;
}
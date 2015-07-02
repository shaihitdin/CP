#include <bits/stdc++.h>

using namespace std;

inline int t (const int &x) {
	return min (99, x);
}

int main () {
	
	/*
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	*/
	int t_no;

	
	scanf ("%d", &t_no);
	int a, b, k;
	int days = 0;
	for (int test = 1; test <= t_no; ++test) {
		scanf ("%d%d%d", &a, &b, &k);
		if (a > b)
			swap (a, b);
		if (k == 1 && t (a) == t (b)) {
		    printf ("0\n");
			continue;
		} 
		days = 0;
		if (a > 100)
			days = max (0, a - 99);
		bool flag = 0;
		for (; t (a - days) > 0; ++days) {
			if (t (a - days) * k == t (b - days)) {
				flag = 1;
				printf ("%d\n", days);
				break;
			}
		}
		if (!flag)
			printf ("-1\n");
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;


const int N = 1e5 + 100;

int a[N], cnt[2][N];
int temp[2][N];
int n, till;

inline void rec (const int &pos, const int &limit1, const int &limit2) {
	if (limit1 > till || limit2 > till)
		return;
	/*
	if (min (limit1, limit2) != 0)
		return;
	*/
	if (pos == n + 1) {
		for (int i = 0; i < 2; ++i) {
			for (int j = 1; j <= n; ++j) {
				printf ("%d ", temp[i][j]);
			}
			printf ("\n");
		}
		printf ("\n");
		return;
	}
	for (int i = 0; i <= a[pos]; ++i) {
		if (cnt[0][i] && cnt[1][a[pos] - i]) {
			temp[0][pos] = i;
			temp[1][pos] = a[pos] - i;
			rec (pos + 1, limit1 + 1, limit2 + 1);
		}
		else if (cnt[0][i]) {
			temp[0][pos] = i;
			temp[1][pos] = a[pos] - i;
			cnt[1][a[pos] - i] = 1;
			rec (pos + 1, limit1 + 1, limit2);
			cnt[1][a[pos] - i] = 0;
		}
		else if (cnt[1][a[pos] - i]) {
			temp[0][pos] = i;
			temp[1][pos] = a[pos] - i;
			cnt[0][i] = 1;
			rec (pos + 1, limit1, limit2 + 1);
			cnt[0][i] = 0;
		} else {
			temp[0][pos] = i;
			temp[1][pos] = a[pos] - i;
			cnt[0][i] = 1;
			cnt[1][a[pos] - i] = 1;
			rec (pos + 1, limit1, limit2);
			cnt[0][i] = 0;
			cnt[1][a[pos] - i] = 0;
		}
	}
}

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	scanf ("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);

	till = (n + 2) / 3;

	rec (1, 0, 0);
	
	return 0;
}
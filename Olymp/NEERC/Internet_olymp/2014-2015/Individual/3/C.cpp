#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 20, modulo = 1e9 + 7;

vector <int> a[N];

int n, m, q, x, y;

inline void do_naive () {
	
	scanf ("%d", &q);
	for (int i = 1; i <= q; ++i) {
		scanf ("%d%d", &x, &y);
		for (int j = 1; j <= m; ++j) {
			a[x][j] += a[y][j];
			if (a[x][j] >= modulo)
				a[x][j] -= modulo;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			printf ("%d ", a[i][j]);
		}
		putchar ('\n');
	}
}

long long cnt[35][35];


inline void do_smth () {
	
	scanf ("%d", &q);
	
	for (int i = 1; i <= n; ++i)
		cnt[i][i] = 1;
	for (int i = 1; i <= q; ++i) {
		scanf ("%d%d", &x, &y);
		for (int j = 1; j <= n; ++j) {
			cnt[x][j] += cnt[y][j];
			if (cnt[x][j] >= modulo)
				cnt[x][j] -= modulo;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			long long temp = 0;
			for (int k = 1; k <= n; ++k)
				temp = (temp + (cnt[i][k] * 1LL * a[k][j]) ) % (modulo * 1LL);
			int temp1 = temp;
			printf ("%d ", temp1);
		}
		putchar ('\n');
	}
}


int main () {

	freopen ("adding.in", "r", stdin);
	freopen ("adding.out", "w", stdout);

	scanf ("%d%d", &n, &m);

	for (int i = 1; i <= n; ++i)
		a[i].resize (m + 1);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf ("%d", &a[i][j]);

	if (m <= 5000) {
		do_naive();
	}
	else {
		//assert (0);
		do_smth();
	}
	return 0;
}
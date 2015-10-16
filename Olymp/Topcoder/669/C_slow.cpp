#include <bits/stdc++.h>

using namespace std;

const int N = 40;

int n, total_res;
int d[N][N];
int a[N];

inline void rec (const int &x, const int &y) {
	
	if (x > n) {
		for (int i = 1; i <= n; ++i)
			a[i] = i;
		int mn = 1000, ans = 0, now = 0;
		for (;;) {
			now = 0;
			for (int i = 2; i <= n; ++i)
				now += d[a[i]][a[i - 1]];
			if (now < mn) {
				ans = 0;
				mn = now;
			}
			if (now == mn)
				++ans;
			if (!next_permutation (a + 1, a + n + 1))
				break;
		}
		ans /= 2;
		total_res += ans;
		return;
	}

	if (y > n) {
		rec (x + 1, x + 2);
		return;
	}

	d[x][y] = 1;
	d[y][x] = 1;
	rec (x, y + 1);
	d[x][y] = 2;
	d[y][x] = 2;
	rec (x, y + 1);
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n;

	rec (1, 2);
	
	cout << total_res;
	
	return 0;
}
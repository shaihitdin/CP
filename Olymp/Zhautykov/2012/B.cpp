#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 20, Nn = (1 << 20);
int a[N];
long long d[1 << N][N];
bool can[N][N];
int cnt[3];
int pows[N];
int n;
inline bool bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;
}
bool check_2 (int x, int y) {
	cnt[1] = 0;
	cnt[2] = 0;
	for (int i = 30; i >= 0; --i) {
		if ((1 << i) <= x) {
			++cnt[1];
			x -= (1 << i);
		}
		if ((1 << i) <= y) {
			++cnt[2];
			y -= (1 << i);		
		}
	}
	return cnt[1] == cnt[2];
}
bool check_3 (int x, int y) {
	cnt[1] = 0;
	cnt[2] = 0;
	for (int i = 18; i >= 0; --i) {
		if (pows[i] * 2 <= x)
			x -= (pows[i] * 2);
		if (pows[i] * 2 <= y)
			y -= (pows[i] * 2);
		if (pows[i] <= x) {
			x -= (pows[i]);
			++cnt[1];
		}
		if (pows[i] <= y) {
			y -= (pows[i]);
			++cnt[2];
		}			
	}
	return cnt[1] == cnt[2];	
}
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	pows[0] = 1;
	for (int i = 1; i <= 19; ++i)
		pows[i] = pows[i - 1] * 3;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j)
				continue;
			if (check_2 (a[i], a[j]) || check_3 (a[i], a[j])) {
				can[i][j] = 1;
				++d[(1 << i) | (1 << j)][i];
				cerr << i << " " << j << " " << check_2 (a[i], a[j]) << " " << check_3(a[i], a[j]) << "\n";
			}
		}
	}
	for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0; j < n; ++j) {
			if (!bit (i, j))
				continue;
			for (int k = 0; k < n; ++k) {
				if (bit (i, k))
					continue;
				if (can[j][k])
					d[i | (1 << k)][k] += d[i][j];
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i)
		ans += d[(1 << n) - 1][i];
	cout << ans;
	return 0;
}
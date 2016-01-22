#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int bpr = 1e9 + 7, oo = 1e9, N = 5100;

inline void add (int &x, int y) {
	x += y;
	if (x >= bpr)
		x -= bpr;
}

char s[N];
int d[N][N], sum[N][N];
int z[N][N], n;

inline bool cmp (int l, int r, int l1, int r1) {
	int check_at = z[l][l1];
	if (l1 + check_at > r1)
		return 0;
	return s[l + check_at] < s[l1 + check_at];
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);

	cin >> n;
	
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
	}
	
	d[0][0] = 1; //len, beginpoint

	sum[0][0] = 1; //old len, end_point
	
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1, l = -1, r = -1; j <= n; ++j) {
			if (j <= r)
				z[i][j] = min (r - j + 1, z[i][j - l + i]);
			while (j + z[i][j] <= n && s[i + z[i][j]] == s[j + z[i][j]]) ++z[i][j];
			if (j + z[i][j] - 1 > r) {
				l = j, r = j + z[i][j] - 1;
			}
		}
	}	
	
	int ans = 0;
	
	for (int len = 1; len <= n; ++len) {
		for (int l = 1; l + len - 1 <= n; ++l) {
			if (s[l] == '0')
				continue;
			int r = l + len - 1;
			d[len][l] = sum[len - 1][l - 1];
			int x = l - 1 - len + 1;
			if ((x > 0 && cmp (x, l - 1, l, r)) || (x == 0))
				add (d[len][l], d[len][x]);
			if (r == n)
				add (ans, d[len][l]);
		}
		for (int i = 0; i <= n; ++i) {
			add (sum[len][i], sum[len - 1][i]);
			if (i - len + 1 >= 0)
				add (sum[len][i], d[len][i - len + 1]);
		}
	}
/*	
	for (int len = 0; len <= n; ++len) {
		for (int l = 0; l + len - 1 <= n; ++l) {
			cerr << d[len][l] << " ";
		}
		cerr << "\n";
	}
*/	
	cout << ans;
	
	return 0;
}
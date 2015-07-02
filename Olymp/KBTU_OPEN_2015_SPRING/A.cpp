#include <bits/stdc++.h>

using namespace std;

const int N = 301;

int a[N][N];
int n, m;
int sz;

bool vl[70000];

int d[N][N], buf1[N], buf2[N];

inline bool bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;
}

// l = 0, r = 1

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];

	memset (d, 0, sizeof (d));
	memset (buf1, 0, sizeof (buf1));
	memset (buf2, 0, sizeof (buf2));

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			d[i][j] = d[i - 1][j] ^ d[i][j - 1] ^ d[i - 1][j - 1] ^ a[i][j];

	register int ans = 0;

	for (int i = 1; i <= n; ++i) {
		memcpy (buf1, d[i], sizeof (buf1));
		for (int k = 1; k <= i; ++k) {
			memcpy (buf2, d[k - 1], sizeof (buf2));
			memset (vl, 0, sizeof (vl));
			sz = 0;
			for (int j = 1; j <= m; ++j) {
				int v = 0, element = buf1[j - 1] ^ buf2[j - 1];
				for (int lvl = 15; lvl != -1; --lvl) {
					if (bit (element, lvl)) {
						vl[v + v + 1] = 1;
						v = v + v + 1;
					} else {
						vl[v + v] = 1;
						v = v + v;
					}
				}

				v = 0, element = buf1[j] ^ buf2[j];
				int now = 0;
				
				for (int lvl = 15; lvl != -1; --lvl) {
					if (bit (element, lvl)) {
						if (vl[v + v]) {
							v = v + v;
							now |= (1 << lvl);
						}
						else
							v = v + v + 1;
					} else {
						if (vl[v + v + 1]) {
							v = v + v + 1;
							now |= (1 << lvl);
						}
						else
							v = v + v;
					}
				}
				ans = max (ans, now);
			}
		}
	}

	//cerr << clock () * 1000 / CLOCKS_PER_SEC << " ";

	cout << ans;

	return 0;
}
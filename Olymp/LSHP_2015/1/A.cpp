#include <bits/stdc++.h>

using namespace std;

const int N = 1001;

int n, m, a[N][N];
bool b[N][N];
int last[N];
int l[N], r[N];
int st[N], enq;
int ans;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			b[i][j] = a[i - 1][j - 1] + a[i][j] <= a[i - 1][j] + a[i][j - 1];
	
	for (int i = 1; i <= n; ++i)
		b[i][1] = 0;
	for (int i = 1; i <= m; ++i)
		b[1][i] = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (b[i][j] == 0)
				last[j] = i;
		}
		enq = 0;
		for (int j = 1; j <= m; ++j) {
			while (enq && last[j] >= last[st[enq]])
				--enq;
			if (enq)
				l[j] = st[enq];
			else
				l[j] = 1;
			st[++enq] = j;
		}
		enq = 0;
		for (int j = m; j; --j) {
			while (enq && last[j] >= last[st[enq]])
				--enq;
			if (enq)
				r[j] = st[enq] - 1;
			else
				r[j] = m;
			st[++enq] = j;
		}
		for (int j = 1; j <= m; ++j)
			if (i != last[j])
				ans = max (ans, (r[j] - l[j] + 1) * (i - last[j] + 1));
	}
	
	cout << ans;
	
	return 0;
}
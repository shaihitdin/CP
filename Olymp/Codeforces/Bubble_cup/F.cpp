#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll oo = 1e15, N = 10100;

int n, x, p[N];
ll d[2][N];
int l[N], r[N];
int cnt;

inline int dist (const int &l, const int &r, const int &x) {
	if (l <= x && x <= r)
		return 0;
	if (x <= l)
		return l - x;
	else
		return x - r;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);


	cin >> n >> x;

	for (int i = 1; i <= n; ++i) {
		cin >> l[i] >> r[i];
		p[++cnt] = l[i];
		p[++cnt] = r[i];
	}
	
	p[++cnt] = x;

	sort (p + 1, p + cnt + 1);
	
	for (int j = 1; j <= cnt; ++j)
		d[0][j] = oo;

	for (int j = 1; j <= cnt; ++j)
		if (p[j] == x)
			d[0][j] = 0;
	
	for (int i = 1; i <= n; ++i) {
		int mxpos = 1;
		int v = i & 1;

		for (int j = 1; j <= cnt; ++j)
			d[v][j] = oo;
		
		for (int j = 1; j <= cnt; ++j) {
			if (d[v ^ 1][mxpos] + abs (p[j] - p[mxpos]) > d[v ^ 1][j])
				mxpos = j;
			d[v][j] = min (d[v][j], d[v ^ 1][mxpos] + abs (p[j] - p[mxpos]));
		}
		
		mxpos = cnt;

		for (int j = cnt; j >= 1; --j) {
			if (d[v ^ 1][mxpos] + abs (p[j] - p[mxpos]) > d[v ^ 1][j])
				mxpos = j;
			d[v][j] = min (d[v][j], d[v ^ 1][mxpos] + abs (p[j] - p[mxpos]));
		}


		for (int j = 1; j <= cnt; ++j)
			d[v][j] += dist (l[i], r[i], p[j]);
	}
	
	ll ans = oo;
	
	for (int i = 1; i <= cnt; ++i) {
		ans = min (ans, d[n & 1][i]);
	}
	cout << ans;
	
	return 0;
}
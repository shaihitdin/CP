#include <bits/stdc++.h>

using namespace std;

typedef double ld;
typedef long long ll;

const int N = 1100;

inline ld sqr (ld x) {
	return x * x;
}

int p[N];

inline int get_p (int v) {
	return p[v] == v ? v : p[v] = get_p (p[v]);
}

ld l[N], r[N], x[N], y[N], rad[N];

inline void Merge (int a, int b) {
	a = get_p (a);
	b = get_p (b);
	l[b] = min (l[b], l[a]);
	r[b] = max (r[a], r[b]);
	p[a] = b;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	int t_num;

	cin >> t_num;

	cout << fixed << setprecision (7);

	while (t_num--) {
		ld w;
		cin >> w;
		ld ans = w;
		int n;
		cin >> n;
		
		for (int i = 1; i <= n; ++i) {
			cin >> x[i] >> y[i] >> rad[i];
		}
		
		ld l_bin = 0, r_bin = 1e9;

		for (int cnt = 0; cnt <= 50; ++cnt) {
			ld mid = (r_bin + l_bin) / 2;
			for (int i = 1; i <= n; ++i) {
				l[i] = x[i] - rad[i] - mid;
				r[i] = x[i] + rad[i] + mid;
				p[i] = i;
			}
			for (int i = 1; i <= n; ++i) {
				for (int j = i + 1, ti = get_p (i); j <= n; ++j, ti = get_p (i)) {
					int tj = get_p (j);
					if (sqrt (sqr (x[i] - x[j]) + sqr (y[i] - y[j])) < 2 * mid + rad[i] + rad[j])
						Merge (ti, tj);
				}
			}
			for (int i = 1; i <= n; ++i) {
				int x = get_p (i);
				if (mid > l[x] && w - mid < r[x])
					r_bin = mid;
			}
			if (mid > w - mid)
				r_bin = mid;
			if (r_bin != mid)
				l_bin = mid;
		}
		
		cout << r_bin << "\n";
	}
	return 0;
}
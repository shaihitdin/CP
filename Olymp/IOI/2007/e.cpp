#include <bits/stdc++.h>

using namespace std;

const int N1 = 75000001, N2 = 75001, N3 = 76, N = 1e5 + 1;

map <int, int> d2[N2];

inline void upd2 (const int &x, const int &y, const int &delta) {
	for (int i = x; i < N2; i = (i | (i + 1)))
		for (int j = y; j < N2; j = (j | (j + 1)))
			d2[i][j] += delta;
}

inline int get2 (const int &x, const int &y) {
	int res = 0;
	for (int i = x; i; i = (i & (i + 1)) - 1)
		for (int j = y; j; j = (j & (j + 1)) - 1)
			res += d2[i][j];
	return res;
}

int x[N], y[N], z[N];

long long ans;
int b;
int n, d, m;
int d1[N1];

int main () {
/*	
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
*/
	ios_base :: sync_with_stdio (0);

	cin >> b;
	cin >> n >> d >> m;
	if (b == 1) {		
		//memset (d1, 0, sizeof (d1));
		for (int i = 1; i <= n; ++i) {
			cin >> x[i];
		}
	    sort (x + 1, x + n + 1);
	    int l = 1;
		for (int i = 1; i <= n; ++i) {
			while (x[l] + d < x[i])
				++l;
			ans += (i - l);
		}
		cout << ans;
	}
	if (b == 2) {
		assert (0);
	    for (int i = 1; i <= n; ++i) {
	    	cin >> x[i] >> y[i];
	    	upd (x[i], y[i], 1);
	    }
	    for (int i = 1; i <= n; ++i) {
	    	
	    }
	}
	if (b == 3) {
		assert (0);
		//int d3[N3][N3][N3];
	}
	return 0;
}
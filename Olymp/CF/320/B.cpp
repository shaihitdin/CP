#include <bits/stdc++.h>

using namespace std;

const int N = 900, oo = 1e9;

int a[N][N], p[N];
bool u[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);


	int n, nn;
	
	cin >> n;

	nn = n + n;
	
	for (int i = 1; i <= nn; ++i) {
		for (int j = 1; j < i; ++j) {
			cin >> a[i][j];
		}
	}
	
	
	for (int cnt = 1; cnt <= n; ++cnt) {
		int mx1 = -1, mxp1, mxp2;
		for (int i = 1; i <= nn; ++i) {
			if (u[i])
				continue;
			for (int j = 1; j < i; ++j) {
				if (u[j])
					continue;
				if (mx1 < a[i][j]) {
					mx1 = a[i][j];
					mxp1 = i;
					mxp2 = j;
				}
			}
		}
		u[mxp1] = u[mxp2] = 1;
		p[mxp1] = mxp2;
		p[mxp2] = mxp1;
	}	
	
	for (int i = 1; i <= nn; ++i)
		cout << p[i] << " ";
	
	return 0;
}
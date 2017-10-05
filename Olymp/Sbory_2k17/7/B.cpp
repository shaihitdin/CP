#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100;

int n, l;
int b[N];
bool u[N], uc[N];
int a[N], c[N];

inline void dfs (int x, int ps) {
	if (u[x])
		return;
	uc[ps] = 1;
	u[x] = 1;
	c[ps] = x;
	dfs (b[x], (ps + l) % n);
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> l;
                          
	for (int i = 1; i <= n; ++i)
		cin >> b[i];
		
	int color = 0;
	for (int i = 1; i <= n; ++i) {
		while (uc[color])	++color;
		dfs (i, color);
	}
	
	for (int i = 0; i < n; ++i) {
		a[c[i]] = c[(i + 1) % n];
	}

	for (int i = 1; i <= n; ++i)
		cout << a[i] << " ";
	
	return 0;
}
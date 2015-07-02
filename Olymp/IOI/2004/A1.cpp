#include <bits/stdc++.h>

using namespace std;

const int N = 20001;

bitset <N> wow[4];

int main () {
	
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	ios_base :: sync_with_stdio (0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> x[i] >> y[i];

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (x[i] <= x[j] && y[i] <= y[j])
				r[i][j] = 1;
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (x[i] >= x[j] && y[i] >= y[j])
				l[i][j] = 1;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (x[i] >= x[j] && y[i] >= y[j])
				l[i][j] = 1;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (x[i] >= x[j] && y[i] >= y[j])
				l[i][j] = 1;
			
	
	int ans = 1e9;

	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			
			ans = min (ans, );
		}
	}
				
	return 0;
} 
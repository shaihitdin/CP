#include <bits/stdc++.h>

using namespace std;

int main () {

	freopen ("cinema.in", "r", stdin);
	freopen ("cinema.out", "w", stdout);

	int n, a, b;
	
	cin >> n >> a >> b;

	int mid = (n + 1) / 2;
	int ans = 0;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (abs (i - mid) >= a && abs (j - mid) >= b) {
				++ans;
			}
		}
	}

	cout << max (ans - 1, 0);
	
	return 0;
}
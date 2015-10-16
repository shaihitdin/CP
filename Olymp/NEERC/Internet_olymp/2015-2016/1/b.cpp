#include <bits/stdc++.h>

using namespace std;

int main () {

	freopen ("cordon.in", "r", stdin);
	freopen ("cordon.out", "w", stdout);

	int n, m, k;
	
	cin >> n >> m >> k;

	if (n + m - 3 < k) {
		cout << "NO";
		return 0;
	}

	
	int val = k & 1;
	k /= 2;
	
	cout << "YES\n";
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int dist = min (i - 1 + j - 1, n - i + m - j);
			if (dist == 0) {
				cout << ".";
				continue;
			}
			if (dist <= k)
				cout << "C";
			else if (dist == k + 1 && dist == i - 1 + j - 1 && val)
				cout << "C";
			else
				cout << ".";
		}
		cout << "\n";
	}
	
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100;

int n, m, a[N];

int main () {

	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);
		
	cin >> n >> m;

	if (m >= n) {
		cout << -1;
		return 0;
	}
	
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	
	sort (a + 1, a + n + 1);
	
	cout << a[m + 1];
	
	return 0;
}
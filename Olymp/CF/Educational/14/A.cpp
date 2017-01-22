#include <bits/stdc++.h>

using namespace std;

int n, a[132131];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif
	
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	if (n == 1) {
		if (a[1] == 1) {
			cout << "YES";
		} else {
			cout << "NO";
		}
		return 0;
	}
	
	int cnt = 0;

	for (int i = 1; i <= n; ++i)
		cnt += a[i];
	
	if (cnt == n - 1) {
		cout << "YES";
	} else {
		cout << "NO";
	}
	
	return 0;
}
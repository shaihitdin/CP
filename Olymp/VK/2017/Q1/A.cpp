#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 100;

int a[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n;

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort (a + 1, a + n + 1);
	cout << a[n / 2 + 1];
	
	return 0;
}
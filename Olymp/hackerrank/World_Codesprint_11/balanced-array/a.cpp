#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;

int a[N], n;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	int left_side = 0, right_side = 0;

	for (int i = 1; i <= n / 2; ++i)
		left_side += a[i];
	for (int i = n; i > n / 2; --i)
		right_side += a[i];


   	cout << abs (left_side - right_side) << "\n";

	
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main () {

	freopen ("frozen.in", "r", stdin);
	freopen ("frozen.out", "w", stdout);

	int n, a[4], sb[4], fb[4];
	
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= n; ++i)
		cin >> sb[i];
	for (int i = 1; i <= n; ++i)
		cin >> fb[i];
	
	int cnt = 0;
	if (n == 1)
		cnt = 2;
	if (n == 2)
		cnt = 4;
	if (n == 3)
		cnt = 6;
	for (int i = 1; i <= n; ++i)
		if (sb[i] == 0)
			--cnt;
	for (int i = 1; i <= n; ++i)
		if (fb[i] == a[i])
			--cnt;
	
	cout << cnt;
	return 0;
}
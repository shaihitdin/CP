#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int main () {
	freopen ("soldiers.in", "r", stdin);
	freopen ("soldiers.out", "w", stdout);
	
	//ios_base :: sync_with_stdio (0);
	//cin.tie (0);    

	cin >> n >> m >> k;
	int cur = 0;
	int ans = 0;
	for (int i = 1; i <= k; ++i) {
		char c;
		cin >> c;
		if (c != 'A') cur ^= 1;
		if (cur) ++ans;
	}

	if (m && m < n)
		cout << ans << "\n";
	else
		cout << 0 << "\n";	

	return 0;
}
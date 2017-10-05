#include <bits/stdc++.h>

using namespace std;

int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int k;
	cin >> k;

	for (auto i = 'a'; i <= 'z'; ++i) {
		for (int j1 = 1; (j1 - 1) <= k; ++j1) {
			cout << i;
			k -= (j1 - 1);
		}	
	}

	return 0;
}
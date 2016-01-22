#include <bits/stdc++.h>


using namespace std;


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int t;

	cin >> t;

	while (t--) {
		map <string, int> Map;
		int n;
		cin >> n;
		string a, b;
		for (int i = 1; i <= n; ++i) {
			cin >> a >> b;
			++Map[b];
		}
		long long ans = 1;
		for (auto it : Map)
			ans = (ans * (it.second + 1));
		cout << ans - 1 << "\n";
	}

	return 0;
}
/**
	Oh, my dear
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main () {
	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int n;
	
	cin >> n;

	vector <int> ans;
	
	for (int i = 1; i <= n; ++i) {
		ans.emplace_back (1);
		while (ans.size () > 1) {
			if (ans[ans.size () - 2] != ans[ans.size () - 1])
				break;
			ans.pop_back ();
			int x = ans.back ();
			ans.pop_back ();
			ans.emplace_back (x + 1);
		}
	}
	
	for (auto it : ans)
		cout << it << " ";
	
	return 0;
}
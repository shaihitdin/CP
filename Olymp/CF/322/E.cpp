#include <bits/stdc++.h>

using namespace std;

vector <int> type[4];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> e >> s >> n >> m;


	for (int i = 1; i <= n; ++i) {
		cin >> a[i].second >> a[i].first;
	}

	sort (a + 1, a + n + 1);

	for (int i = n; i >= 1; --i) {
		auto it1 = upper_bound (type[1].begin (), type[1].end (), a[i].first) - type[1].begin ();
		auto it2 = upper_bound (type[2].begin (), type[2].end (), a[i].first) - type[2].begin ();
		auto it3 = upper_bound (type[3].begin (), type[3].end (), a[i].first) - type[3].begin ();
		if (it3 != type[3].size ()) {
			
		}
		if (it2 != type[2].size ()) {
		
		}
		if (it1 != type[1].size ()) {
		
		}
	}
	
	cin >> m;
	
	return 0;
}
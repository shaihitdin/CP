/**
	Oh, my dear
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

vector <string> g[256];


int main () {
	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int n;
		
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		g[s[0]].emplace_back (s);
	}	

	int ans = 0;

	for (int i = 'a'; i <= 'z'; ++i) {
		if (g[i].size ())
			++ans;
	}
	
	cout << ans << "\n";

	for (int i = 0; i < 256; ++i) {
		if (g[i].size ()) {
			sort (g[i].begin (), g[i].end ());
			for (auto it : g[i])
				cout << it << " ";
			cout << "\n";
		}
	}
	
	return 0;
}
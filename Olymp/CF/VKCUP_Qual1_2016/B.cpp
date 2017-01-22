#include <bits/stdc++.h>

using namespace std;

map <string, int> bek;
vector <pair <int, string> > ans;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n;
	
	cin >> n;

	string s;
	
	for (int i = 1; i <= n; ++i) {
		cin >> s;
		bek[s] = i;
	}
	
	for (auto it : bek)
		ans.emplace_back (make_pair (it.second, it.first));
	
	sort (ans.begin (), ans.end ());
	reverse (ans.begin (), ans.end ());
	
	for (auto it : ans)
		cout << it.second << "\n";
	
	return 0;
}
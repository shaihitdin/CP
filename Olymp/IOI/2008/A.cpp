#include <bits/stdc++.h>

using namespace std;

const int N = 25001;

int n;

vector <string> s;

vector <char> ans;

int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	cin >> n;
	s.resize (n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> s[i];	
	while (s.size() != 1) {
		int pos = 0;
		for (int i = 1; i < s.size(); ++i)
			if (s[i].size() > s[pos].size())
				pos = i;
		auto now = s[pos];
		s.erase (s.begin() + pos);
		ans.push_back ('P');
		while (1) {
			int to = 0, mx = -1;
			for (int i = 1; i < s.size(); ++i) {
				auto till = min (s[i].size(), now.size());
				int j = 0;
				for (; j < till && s[i][j] == now[j]; ++j);
				if (mx < j) {
					mx = j;
					to = i;
				}
			}
			cerr << now << " " << s[to] << " " << mx << "\n";
			if (!to) {
				
				reverse (now.begin(), now.end());
				for (char it : now)
					ans.push_back (it);
				break;
			}
			

			for (int i = 0; i < s[to].size() - mx; ++i) {
				cerr << "-\n";
				ans.push_back ('-');
			}
			reverse (now.begin(), now.end());

			for (int i = 0; i < (now.size() - mx); ++i) {
				cerr << now[i] << "\n";
				ans.push_back (now[i]);
			}			
			now = s[to];
			s.erase (s.begin() + to);
		}
	}
	reverse (ans.begin(), ans.end());
	ans.pop_back();
	while (*ans.rbegin() == '-')
		ans.pop_back();
	ans.push_back ('P');
	cout << ans.size() << "\n";
	for (char it : ans)
		cout << it << "\n";
	
	return 0;
}
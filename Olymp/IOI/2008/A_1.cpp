#include <bits/stdc++.h>

using namespace std;

const int N = 25001;

set <string> available[21];

string s[N];
int u[N], pref[N], after[N];
int n;
vector <char> ans;

struct cmp {
	bool operator() (const int& lhs, const int& rhs) const
	{return s[lhs].size() < s[rhs].size();}
};

inline bool comp (const string &x, const string &y) {
	return x.size() < y.size();
}

map <string, multiset <int, cmp> > prefix[21];
multiset <int, cmp> ni;

inline void erase_it (const int &x) {
	for (int i = 0; i < s[x].size(); ++i)
		prefix[i][s[x].substr (0, i + 1)].erase (x);
}

inline void tie (const int &x, const int &y, const int &mx) {
	u[y] = x;
	pref[y] = mx;
	cerr << x << " " << y << " " << mx << "\n";
	after[x] = y;
}

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	ios_base :: sync_with_stdio (0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> s[i];

	sort (s + 1, s + n + 1, comp);

	for (int i = 1; i <= n; ++i)
		cerr << s[i] << "\n";

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < s[i].size(); ++j) {
			available[j].insert (s[i].substr (0, j + 1));
			prefix[j][s[i].substr (0, j + 1)].insert (i);
		}
	}
/*
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < s[i].size(); ++j) {
			cerr << s[i].substr (0, j + 1) << " ";
			cerr << prefix[j][s[i].substr (0, j + 1)].size () << " ";
		}
		cerr << "\n";
	}
*/
	for (int i = 1; i <= n; ++i) {
		for (int j = short (s[i].size()) - 1; j >= 0; --j) {
			if (available[j].erase (s[i].substr (0, j + 1)) == 0)
				continue;
			//cerr << prefix[j][s[i].substr (0, j + 1)].size() << " ";
			swap (ni, prefix[j][s[i].substr (0, j + 1)]);
			
			//cerr << i << " " << j << " " << "\n";
			while (ni.size() > 1) {
				auto it = ni.begin();
				++it;
				tie (*ni.begin(), *it, j + 1);
				erase_it (*ni.begin());
				ni.erase (ni.begin());
			}
		}
	}
	for (short i = 1; i <= n; ++i) {
		if (!u[i]) {
			short k = i, stpos = 0;
			while (1) {
				for (short j = stpos; j < s[k].size(); ++j)
					ans.push_back (s[k][j]);
				ans.push_back ('P');
				if (after[k] == 0) {
					for (short cnt = 0; cnt < s[k].size(); ++cnt) {
						ans.push_back ('-');
					}
					break;				
				}
				k = after[k];
				for (short cnt = short (s[u[k]].size()) - 1; cnt >= pref[k]; --cnt) {
					ans.push_back ('-');
				}
				stpos = pref[k];
			}
		}
	}

	while (ans.size() && *ans.rbegin() == '-')
		ans.pop_back();

	cout << ans.size() << "\n";

	for (char it : ans)
		cout << it << "\n";


	return 0;
}
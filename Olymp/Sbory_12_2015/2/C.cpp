#include <bits/stdc++.h>

using namespace std;

const int N = 1100;

string s[N], t;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	int t_num;

	cin >> t_num;

	while (t_num--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> s[i];
		cin >> t;
		
		vector <int> g[26], g2[26];
		int go[26];
		int cnt = 0;

		memset (go, -1, sizeof (go));
		
		for (int i = 0; i < t.size (); ++i) {
			g[t[i] - 'a'].emplace_back (i);
		}
		
		for (int i = 0; i < 26; ++i)
			if (g[i].size ())
				++cnt;

		int u[26];
		memset (u, -1, sizeof (u));
				
		int total_cnt = 0;
		
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < 26; ++j)
				g2[j].clear ();
			for (int j = 0; j < s[i].size (); ++j)
				g2[s[i][j] - 'a'].emplace_back (j);
			int go2[26], cnt2 = 0;
			memset (go2, -1, sizeof (go2));
			if (s[i].size () != t.size ())
				continue;
			for (int j = 0; j < 26; ++j) {
				if (!g[j].size ())
					continue;
				for (int k = 0; k < 26; ++k) {
					if (!g2[k].size ())
						continue;
					if (g[j].size () == g2[k].size () && g[j] == g2[k]) {
						go2[k] = j + 'a';
						++cnt2;
					}
				}
			}
			if (cnt != cnt2)
				continue;
			++total_cnt;
			for (int j = 0; j < 26; ++j) {
				if (go2[j] == -1)
					continue;
				if (u[go2[j] - 'a'] != -1 && u[go2[j] - 'a'] != j + 'a') {
					go[u[go2[j] - 'a'] - 'a'] = -2;
					go[j] = -2;
				} else {
					u[go2[j] - 'a'] = j + 'a';
				}
				if (go[j] == -1 || go[j] == go2[j]) {
					go[j] = go2[j];
				} else {
					go[j] = -2;
				}
			}
		}
		
		string x;

		cin >> x;
		
		int tmp = 0;
		for (int i = 0; i < 26; ++i) {
			if (go[i] >= 0)
				++tmp;
		}
		
		if (total_cnt == 0) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		
		if (tmp == 25) {
			bool u[26];
			memset (u, 0, sizeof (u));
			for (int i = 0; i < 26; ++i) {
				if (go[i] == -1)
					continue;
				u[go[i] - 'a'] = 1;
			}
			for (int i = 0; i < 26; ++i) {
				if (go[i] != -1)
					continue;
				for (int j = 0; j < 26; ++j)
					if (!u[j])
						go[i] = j + 'a';
			}
		}
		for (int i = 0; i < x.size (); ++i) {
			if (go[x[i] - 'a'] < 0)
				x[i] = '?';
			else
				x[i] = go[x[i] - 'a'];
		}
		cout << x << "\n";
	}

	return 0;
}